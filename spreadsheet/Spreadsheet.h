//Spreadsheet.h
#ifndef _SPREADSHEET_H
#define _SPREADSHEET_H

#include "SpreadsheetCell.h"

class Spreadsheet
{
public: 

	Spreadsheet (int inWidth = kMaxWidth, int inHeight = kMaxHeight);
	Spreadsheet (const Spreadsheet& src); //Copy constructor
	~Spreadsheet();//Destructor
	Spreadsheet& operator=(const Spreadsheet& rhs);//Assignement 


	void setCellAt(int x, int y, const SpreadsheetCell& cell);
	SpreadsheetCell getCellAt(int x, int y);
	void printSpreadsheet();
	int getId();       

	static const int kMaxHeight;
	static const int kMaxWidth;



protected:
	bool inRange(int val, int upper);

	int mWidth, mHeight;
	int mId;

	SpreadsheetCell **mCells;

	static int sCounter;

};

#endif 
