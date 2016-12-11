#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>

#ifndef _PIPS_H
#define _PIPS_H


using namespace std;

enum class suit: short {SPADE,HEART,DIAMOND,CLUB};

class pips{
	public:
		pips(int val):v(val){assert(v>0 && v<14);}
		friend ostream& operator<<(ostream& out, const pips& p); // it is not a member function of pips (it is global function)
																// but it can access the members of pips 
		int get_pips(){return v;}
	private:
		int v;
};

 #endif