#include <iostream>
#include <vector>
#include <string>

using namespace std;

// to compile 
// g++ -std=c++11 main.cpp -o main.exe


#ifndef _DUO_H
#define _DUO_H

class duo{
	public:
		duo():first(0.0),second(0.0){};
		duo(double x, double y):first(x),second(y){};// need to add this 
		
		void set_first(double d){first=d;}
		void set_second(double d){second=d;}
		
		double get_first(){return first;}
		double get_second(){return second;}
		
	protected:// allows inheritance 
		double first, second;
	
};

class point: public duo{
	public:
		point():duo(){}; // initialize base object
		point(double x, double y=0.0):duo(x,y){};
		virtual double length(){cout << " point version of length  " << endl;return sqrt(first*first+second*second);}
}; // virtuall is pur epolimorphiism 

class point3d: public point{
	public:
		point3d():point(),z(0.0){}
		double length(){cout << " point3d version of length  " << endl;return sqrt(first*first + second*second+ z*z);}
		void set_z(double d){z=d;}
		double get_z(){return z;}
	private:
		double z;
};

#endif