//Grid.h

#ifndef DEFINES_GRDIH
#define DEFINES_GRIDH

template <typename T>
class Grid {
  public:
	// constructors 
	Grid(int inWidth = kDefaultWidth, int inHeight = kDefaultHeight);
    // copy constructor
	Grid(const Grid<T>& src);
	// assignemnt
    Grid<T>& operator=(const Grid<T>& src);
	
	// desctructor
	~Grid();
	
	// methods 
	void setElementAt(int x, int y, const T& inElemen);
	T& getElementAt(int x, int y);
	
	int getHeight() const { return mHeight; }
    int getWidth() const { return mWidth; }
	
	// static const
	static const int kDefaultHeight = 10;
    static const int kDefaultWidth = 10;
  
  protected:
    void copyFrom(const Grid<T>& src);
  	T** mCells;
    int mWidth, mHeight;		
};
#endif 

#include "GridDefinitions.h"