
#include <iostream>
#include <string>
//namespace std ;

// use of references 
void swap (int& first, int& second){
	int temp = first;
	first = second ; 
	second = temp;
}
//void separateOdddsAndEvens(const int arr[], int size, int*& odds, int& numOdds,int*& evens, int& numEvens);
void separateOdddsAndEvens(const int myarr[], int mysize, int*& myodds, int& mynumOdds,	int*& myevens, int& mynumEvens);

enum Color : unsigned int {YES=2,MAYBE=1,NO=0};

/* bool Color::operator >(const Color &a, const Color &b){
	
	if((a==YES)&(b==MAYBE)){
		return true;
	} else if((a==YES)&(b==NO)){
		return true;
	} else if ((a==MAYBE)&(b==NO)){
		return true;
	} else {
		return false;
	}
}  */


int main (int argc, char ** argv)
{

   const Color mycolor1 = YES;
   const Color mycolor2 = MAYBE;
   
   if(mycolor1 > mycolor2){
	   std::cout<<"bella zii is major "<<std::endl;
   }
   std::cout<<"bella zii"<<  2 * MAYBE << std::endl;
   
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
	
	// call swap function 
	std::cout << std::endl << std::endl;
    std::cout << "Swap function   " << std::endl;
	int xc=5,yc=6;
	std::cout << "xc and yc before swap:" << xc << " "<< yc << std::endl;
	swap(xc,yc);
	std::cout << "xc and yc after swap:" << xc << " "<< yc << std::endl;
	//swap(3,4); does not compile
	// reference from pointers 
	
	int xd=8, yd=9;
	int *xdp=&xd, *ydp=&yd;
	swap(*xdp,*ydp);
	std::cout << "*xdp and *ydp after swap:" << *xdp << " "<< *ydp << std::endl;
	
	
	// call the function
	int unisplit[10] = {1,2,3,4,5,6,7,8,9,10};
	int *odds, *evens;
	int numOdds, numEvens;
	const int dsize=10; 
	
	separateOdddsAndEvens(unisplit,dsize,odds,numOdds,evens,numEvens);
	std::cout << "Odds numbers "<< std::endl;
	for (int r=0;r<numOdds;r++)
		std::cout << odds[r] << std::endl;
	
	std::cout << "even numbers "<< std::endl;
	for (int r=0;r<numEvens;r++)
		std::cout << evens[r] << std::endl;
	
	return (0);

}


void separateOdddsAndEvens(const int myarr[], int mysize, int*& myodds, int& mynumOdds,	int*& myevens, int& mynumEvens){
	
	for (int i=0;i<mysize;i++){
		if(myarr[i] % 2 == 0 ){
			mynumEvens++;
		}
		else{
			mynumOdds++;
		}
	}
	//std::cout << "mynumEvens" << mynumEvens << " mynumOdds "<< mynumOdds << std::endl;
	
	//allocate memory for th eeven and odds 
	myodds = new int[mynumOdds];
	myevens= new int[mynumEvens];
	// current position
	int evensPos = 0, oddsPos = 0;
	
	for (int i=0;i<mysize;i++){
		if(myarr[i] % 2 == 0 ){
			myevens[evensPos++]=myarr[i];
			}
		else{
			myodds[oddsPos++]=myarr[i];
			}
	}
	
}

