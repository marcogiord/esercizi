//#GridDefinitions.h
#include "iostream"
template<typename T>
const int Grid<T>::kDefaultHeight;

template<typename T>
const int Grid<T>::kDefaultWidth;

template<typename T>
Grid<T>::Grid(int inWidth , int inHeight): mWidth(inWidth),mHeight(inHeight)
{
	mCells = new T*[mWidth];
	for (int i=0; i<mWidth; i++){
		mCells [i]=new T[mHeight];
	}
}

//destructor 
template<typename T>
Grid<T>::~Grid(){
	delete mCells;
}

// copy constructor
	//Grid(const Grid<T>& src);
template<typename T>
template<typename E>
Grid<T>::Grid(const Grid<E>& src){
	copyFrom(src);
}

// assignemnt
template<typename T>
template<typename E>
Grid<T>& Grid<T>::operator=(const Grid<E>& rhs){
	if(this==&rhs){
		return (*this);
	}
	// delete memory 
	for (int i=0; i<mWidth; i++){
		delete [] mCells[i];
	}
	delete [] mCells;
	// copy from 
	copyFrom(rhs);
	return (*this);
}

template<typename T>
template<typename E>
void Grid<T>::copyFrom(const Grid<E>& src)
{
	int i,j;
	mWidth=src.getWidth();
	mHeight=src.getHeight();
	// allocat enew 
	mCells = new T*[mWidth];
	for (i=0; i<mWidth; i++){
		mCells [i]=new T[mHeight];
	}
	// copy data 
	for (i=0; i<mWidth; i++){
		for (j=0; j<mHeight; j++){
		mCells [i][j]=src.getElementAt(i,j);			
		}
	}
	
}
template<typename T>
void Grid<T>::setElementAt(int x, int y, const T& inElemen){
		// check borders
		mCells [x][y]=inElemen;
	}
////
template<typename T>
T& Grid<T>::getElementAt(int x, int y){
	//check biorders
	return(mCells [x][y]);	
}
