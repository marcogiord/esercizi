//SpreadsheetCell.h
#include <string>

//using namespace std;
#ifndef _SPREADSHEETCELL_H
#define _SPREADSHEETCELL_H


class SpreadsheetCell
{
public:
	SpreadsheetCell();

	virtual~SpreadsheetCell();
	
	//Utilities
	
	virtual void set (const std::string& inString);
	virtual std::string getString ();
	
	
/*protected:
	static std::string doubleToString(double inValue);
	static double stringToDouble(const std::string& inString);

	double mValue;
	std::string mString;*/
		
};

#endif 
