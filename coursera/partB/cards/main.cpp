#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include "pips.h"
#include "card.h"

using namespace std;

// to compile 
// g++ -std=c++11 main.cpp -o main.exe

template <typename ForwardIterator>
void square (ForwardIterator first, ForwardIterator last)
{
	
	for(; first!=last; first++)
		*first = (*first) * (*first);
}


int main(){
	
	 std::cout << __cplusplus << "\n";
	 std::vector<int> w;
	 
	 w.push_back(9);
	 w.push_back(11);
	 w.push_back(12);
	 
    //std::cout << 'square the vector '<< std::endl;
	
	//square(w.begin(),w.end());
	
		
	
	std::cout << "creat vector "<< std::endl;
	std::vector <card> mydeck(52);
	
	std::cout << "initialize  "<< std::endl;
	init_deck(mydeck);
	
	std::cout << "elements in deck  "<< mydeck[0]<< endl;
	
	print(mydeck);
	
	std::vector <card> myhand(5);
	
	card c(SPADE,2);
	myhand[0]=c;
    myhand[1]=c;
	myhand[2]=c;
	myhand[3]=c;
	myhand[4]=c;
	
	
	bool checkflush=is_flush(myhand);
	cout<< "is flush "<< checkflush << endl;
	
}