//Grid.h

#ifndef DEFINES_GRDIH
#define DEFINES_GRIDH

template <typename T, typename Container>
class Grid {
  public:
	// constructors 
	Grid(int inWidth = kDefaultWidth, int inHeight = kDefaultHeight);
    // copy constructor
	Grid(const Grid<T, Container>& src);
	// desctructor
	~Grid();
	// assignemnt
    Grid<T, Container>& operator=(const Grid<T, Container>& src);
	
	// methods 
	void setElementAt(int x, int y, const T& inElemen);
	T& getElementAt(int x, int y);
	const T& getElementAt(int x, int y) const;
	
	int getHeight() const { return mHeight; }
    int getWidth() const { return mWidth; }
	
	// static const
	static const int kDefaultHeight = 10;
    static const int kDefaultWidth = 10;
  
  protected:
    void copyFrom(const Grid<T, Container>& src);
  	Container* mCells;
    int mWidth, mHeight;		
};
#endif 

#include "GridDefinitions.h"