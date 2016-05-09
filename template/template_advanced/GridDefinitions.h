//#GridDefinitions.h
#include "iostream"
template<typename T, typename Container>
const int Grid<T>::kDefaultHeight;

template<typename T, typename Container>
const int Grid<T>::kDefaultWidth;

template<typename T, typename Container>
Grid<T, Container>::Grid(int inWidth , int inHeight): mWidth(inWidth), mHeight(inHeight)
{
	// dynamicallty allocate an array of mWidth containers 
	mCells = new Container[mWidth];
	for (int i=0; i<mWidth; i++){
		// resize each container so that it can hold mHeight containers  
		mCells[i].resize(mHeight);
	}
}

//destructor 
template<typename T, typename Container>
Grid<T, Container>::~Grid(){
	delete [] mCells;
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
