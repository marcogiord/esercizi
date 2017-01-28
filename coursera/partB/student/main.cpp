#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "student.h"

using namespace std;

// to compile 
// g++ -std=c++11 main.cpp -o main.exe



int main(){
	
	std::cout << __cplusplus << "\n";
	
	grad_student gs("Morris Pohl",200,3.789,senior,
					ta,"Toxicology","Toxicology methods for environment");
	
	
	return 0 ;
}