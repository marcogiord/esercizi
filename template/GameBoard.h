//GameBoard.h

#include "GamePiece.h"

#ifndef DEFINES_GAMEBOARDH
#define DEFINES_GAMEBOARDH

class GameBoard {
  public:
	// constructors 
	GameBoard(int inWidth = kDefaultWidth, int inHeight = kDefaultHeight);
    // copy constructor
	GameBoard(const GameBoard& src);
	// assignemnt
    GameBoard& operator=(const GameBoard& src);
	
	// desctructor
	~GameBoard();
	
	// methods 
	void setPieceAt(int x, int y, const GamePiece& inPiece);
	GamePiece& getPieceAt(int x, int y);
	
	int getHeight() const { return mHeight; }
    int getWidth() const { return mWidth; }
	
	// static const
	static const int kDefaultHeight = 10;
    static const int kDefaultWidth = 10;
  
  protected:
    void copyFrom(const GameBoard& src);
  	GamePiece** mCells;
    int mWidth, mHeight;		
};
#endif