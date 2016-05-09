//StringSpreadsheetCell.h
#include <string>

//using namespace std;
#ifndef _STRINGSPREADSHEETCELL_H
#define _STRINGSPREADSHEETCELL_H

class StringSpreadsheetCell : public SpreadsheetCell 
{
public:
	StringSpreadsheetCell();

	//Overidding
	virtual void set (const std::string& inString);
    virtual std::string getString () const;

protected:
	std::string mValue;
};

#endif 



