
#ifndef DEFINES_GAMEBOARDH
#define DEFINES_GAMEBOARDH

template <typename T>
class GameBoard : public Grid<T>
{
	public:
		// constructors 
		GameBoard(int inWidth= Grid<T>::kDefaultWidth, int inHeight = Grid<T>::kDefaultHeight);
		// overloading == comparison operator
		bool operator==(const GameBoard<T>& nhr);
		// move from 
		void move (int xSrc, int ySrc, int xDest, int yDest);
	
};

template <typename T>
GameBoard<T>::GameBoard(int inWidth, int inHeight ){	
	
}

template <typename T>
bool GameBoard<T>::operator==(const GameBoard<T>& nhr){
	bool equal= true;
	// check if size of the two is the same 
	if( ((this->mWidth)==nhr.getWidth())&&((this->mHeight)==nhr.getHeight()) ){
		// loop over the eleemnts to see if there are different elements 
		for (int i=0; i<this->mWidth; i++){
		    for (int j=0; j<this->mHeight; j++){
				if(!((this->mCells[i][j])==(nhr.mCells[i][j]))){
					equal = false;
				}
			}
		}
	}
	else{
	   return false;
	}
	return equal;
} 


template <typename T>
void GameBoard<T>::move(int xSrc, int ySrc, int xDest, int yDest){
	this->mCells[xDest][yDest]=this->mCells[xSrc][ySrc];
	this->mCells[xSrc][ySrc]=T();
}
#endif