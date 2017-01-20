#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include "pips.h"
#include "card.h"
#include <time.h>

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
		
	std::vector <card> myhand(5);
	
	card c(SPADE,10);
	card c2(SPADE,2);
	card c3(SPADE,10);
	card c4(SPADE,10);
	card c5(SPADE,10);
	
	myhand[0]=c;
    myhand[1]=c2;
	myhand[2]=c3;
	myhand[3]=c4;
	myhand[4]=c5;
	
	print(myhand);
	
	
	cout<< "is flush "<< is_flush(myhand) << endl;
	cout<< "is straight "<< is_straight(myhand)<<endl;
	cout<< "is straight flush "<< is_straight_flush(myhand)<<endl;
	cout<< "is four of a kind "<< is_4of_akind(myhand)<<endl;
	
	
	// simulation 
	int how_many = 1000000;
	int flush_count =0 ;
	int str_count=0;
	int str_flush_count=0;
	int four_of_kind_count=0;
	cout << "Ho wmany shuffles?";
	//cin >> how_many;
	
	vector<card> deck(52);
	srand(time(0));
	
	std::cout << "initializing vector "<< std::endl;
	init_deck(deck);
	
	print(deck);
	
	std::cout << "simulation  "<< std::endl;
	
	for(int loop=0; loop < how_many; loop++){
		
		//std::cout << "shuuffling "<< loop << std::endl;
		random_shuffle(deck.begin(),deck.end());
		if(loop==0)
			print(deck);
		// create a hand 
		
		//cout << "allocating a hand" <<endl;
		vector<card> hand(5);
		int i=0;
		// pick up 5 cards from the top of the deck 
		//cout << "pick uup a hand" <<endl;
		
		for (auto p=deck.begin(); i<5 ;++p)
			hand[++i] = *p;
		
		// check how many flushes etc .. 
		if(is_flush(hand))
			flush_count++;
		
		if(is_straight(hand))
			str_count++;
		
		if(is_straight_flush(hand))
			str_flush_count++;
		
		if(is_4of_akind(hand))
			four_of_kind_count++;
		
		if(0);
	}
	
	cout<< "Flushes "<< flush_count << " out of " << how_many << " prob is "<< 100.0*double(flush_count)/double(how_many) << endl;
	cout<< "Straights  "<< str_count<< " out of " << how_many << " prob is "<< 100.0*double(str_count)/double(how_many) << endl;
	cout<< "Straights Flushes  "<< str_flush_count << " out of " << how_many << " prob is "<< 100.0*double(str_flush_count)/double(how_many) << endl;
	cout<< "4 of kind "<< four_of_kind_count << " out of " << how_many << " prob is "<< 100.0*double(four_of_kind_count)/double(how_many) << endl;
	
	
}