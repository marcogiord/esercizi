


#include "Spreadsheet.h"
//#include "stdio.h"
#include <iostream>

using namespace std;

//static member 
int Spreadsheet::sCounter = 0;
const int Spreadsheet::kMaxHeight = 100;
const int Spreadsheet::kMaxWidth  = 100;

Spreadsheet::Spreadsheet(int inWidth, int inHeight) :
mWidth(inWidth), mHeight(inHeight)
{
	mId = sCounter++;
	mCells = new SpreadsheetCell* [mWidth];

	for (int i = 0 ; i < mWidth; i++) {
		mCells[i]  = new SpreadsheetCell[mHeight];
	}
}

//Copy constructor
Spreadsheet::Spreadsheet(const Spreadsheet& src)
{
	int i,j;

	mId = sCounter++;

	mWidth = src.mWidth;
	mHeight= src.mHeight;
	
	mCells = new SpreadsheetCell* [mWidth];

	for (int i = 0 ; i < mWidth; i++) {
		mCells[i]  = new SpreadsheetCell[mHeight];
	} 

    for (int i = 0 ; i < mWidth; i++){
		for (int j = 0 ; j < mWidth; j++){
			mCells[i][j]  = src.mCells[i][j];
	     }
	}
}

//Destructor
Spreadsheet::~Spreadsheet()
{
	for (int i=0; i <mWidth; i++) {
		delete [] mCells[i];
	}

	delete[] mCells;

}

//Assignement
Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs){

	int i,j;

	//Check for self assigment
	if (this == &rhs) {
		return (*this);
	}

	//free old memory
	for (int i=0; i <mWidth; i++) {
		delete [] mCells[i];
	}

	delete[] mCells;

	//Copy construct new item
	mWidth = rhs.mWidth;
	mHeight= rhs.mHeight;
	
	mCells = new SpreadsheetCell* [mWidth];

	for (int i = 0 ; i < mWidth; i++) {
		mCells[i]  = new SpreadsheetCell[mHeight];
	} 

    for (int i = 0 ; i < mWidth; i++){
		for (int j = 0 ; j < mWidth; j++){
			mCells[i][j]  = rhs.mCells[i][j];
	     }
	}



}


void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell& cell){

	if(!inRange(x,mWidth) || !inRange(y,mHeight)) {
		return;
	}
		mCells[x][y]=cell;
}

SpreadsheetCell Spreadsheet::getCellAt(int x, int y){

	SpreadsheetCell empty;

	if(!inRange(x,mWidth) || !inRange(y,mHeight)) {
		return empty;
	}
		
	return(mCells[x][y]);
}

bool Spreadsheet::inRange(int val, int upper){
	
    if(val<upper){
		return true;}
	else{
		return false;}
	
	}


void Spreadsheet::printSpreadsheet(){

	for(int i=0; i <mWidth; i++){

		std::cout<<std::endl;
		std::cout<<"Row "<<i<<" : ";
		
		for(int j=0; j <mHeight; j++){
			//printf("%d",mCells[i][j]);}
						
			std::cout<<(mCells[i][j]).getValue();
		   
		
		}
	}
}

int Spreadsheet::getId(){
	return  mId;
}
