
#include <iostream>
#include <string>
//namespace std ;



int main (int argc, char ** argv)
{

	int x =5;
	//int& xref; // DONT COMPILE, MUST BE INIIALIZED
	int& xref = x; //(the value of x and xref are the same )
    xref = 10;
	//int& unnamedref = 6; // DONT COMPILE, can not initialize reference to unamed value
	const int& unnamedref = 6;
	// Print values
	std::cout << "x: " << x << std::endl;
	std::cout << "xref: " << xref << std::endl;
	std::cout << "unnamedref: " << unnamedref  << std::endl;
	
	// you can no change the variable to which the references points  
	int y= 4;
	xref = y ; 
	std::cout << "y: " << y << std::endl;
	std::cout << "xref (after (xref = y) is assigned to it: " << xref << std::endl;
	y = 8 ; xref = 9; 
	std::cout << "xref (after (y = 8) is assigned to it: " << xref << std::endl;
	x = 7;
	std::cout << "xref (after (x= 7) is assigned to it: " << xref << std::endl;
	//xref = &y; !!!!!!does not compile (reference are not pointers, or not reference to pinters )
	int& yref = y; 
	xref = yref  ;
	std::cout << "xref (after xref = yref ) is assigned to it: " << xref << std::endl;
	y = 9; std::cout << "y: " << y << std::endl;
	std::cout << "xref y = 9(after xref = yref and change y to 9) is assigned to it: " << xref << std::endl;
	
	
	// ########References to pointers ###########
	std::cout << std::endl << std::endl;	
	std::cout << "Reference to pointers  " << std::endl;
	int* ptr;
	int*& ptrRef = ptr; // assign the reference to a pointer (REFERENCE TO POINTER)
	ptrRef = new int;
	*ptrRef = 10; 
	std::cout << "int* ptr .. int*& ptrRef = ptr ... *ptrRef = 10" << std::endl;
	std::cout << "ptrRef:  " << *ptrRef << " ptr: " << *ptr << std::endl;
	
	// ########Pointer to reference###########
	std::cout << std::endl << std::endl;
	std::cout << "Pointer to reference  " << std::endl;
	//int x =5;
	//int& xref = x; //(the value of x and xref are the same )
	int* xPtr = &xref;
	*xPtr = 100; 
	std::cout << "int* xPtr = &xref  ... *xPtr = 100  " << std::endl;
	std::cout << "xref:  " << xref << std::endl;
	std::cout << "xPtr:  " << *xPtr << std::endl;
	
	
	
	
	return (0);

}



