#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <assert.h> 

#ifndef _PIPS_H
#define _PIPS_H


using namespace std;

enum suit {SPADE,HEART,DIAMOND,CLUB};

std::ostream& operator<<(std::ostream & os, const suit & s)
{
  switch (s) {
  case SPADE:
      os << "Spade";
      break;
  case HEART:
      os << "Heart";
      break;
  case DIAMOND:
      os << "Diamond";
	  break;
  case CLUB:
      os << "Club"  ;
	  break;
  }
  return os;
}


class pips{
	public:
		pips(int val):v(val){assert(v>0 && v<14);}
		friend ostream& operator<<(ostream& out, const pips& p); // it is not a member function of pips (it is global function)
																// but it can access the members of pips 
		int get_pips(){return v;}
	private:
		int v;
};

ostream& operator<<(ostream& out, const pips& p){
	
	out << p.v;
	return out;
}

 #endif