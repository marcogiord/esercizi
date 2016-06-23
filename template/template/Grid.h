//Grid.h

#ifndef DEFINES_GRIDH
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

template <typename T>
const int Grid<T>::kDefaultHeight;
 
template <typename T>
const int Grid<T>::kDefaultWidth;
 
template <typename T>
Grid<T>::Grid(int inWidth, int inHeight) : 
    mWidth(inWidth), mHeight(inHeight)
 {
	 mCells = new T*[mWidth];
	for (int i=0; i<mWidth; i++) {
		 mCells[i]=new T[mHeight];}
	 
 }
 
 template <typename T>
 Grid<T>::Grid(const Grid<T>& src)
 {
	copyFrom(src);
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
 
template <typename T>
void Grid<T>::copyFrom(const Grid<T>& src) {
	
	int i,j;
	 mWidth = src.mWidth;
	 mHeight= src.mHeight;
	 
	 mCells = new T*[mWidth];
	 	 for (i=0; i<mWidth; i++) {
		 mCells[i]=new T[mHeight];
		 }
		 
	for (i=0; i<mWidth; i++){
		for (j=0; j<mHeight; j++){
			mCells[i][j]=src.mCells[i][j];
		}
	}
	
}

template <typename T>
Grid<T>& Grid<T>::operator=(const Grid<T>& rhs){
	
	//check for self assigment 
	if(this==&rhs){
		return(*this);
	}
			
	//free old memory
	 for (int i=0; i<mWidth; i++){
	 delete [] mCells[i];
	 }
	 delete[] mCells;
		
	copyFrom(rhs);
				
	return(*this);	
	
	
}

template <typename T>
void Grid<T>::setElementAt(int x, int y, const T& inElemen)
{
	mCells[x][y]=inElemen;
}


template <typename T>
T& Grid<T>::getElementAt(int x, int y)
{
	return(mCells[x][y]);
}

 
#endif