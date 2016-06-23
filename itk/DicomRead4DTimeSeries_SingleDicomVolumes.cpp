
// Testing routine to read a 4D CT dataset 
// M. Giordano, TuDelft, 23.6.2016 

#include "itkImage.h"
#include "itkGDCMImageIO.h"
#include "itkGDCMSeriesFileNames.h"
#include "itkImageSeriesReader.h"
#include "itkImageFileWriter.h"
#include <itkNiftiImageIO.h>

#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>


namespace fs = boost::filesystem;

// Software Guide : EndCodeSnippet
itk::ImageIOBase::Pointer getImageIO(std::string input){
	itk::ImageIOBase::Pointer imageIO = itk::ImageIOFactory::CreateImageIO(input.c_str(), itk::ImageIOFactory::ReadMode);

	imageIO->SetFileName(input);
	imageIO->ReadImageInformation();

	return imageIO;
}

itk::ImageIOBase::IOComponentType component_type(itk::ImageIOBase::Pointer imageIO){
	return imageIO->GetComponentType();
}

itk::ImageIOBase::IOPixelType pixel_type(itk::ImageIOBase::Pointer imageIO){
	return imageIO->GetPixelType();
}

size_t num_dimensions(itk::ImageIOBase::Pointer imageIO){
	return imageIO->GetNumberOfDimensions();
}

