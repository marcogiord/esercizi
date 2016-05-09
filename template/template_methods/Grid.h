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
	// templated copy constructor 
	template <typename E>
	Grid(const Grid<E>& src);
	~Grid();
	
	// assignemnt
    Grid<T>& operator=(const Grid<T>& src);	
	// templated assiignemtn
	template <typename E>
	Grid<T>& operator=(const Grid<E>& src);
	
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
  // copy from function
    void copyfrom(const Grid<T>& src);
	
	template <typename E>
	void copyFrom(const Grid<E>& src);
	
	T** mCells;
	int mWidth, mHeight;	
    
};
#endif 

#include "GridDefinitions.h"