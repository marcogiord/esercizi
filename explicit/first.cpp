#include <iostream>
#include "myclass.h"

using namespace std;

//define class 

void dosomething(SpreadSheet g){

	int j=g.a;
	cout << "one argument onbtrsuctor conbstructor"<< j<<endl;
}

int main(int argc, char** argv)
{
	
	//SpreadSheet myspread;
	SpreadSheet mynewspread(9);
	SpreadSheet mynews("defsdfsd");
	dosomething(6);

	return 0;
}
      