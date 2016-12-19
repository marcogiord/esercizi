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

void init_deck(vector <card> & d){
	std::cout << "initializing vector "<< std::endl;
	for(int i=1; i<14; ++i){
		card c(suit::SPADE,i); 
		d[i-1]=c;
	}
	for(int i=1; i<14; ++i){
		card c(suit::HEART,i); 
		d[i+12]=c;
	}
	for(int i=1; i<14; ++i){
		card c(suit::DIAMOND,i); 
		d[i+25]=c;
	}
	for(int i=1; i<14; ++i){
		card c(suit::CLUB,i); 
		d[i+38]=c;
	}
}

void print(vector<card> & deck){
	for (auto p=deck.begiin();p!=deck.end();++p){
		cout<<*p;
	}
	
	
}


int main(){
	
	 std::cout << __cplusplus << "\n";
	 std::vector<int> w;
	 
	 w.push_back(9);
	 w.push_back(11);
	 w.push_back(12);
	 
    //std::cout << 'square the vector '<< std::endl;
	
	//square(w.begin(),w.end());
	 
		
	std::cout << "creat epips  "<< std::endl;
	 
	pips myfirstpip(6);
	std::cout << "creat vector "<< std::endl;
	std::vector <card> mydeck(52);
	std::cout << "initialize  "<< std::endl;
	init_deck(mydeck);
	std::cout << "elements "<< mydeck[0].get_pips() << endl;
	
}