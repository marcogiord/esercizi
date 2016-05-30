//GridChar.h
#include "Grid.h"

#ifndef DEFINES_GRDICHARH
#define DEFINES_GRIDCHARH

#include <cstdlib>
#include <cstring>
using namespace std;


template <>
class Grid <char*>{
  public:
	// constructors 
	Grid(int inWidth = kDefaultWidth, int inHeight = kDefaultHeight);
    // copy constructor
	Grid(const Grid<char*>& src);
	// desctructor
	~Grid();
	
	// assignemnt
    Grid<char*>& operator=(const Grid<char*>& src);
		
	// methods 
	void setElementAt(int x, int y, const char* inElemen);
	char* getElementAt(int x, int y);
	
	int getHeight() const { return mHeight; }
    int getWidth() const { return mWidth; }
	
	// static const
	static const int kDefaultHeight = 10;
    static const int kDefaultWidth = 10;
  
  protected:
    void copyFrom(const Grid<char* >& src);
  	char*** mCells;
    int mWidth, mHeight;
};


const int Grid<char*>::kDefaultHeight;
const int Grid<char*>::kDefaultWidth;
 

Grid<char*>::Grid(int inWidth, int inHeight) : 
    mWidth(inWidth), mHeight(inHeight)
 {
	mCells = new char**[mWidth];
	for (int i=0; i<mWidth; i++){
		 mCells[i]=new char*[mHeight];
		 for (int j=0; j<mWidth; j++){
			mCells[i][j] = NULL;
		}
	}
}
 
 
 Grid<char*>::Grid(const Grid<char*>& src)
 {
	copyFrom(src);
 }
 
 
 Grid<char*>::~Grid(){	 
	 //free old memory
	 for (int i=0; i<mWidth; i++) {
		 for (int j=0; j<mWidth; j++){
				 delete [] mCells[i][j]; 
		 }
		 delete [] mCells[i];
	 }
	 delete[] mCells;
}
 

void Grid<char*>::copyFrom(const Grid<char*>& src) {
	
	int i,j;
	mWidth = src.mWidth;
	mHeight= src.mHeight;
	 
	 mCells = new char**[mWidth];
	 	 for (i=0; i<mWidth; i++) {
		 mCells[i]=new char*[mHeight];
		 }
		 
	for (i=0; i<mWidth; i++){
		for (j=0; j<mHeight; j++){
			if(src.mCells[i][j]==NULL){
				mCells[i][j]==NULL;
			}
			else{
				mCells[i][j]=new char[strlen(src.mCells[i][j])+1];
				strcpy(mCells[i][j],src.mCells[i][j]);				
			}
		}
	}
	
}

Grid<char*>& Grid<char*>::operator=(const Grid<char*>& rhs){
	
	//check for self assigment 
	if(this==&rhs){
		return(*this);
	}
			
	//free old memory
	 for (int i=0; i<mWidth; i++) {
		 for (int j=0; j<mWidth; j++){
				 delete [] mCells[i][j]; 
		 }
		 delete [] mCells[i];
	 }
	 delete[] mCells;
		
	copyFrom(rhs);
				
	return(*this);
	
}

void Grid<char*>::setElementAt(int x, int y, const char* inElem)
{
	delete [] mCells[x][y];
	if(inElem==NULL){
		mCells[x][y]==NULL;
	}
	else{
		mCells[x][y]=new char[strlen(inElem)+1];
		strcpy(mCells[x][y],inElem);
	}
			
}


char* Grid<char*>::getElementAt(int x, int y)
{
	if(mCells[x][y]==NULL){
	  return(NULL);
	}
	char *ret=new char[strlen(mCells[x][y])+1];
	strcpy(ret,mCells[x][y]);
	
	return (ret);
}

 
#endif