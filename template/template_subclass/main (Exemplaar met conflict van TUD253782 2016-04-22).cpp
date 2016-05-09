#include "Grid.h"
#include "GameBoard.h"
#include<iostream>

template <typename T>
int Find(T& value, T* arr, int size){
	
	for (int i=0; i<size; i++){
		if(arr[i]==value){
			return i;
		}
	}
	return(-1);
}

int main(int argc, char ** argv){

	GameBoard<int> chessBoard;
	 float myp[10];
	 myp[0]=7.8;
	 myp[1]=7.8;
	 myp[2]=7.9;
	float* poi;
	poi=&myp[0];
	poi[2]=5.6;
	
	chessBoard.setElementAt(1,1,3);
	chessBoard.move(0,0,1,1);
	
	float val=7.9;
	int found=Find(val,poi,3);
	
	std::cout<<"element is "<<chessBoard.getElementAt(0,0)<<std::endl;
	std::cout<<"element is "<<found <<std::endl;
	
	 return(0);
}