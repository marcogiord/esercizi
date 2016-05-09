#include <iostream>
#include "myclass.h"

using namespace std;
//SpreadSheet::SpreadSheet (){
//		cout << "default onbtrsuctor conbstructor"<< endl;
//};

SpreadSheet::SpreadSheet (int x){
		cout << "one argument conbstructor"<< endl;
		a=x;
};

SpreadSheet::SpreadSheet (const string& initialvalue){
		cout << "one argument string constructor"<< initialvalue <<endl;
		str=initialvalue;
};
