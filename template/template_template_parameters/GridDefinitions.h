//#GridDefinitions.h
#include "iostream"

template <typename T, template <typename E, typename Allocator = allocator<E> > class Container  >
const int Grid<T, Container>::kDefaultHeight;

template <typename T, template <typename E, typename Allocator = allocator<E> > class Container  >
const int Grid<T, Container>::kDefaultWidth;


template <typename T, template <typename E, typename Allocator = allocator<E> > class Container  >
Grid<T, Container>::Grid(int inWidth , int inHeight): mWidth(inWidth), mHeight(inHeight)
{
	// dynamicallty allocate an array of mWidth containers 
	mCells = new Container<T>[mWidth];
	for (int i=0; i<mWidth; i++){
		// resize each container so that it can hold mHeight containers  
		mCells[i].resize(mHeight);
	}
}

//destructor 
template <typename T, template <typename E, typename Allocator = allocator<E> > class Container  >
Grid<T, Container>::~Grid(){
	delete [] mCells;
}

template <typename T, template <typename E, typename Allocator = allocator<E> > class Container  >
void Grid<T, Container>::copyFrom(const Grid<T, Container>& src)
{
	int i,j;
	mWidth=src.mWidth;
	mHeight=src.mHeight;
	// allocat enew 
	mCells = new Container<T>[mWidth];
	for (i=0; i<mWidth; i++){
		mCells[i].resize(mHeight);
	}
	// copy data 
	for (i=0; i<mWidth; i++){
		for (j=0; j<mHeight; j++){
			mCells[i][j]=src.mCells[i][j];
		}
	}
}

// copy constructor
	//Grid(const Grid<T>& src);
template <typename T, template <typename E, typename Allocator = allocator<E> > class Container  >
Grid<T, Container>::Grid(const Grid<T, Container>& src){
	copyFrom(src);
}

// assignemnt
template <typename T, template <typename E, typename Allocator = allocator<E> > class Container  >
Grid<T, Container>& Grid<T, Container>::operator=(const Grid<T, Container>& rhs){
	// check for self assignment 
	if(this==&rhs){
		return (*this);
	}
	// delete old memory 
	delete [] mCells;
	
	// copy from 
	copyFrom(rhs);
	
	return (*this);
}

template <typename T, template <typename E, typename Allocator = allocator<E> > class Container  >
void Grid<T, Container>::setElementAt(int x, int y, const T& inElemen){
		// check borders
		mCells[x][y]=inElemen;
	}
////
template <typename T, template <typename E, typename Allocator = allocator<E> > class Container  >
T& Grid<T, Container>::getElementAt(int x, int y){
	//check biorders
	return(mCells[x][y]);	
}

template <typename T, template <typename E, typename Allocator = allocator<E> > class Container  >
const T& Grid<T, Container>::getElementAt(int x, int y) const {
	//check biorders
	return(mCells[x][y]);	
}

