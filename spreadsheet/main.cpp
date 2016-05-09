#include "Spreadsheet.h"
#include <iostream>
#include <string>
//namespace std ;

/*void printSpreadsheet(Spreadsheet s){
	for(int i=0; i <s.mWidth; i++)
		(int j=0; j <s.mHeight; j++)
		cout <<"element "<< i << j << s[i][j] <<endl;
}*/

int main (int argc, char ** argv)
{

	double temp;
	int tempint;
	//SpreadsheetCell tempCell(3.0);


	Spreadsheet s1(4,3);std::cout << "temp id s1 is" << s1.getId() <<std::endl;
	Spreadsheet s2(3,3);std::cout << "temp id s2 is" << s2.getId() <<std::endl;

	(s1.getCellAt(1,1)).setValue(3.0);
	
	s1.printSpreadsheet();	
	std::cout << std::endl;
	s2.printSpreadsheet();


	// exercise on overloading //
	SpreadsheetCell myCell(4), anotherCell(2), aThirdCell;
	std::string str = "hello";
	aThirdCell=myCell + str;

	temp=aThirdCell.getValue();
	
	//std::cout <<std::endl;
	std::cout << "temp is" << temp <<std::endl;
	

	/* exercise copy constructor*/
	//s1.setCellAt(1,1,tempCell);

	//tempint=s2.getId();
	//std::cout << "temp id is" << tempint <<std::endl;

	//play with copy cistructor
	
	//temp=(s2.getCellAt(1,1)).getValue();
	//std::cout << "temp is" << temp <<std::endl;

	//s1.setCellAt(2,2,tempCell);
	//s1.printSpreadsheet();	s2.printSpreadsheet();

	return (0);

}



