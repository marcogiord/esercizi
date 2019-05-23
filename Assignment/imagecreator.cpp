#include "imagecreator.h"
#include <iostream>
#include <fstream>

//ImageCreator::ImageCreator()
//{

//}

void ImageCreator::RunCreator ()
{
  this->CreateImage();
  this->DrawCircleInImage();
  this->SaveImageToFile();
}


ImageCreator::ImageCreator(const ImageProperty& property) :m_property(property)
{

}

void ImageCreator::CreateImage()
{

    // get dimensions
    ImagePropertyData props;
    m_property.GetProperties(props);

    int width = props.m_width;
    int height = props.m_height;

    // allocate buffer memory
    m_image = std::vector<unsigned char>(width * height, 0);

    // i assume the image is all zeros
//    for (int x = 0; x < width; ++x)
//        for (int y = 0; y < height; ++y)
//    {
//        m_image[y * width + x] = 0;
//    }

    //delete image;
}

void ImageCreator::DrawCircleInImage()
{

      ImagePropertyData props;
      m_property.GetProperties(props);

      for (int x = 0; x < props.m_width; ++x)
          for (int y = 0; y < props.m_height; ++y)
      {
          int dist = (x - props.m_centerX)*(x - props.m_centerX) + (y - props.m_centerY)*(y - props.m_centerY);
          if (dist < props.m_radius)
            m_image[y * props.m_width + x] = 255;
      }

}

void ImageCreator::SaveImageToFile()
{


    ImagePropertyData props;
    m_property.GetProperties(props);
    std::ofstream outfile (props.m_strNameImage.toStdString() , std::ios::out | std::ios::binary);
    // open stream
    if (outfile)
    {
      // according to format insert dimensions
      outfile << props.m_width;
      outfile << props.m_height;

      // then insert data
      for (int x = 0; x < props.m_width; ++x)
        for (int y = 0; y < props.m_height; ++y)
        {
          outfile <<  m_image.at(y * props.m_width + x);
        }
      // close stream
      outfile.close();
    }
  //delete m_image;

}


//void CheckProperties(ImageProperty & props)
//{

//}

//void ImageCreator::SetProperty(const ImageProperty& property)
//{
//    m_property = property;
//}