int main(int argc, char* argv[])
{

	if (argc < 3)
	{
		std::cerr << "Usage: " << std::endl;
		std::cerr << argv[0] << " inputDicomDirectory  outputFileName  "
			<< std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "Input Dir     :" << argv[1] << std::endl;
	std::cout << "Output file   :" << argv[2] << std::endl;
	
	// check if input directory exist to avoid crash 
	fs::path data_dir(argv[1]);

	if (!fs::exists(data_dir))
	{
		std::cout << "Error: the input directory " << argv[1] << "does not exist " << std::endl;
		return EXIT_FAILURE;
	}

	
	//pixel types 
	typedef signed short    PixelType;
	// image types 
	typedef itk::Image < PixelType, 3>   Image3DType;
	typedef itk::Image < PixelType, 4 >  Image4DType;

	// define reader type 
	typedef itk::ImageSeriesReader< Image3DType > ReaderType;
	ReaderType::Pointer reader = ReaderType::New();

	// 3D and 4D Image Types	
	Image4DType::Pointer image4D = Image4DType::New();
	Image3DType::Pointer image3D = Image3DType::New();

	// GDCM type
	typedef itk::GDCMImageIO       ImageIOType;
	ImageIOType::Pointer dicomIO = ImageIOType::New();

	// set read I/O
	reader->SetImageIO(dicomIO);

	// restriction on DICOM  (acquisition time)
	const std::string entry_id = "0008|0033";

	// name generator 
	typedef itk::GDCMSeriesFileNames NamesGeneratorType;
	NamesGeneratorType::Pointer nameGenerator = NamesGeneratorType::New();
	nameGenerator->SetUseSeriesDetails(true);
	nameGenerator->AddSeriesRestriction(entry_id);
	std::cout << "Name generator " << std::endl;
	nameGenerator->SetDirectory(argv[1]);

	// Series ID
	typedef std::vector< std::string >    SeriesIdContainer;
	const SeriesIdContainer & seriesUID = nameGenerator->GetSeriesUIDs();
	SeriesIdContainer::const_iterator seriesItr = seriesUID.begin();
	SeriesIdContainer::const_iterator seriesEnd = seriesUID.end();

	// container with file names 
	typedef std::vector< std::string >   FileNamesContainer;

	// figure out how many time points there are based on number of series 
	unsigned int timepoints = 0;
	while (seriesItr != seriesEnd){
		timepoints++;
		seriesItr++;
	}
	std::cout << "Number of time points  : " << timepoints << std::endl;

	// read first image
	seriesItr = seriesUID.begin();
	std::cout << "Reading first image : " << std::endl;
	std::cout << seriesItr->c_str() << std::endl;

	std::string seriesIdentifier;
	seriesIdentifier = seriesItr->c_str();

	// generate file names 
	FileNamesContainer fileNames;
	fileNames = nameGenerator->GetFileNames(seriesIdentifier);
	FileNamesContainer::iterator fileiterator = fileNames.begin();

	// get Image info
	itk::ImageIOBase::Pointer imageIO = getImageIO(fileiterator->c_str());

	// read file 
	reader->SetFileNames(fileNames);

	try
	{
		reader->Update();
	}
	catch (itk::ExceptionObject &ex)
	{
		std::cout << ex << std::endl;
		return EXIT_FAILURE;
	}

			
	// spacing 
	const Image3DType::SpacingType& spacing3D = reader->GetOutput()->GetSpacing();
	std::cout << "Spacing 3D = " << spacing3D[0] << ", " << spacing3D[1] << ", " << spacing3D[2] << std::endl;
	// origin info 
	const Image3DType::PointType origin3D = reader->GetOutput()->GetOrigin();
	std::cout << "Origin  3D = " << origin3D[0] << ", " << origin3D[1] << ", " << origin3D[2] << std::endl;
	// get 3D size 
	const Image3DType::SizeType size3D = reader->GetOutput()->GetBufferedRegion().GetSize();

	// decleare 4D parameters 
	Image4DType::SpacingType spacing4D;
	Image4DType::PointType origin4D;
	Image4DType::SizeType size4D;

	// copy parameters from 3D
	for (int i = 0; i < 3; ++i){
		spacing4D[i] = spacing3D[i];
		origin4D[i] = origin3D[i];
		size4D[i] = size3D[i];
	}
		
	// add 4-th dimension 
	spacing4D[3] = 1;
	origin4D[3] = 0;
	size4D[3] = timepoints;

	// start 
	Image4DType::IndexType start4D;
	start4D.Fill(0);

	// set  region 
	Image4DType::RegionType region4D(start4D, size4D);

	std::cout << "Spacing 4D = " << spacing4D[0] << ", " << spacing4D[1] << ", " << spacing4D[2] << ", " << spacing4D[3] << std::endl;
	std::cout << "Size 4D = " << size4D[0] << ", " << size4D[1] << ", " << size4D[2] << ", " << size4D[3] << std::endl;

	// allocate 4D image 	
	image4D->SetRegions(region4D);
	image4D->SetSpacing(spacing4D);
	image4D->SetOrigin(origin4D);
	image4D->Allocate();

	// point again to first series ID		
	seriesItr = seriesUID.begin();

	// iterators to loop into images 
	typedef itk::ImageRegionConstIterator< Image3DType >  Iterator3D;
	typedef itk::ImageRegionIterator< Image4DType >  Iterator4D;

	// define pointer to 4d image
	Iterator4D it4(image4D, image4D->GetBufferedRegion());
	it4.GoToBegin();
		
	// Loop to read the Dicom volumes one by one   
	unsigned short int idx = 0;
	while (seriesItr != seriesEnd){

		seriesIdentifier = seriesItr->c_str();
		std::cout << "Reading series " << std::endl;
		std::cout << seriesItr->c_str() << std::endl;

		// generate file names 
		fileNames = nameGenerator->GetFileNames(seriesIdentifier);

		// read volume files 
		reader->SetFileNames(fileNames);
		
		// set image3D 
		image3D = reader->GetOutput();
		image3D->SetRegions(reader->GetOutput()->GetRequestedRegion());
		image3D->CopyInformation(reader->GetOutput());
		image3D->Allocate();
		
		std::cout << "reading image volume " << idx << std::endl << std::endl;
		try
		{
			reader->Update();
		}
		catch (itk::ExceptionObject &ex)
		{
			std::cout << ex << std::endl;
			return EXIT_FAILURE;
		}

		// point to the current image 		
		Iterator3D it3(image3D, image3D->GetBufferedRegion());
		it3.GoToBegin();

		while (!it3.IsAtEnd())
		{
			it4.Set(it3.Get());
			++it3;
			++it4;
		}

		// increment iterator
		seriesItr++; 
		idx++;
	}

	std::cout << " creating nifti file ...   " << std::endl << std::endl;
	itk::NiftiImageIO::Pointer nifti_io = itk::NiftiImageIO::New();
	nifti_io->SetPixelType(pixel_type(imageIO));

	itk::ImageFileWriter<Image4DType>::Pointer nifti_writer = itk::ImageFileWriter<Image4DType>::New();
	nifti_writer->SetFileName(argv[2]);
	nifti_writer->SetInput(image4D);
	nifti_writer->SetImageIO(nifti_io);
	nifti_writer->Update();
	
	return EXIT_SUCCESS;
}

