//GamePiece.cpp
#include "GamePiece.h"
#include <string>

GamePiece::GamePiece(){
	name="unknown";	
};

void GamePiece::setName(string inString){
	name=inString;
};

string GamePiece::getName(){
	return name;
	};
