//Grid.h

#ifndef DEFINES_GRDIH
#define DEFINES_GRIDH

template <typename T, int WIDTH=10, int HEIGHT=10>
class Grid {
  public:
	// no need for constructors 
		
	// methods 
	void setElementAt(int x, int y, const T& inElemen);
	T& getElementAt(int x, int y);
	const T& getElementAt(int x, int y) const;
	
	int getHeight() const { return HEIGHT; }
    int getWidth() const { return WIDTH; }
	
	// static const
	//static const int kDefaultHeight = 10;
    //static const int kDefaultWidth = 10;
  
  protected:
    T mCells[WIDTH][HEIGHT];
    
};
#endif 

#include "GridDefinitions.h"