//DoubleSpreadsheetCell.h
#include <string>

//using namespace std;
#ifndef _DOUBLESPREADSHEETCELL_H
#define _DOUBLESPREADSHEETCELL_H


class DoubleSpreadsheetCell : SpreadsheetCell
{
public:
	DoubleSpreadsheetCell();

	DoubleSpreadsheetCell(double initialValue);
	
	//Utilities
	virtual void set (double inDouble);
	virtual void set (const std::string& inString);
	virtual std::string getString ();
	
	
protected:
	static std::string doubleToString(double inValue);
	static double stringToDouble(const std::string& inString);

	double mValue;
	std::string mString;
		
};

#endif 
