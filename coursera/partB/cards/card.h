#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include "pips.h"

#ifndef _CARD_H
#define _CARD_H

using namespace std;

class card {
	public:
		card():s(suit::SPADE), v(1){}
		card(suit s, pips v): s(s),v(v){}
		friend ostream& operator<<(ostream& out, const card& c); // it is not a member function of pips (it is global function)
		suit get_suit(){return s;}
		pips get_pips(){return v;}
		
		
	private:
		suit s;
		pips v;

};

std::ostream& operator<< (std::ostream &out, const card& c){
	
	out << c.v << " " << c.s;
	return(out);
}

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

/* void print(vector<card> & deck){
	for (auto p=deck.begin();p!=deck.end();++p){
		cout<<*p;
	cout<<endl;
	}
} */

void print(vector<card> & deck){
	for (auto cardval:deck)
		cout<<cardval<<endl;
	cout<<endl;	
}

bool is_flush(vector<card> & hand){

	suit s= hand[0].get_suit();
	for (auto p=hand.begin()+1;p!=hand.end();++p){
		if(s!=p->get_suit())
			return false;
		return true;	
	}
}

bool is_straight(vector<card> & hand){
	int pips_v[5],i = 0; //initialize some temp pips
	// get the pips 
	for (auto p=hand.begin()+1;p!=hand.end();++p)
		pips_v[i++]=(p->get_pips()).get_pips();
	// sort the pips 
	sort(pips_v,pips_v+5);
	
	if(pips_v[0]!=1) // non aces (first test case where the first car dis not an ace)
		return( (pips_v[0]==pips_v[1]-1) &&  (pips_v[1]==pips_v[2]-1) && (pips_v[2]==pips_v[3]-1) && (pips_v[4]==pips_v[4]-1) );
    else 
		return ( (pips_v[0]==pips_v[1]-1) &&  (pips_v[1]==pips_v[2]-1) && (pips_v[2]==pips_v[3]-1) && (pips_v[4]==pips_v[4]-1) )
	          || ( (pips_v[1]==10) && (pips_v[2]==11) && (pips_v[3]==12) && (pips_v[4]==13) );

	
}

#endif