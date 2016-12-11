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
// function to look for least busy factory  



int main(){
	
	 std::cout << __cplusplus << "\n";
	 std::vector<int> w;
	 
	 w.push_back(9);
	 w.push_back(11);
	 w.push_back(12);
	 
    std::cout << 'square the vector '<< std::cendl;
	
	square(w.begin(),w.end());
	 
	for(auto i : w){
	 std::cout << i << ' ';}
	
	std::cout << '\n';
	 
	pips myfirstpip(6);
	
	
}