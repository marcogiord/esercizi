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
		cad(suit s, pips v): s(s),v(v){}
		friend ostream& operator<<(ostream& out, const card& c); // it is not a member function of pips (it is global function)
		suit get_suit(){return s;}
		pips get_pips(){return v;}
		
		
	private:
		suit s;
		pips v;

};

ostream& operator<<(ostream& out, const card& c){
	
	cout<< c.s << c.s << cendl;
}

#endif