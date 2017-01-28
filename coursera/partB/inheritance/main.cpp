#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
#include "duo.h"

using namespace std;

// to compile 
// g++ -std=c++11 main.cpp -o main.exe



int main(){
	
	std::cout << __cplusplus << "\n";
	
	point q;
	
	q.set_first(3.0);
	q.set_second(4.0);
		
	cout << q.get_first()<< " , " << q.get_second() << endl;
	cout << q.length() << endl;
		
	point3d myp;
	cout << myp.get_first()<< " , " << myp.get_second() << endl;
	cout << myp.length() << endl;
	
	//point* poi=&q;//this gives the point version of length
	point* poi=&myp;//this gives th epoint3d version 
	
	cout << poi->get_first()<< " , " << poi->get_second() << endl;
	cout << poi->length() << endl;
	
	point* poi3= new point3d();
	cout << poi3->get_first()<< " , " << poi3->get_second() << endl;
	cout << poi3->length() << endl;
	
	return 0 ;
}