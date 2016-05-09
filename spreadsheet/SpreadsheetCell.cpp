
#include "SpreadsheetCell.h"
#include <string>

SpreadsheetCell::SpreadsheetCell() : mValue(0){
}


SpreadsheetCell::SpreadsheetCell(double initialValue) : 
       mValue(initialValue)
{
 }

SpreadsheetCell::SpreadsheetCell(const std::string& initialValue){}; 
 


//SpreadsheetCell::SpreadsheetCell(const string& initialValue) : 
  //     mValue(stringToDouble(initialValue)), mString(initialValue)
	//   {
	  // }

SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell &src) : 
	   mValue(src.mValue)
	   {
	   }

SpreadsheetCell&  SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
	   {
		   if (this==&rhs) {
			   return(*this);
		   }
		   mValue=rhs.mValue;
	//	   mString=rhs.mString;
	   }

const SpreadsheetCell SpreadsheetCell::operator+(const SpreadsheetCell& cell) const{
	
	SpreadsheetCell newCell;
	newCell.setValue(mValue + cell.mValue);
	return (newCell);
}

void SpreadsheetCell::setValue(double inValue){
	
	 mValue=inValue;
	 //mString=doubleToString(inValue);
}



double SpreadsheetCell::getValue() const
{
	mNumAccesses++;	
	return mValue;
}


/*void SpreadsheetCell::setString(const string& inString)
{
	mString=inString;
	mValue=stringToDouble(inString);
	}*/

/*string SpreadsheetCell::getString(){
	return mString;
}*/	
	

