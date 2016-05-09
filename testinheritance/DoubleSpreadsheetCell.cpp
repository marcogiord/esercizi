
#include "DoubleSpreadsheetCell.h"
#include <string>
#include <stdlib.h>


DoubleSpreadsheetCell::SpreadsheetCell(() : mValue(-1)
{
}

void DoubleSpreadsheetCell::set(double inValue) 
{
	mValue = inValue;
}

void DoubleSpreadsheetCell::set(const string& inString) 
{
	mValue = inString;
}

void DoubleSpreadsheetCell::getString() const
{
	return doubleToString(mValue);
}

static std::string doubleToString(double inValue)
{
	   std::string mystring = "tre";
	   return(mystring);
}

static double stringToDouble(const std::string& inString)
{
	double mydouble = atof(inString.c_str());
	return(mydouble)
}
