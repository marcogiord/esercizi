//#GridDefinitions.h
#include "iostream"



template<typename T,int WIDTH, int HEIGHT>
void Grid<T,WIDTH,HEIGHT>::setElementAt(int x, int y, const T& inElemen)
{
		// check borders
		mCells [x][y]=inElemen;
}
////
template<typename T,int WIDTH, int HEIGHT>
T& Grid<T,WIDTH,HEIGHT>::getElementAt(int x, int y)
{
	//check biorders
	return(mCells[x][y]);	
}

template<typename T,int WIDTH, int HEIGHT>
const T& Grid<T,WIDTH,HEIGHT>::getElementAt(int x, int y) const
{
	
	return(mCells[x][y]);	
}