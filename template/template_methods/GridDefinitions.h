//#GridDefinitions.h
#include "iostream"
using namespace std;

template<typename T>
const int Grid<T>::kDefaultHeight;

template<typename T>
const int Grid<T>::kDefaultWidth;

template<typename T>
Grid<T>::Grid(int inWidth, int inHeight): mWidth(inWidth),mHeight(inHeight)
{
	mCells = new T*[mWidth];
	for (int i=0; i<mWidth; i++){
		mCells [i]=new T[mHeight];
	}
}

template <typename T>
 Grid<T>::~Grid(){
	 
	 //free old memory
	 for (int i=0; i<mWidth; i++) 
{
		 delete [] mCells[i];
	 }
		 
	 delete[] mCells;
}

// non templitzed version
template<typename T>
Grid<T>::Grid(const Grid<T>& src)
{
	copyFrom(src);
}
// copy constructoir 
template<typename T>
template<typename E>
Grid<T>::Grid(const Grid<E>& src)
{
	copyFrom(src);
}

// 
template<typename T>
template <typename E>
Grid<T>& Grid<T>::operator=(const Grid<E>& rhs)
{
	//free old memory
	 for (int i=0; i<mWidth; i++){
	 delete [] mCells[i];
	 }
	 delete[] mCells;
		
	copyFrom(rhs);
				
	return(*this);	
}

//
template<typename T>
template <typename E>
void Grid<T>::copyFrom(const Grid<E>& src){
	
	int i,j;
	mWidth = src.getWidth();
	mHeight= src.getHeight();
	 
	 mCells = new T*[mWidth];
	 	 for (i=0; i<mWidth; i++) {
		 mCells[i]=new T[mHeight];
		 }
		 
	for (i=0; i<mWidth; i++){
		for (j=0; j<mHeight; j++){
			mCells[i][j]=src.getElementAt(i,j);
		}
	}
}



template<typename T>
void Grid<T>::setElementAt(int x, int y, const T& inElemen)
{
		// check borders
		if ((x<mWidth)&(y<mHeight)){
		  mCells [x][y]=inElemen;
		} else{
			std::cerr << "invalid grid position "<<std::endl;
		}

 
}
////
template<typename T>
T& Grid<T>::getElementAt(int x, int y)
{
	//check biorders
	if ((x<mWidth)&(y<mHeight)){
		  return(mCells[x][y]);	
		} else{
	std::cerr << "invalid grid position "<<std::endl;
		}
}

template<typename T>
const T& Grid<T>::getElementAt(int x, int y) const
{
	
	return(mCells[x][y]);	
}