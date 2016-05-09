#include "Grid.h"
#include "GameBoard.h"
#include<iostream>

template <typename T>
int Find(T& value, T* arr, const int size){
	
	for (int i=0; i<size; i++){
		if(arr[i]==value){
			return i;
		}
	}
	return(-1);
}

int main(int argc, char ** argv){
    
	// small exercise on subclasses  
	GameBoard<int> chessBoard;
	chessBoard.setElementAt(1,1,3);
	chessBoard.move(0,0,1,1);
	//std::cout<<"element is "<<chessBoard.getElementAt(0,0)<<std::endl;
	
	GameBoard<int> secondchessBoard;
	secondchessBoard.setElementAt(2,2,6);
	
	// declare an array of floats 
	typedef float typeArray;
	const int sizeArray=3;
	typeArray* myp=new typeArray[sizeArray];
	myp[0]=7.8;
	myp[1]=7.8;
	myp[2]=7.9;	 
	// launch function 
	float val=7.9;
	int index_val=Find(val,myp,sizeArray);// not eit does not work if you pass a const float 
	delete [] myp;
	
	
	// declare an array of objects GameBoard 	
	GameBoard<int>* chessBoardArray=new GameBoard<int>[sizeArray];
	chessBoardArray[0]=chessBoard;
	chessBoardArray[1]=secondchessBoard;
	chessBoardArray[2]=chessBoard;
	// find the second eleemnt 
	// this need the == operator needed in the Find function ... must create the == overloading in the Grid or in the Gameboard 
	int index_chess=Find(secondchessBoard,chessBoardArray,sizeArray);
	
	// show results of finding 
	std::cout<<"element in array is "<<index_val <<std::endl;
	std::cout<<"element in chess array is "<<index_chess <<std::endl;
	
	 return(0);
}