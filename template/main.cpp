//main.cpp

#include "GamePiece.h"
#include "GameBoard.h"
#include <iostream>

using namespace std;


int main(int argc, char ** argv)
{

	cout << "welcome to the template esercize" << endl;
	
	GamePiece mypiece;
	cout << "current name is " << mypiece.getName() <<endl;
	mypiece.setName("hoirse");
	cout << "current name is " << mypiece.getName() <<endl;
	
	GameBoard myboard(5);
	cout << "size of board is " << myboard.getHeight() << " " <<myboard.getWidth() <<endl;
	
	GamePiece temppiece;
	myboard.getPieceAt(1,1);
	cout << "piece at 1 1 is " << (myboard.getPieceAt(1,1)).getName() <<endl;
	
	myboard.setPieceAt(1,1,mypiece);
	cout << "piece at 1 1 is " << (myboard.getPieceAt(1,1)).getName() <<endl;
	
	GameBoard newboard(3,2);
	newboard=myboard;
	
	cout << "piece at 1 1 in new board is " << (newboard.getPieceAt(1,1)).getName() <<endl;
	cout << "size of board is " << newboard.getHeight() << " " <<newboard.getWidth() <<endl;
	
	
	
	return (0);
}

