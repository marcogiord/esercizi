//SpreadsheetCell.h
#include <string>

//using namespace std;
#ifndef _SPREADSHEETCELL_H
#define _SPREADSHEETCELL_H


class SpreadsheetCell
{
public:
	SpreadsheetCell();
	SpreadsheetCell(double initialValue);
	explicit SpreadsheetCell(const std::string& initialValue);
	SpreadsheetCell(const SpreadsheetCell &src); //copy constructor
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs); //assignemnt	
	//Operator Overloading
	const SpreadsheetCell operator+(const SpreadsheetCell& cell) const;

	//Utilities
	void setValue (double inValue);
	double getValue() const;
	
	//void setString (const string& inString);
	//string getString();


protected:
	//string doubleToString(double inValue);
	//double stringToDouble(const string& inString);

	double mValue;
	//string mString;

	mutable int mNumAccesses;//member can be changed by const method getValue
};

#endif 
