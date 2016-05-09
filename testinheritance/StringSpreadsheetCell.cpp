
#include "StringSpreadsheetCell.h"
#include <string>



StringSpreadsheetCell::StringSpreadsheetCell() : mValue("#NOVALUE")
{
}

void StringSpreadsheetCell::set(const string& inString) 
{
	mValue = inString;
}


void StringSpreadsheetCell::getString() const
{
	return mValue;
}

