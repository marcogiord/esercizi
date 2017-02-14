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

class B{
	public:
		int i;
		//virtual void print_i() const { cout << i << " inside B " << endl; }
		virtual void print_i() const = 0;
};

class D: public B{
	public:
		void print_i() const { cout << i << " inside D " << endl; }
};




int main(){
	
	std::cout << __cplusplus << "\n";
	
	student s("Mae Pohl", 100, 4.789, fresh);
	grad_student gs("Morris Pohl", 200, 3.789, grad,ta, "Toxicology", "Toxicology methods for environment");
	
	
	//pointer to publicly derived class may be converted implicitily to pointer to its base class 
	// in general they can point to both classes (base and derived
	// (base class) pointer to (base class) reference  
	student* ps = &s; 
	std::cout << "(base class) pointer to (base class) reference  "  << "\n";
	ps->print(); // this is print Mae Pohl (base class member) 
	
		
	// (base class) pointer to (derived class) reference
	ps=&gs; 
	std::cout << "(base class) pointer to (derived class) reference"  << "\n"; 
	ps->print(); // ps now points to the grad student nter to student "Mael Pohl"
	
	// pointer of type derived class can only point to objects of the derived class
	// (derived class) pointer to (derived class) reference
	grad_student *pgs;
	pgs=&gs;	
	std::cout << "(derived class) pointer invoking (derived class) reference"  << "\n"; 
	pgs->print(); // is poitning to the derived class .. prints "Morris Pohl"
	
	
	/// virtual esercize 
	D myderived;
	//B base;
	B* ptr;
	D* ptrder;
	
    //ptr = &base;
	//ptr->print_i(); // tis print inside B 
	
	ptr = &myderived;
	ptr->print_i(); // this print inside D (if virtual) inside B (if not virtual)
	
	//ptrder = &base; this can not be done 
	//ptrder->print_i();
	
	return 0 ;
}