#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

// to compile 
// g++ -std=c++11 main.cpp -o main.exe

class B{
	public:
		virtual void foo(int i){cout << i << " inside B " << endl;}
		virtual void foo(double j){cout << j << " inside B " << endl;}
};

class D: public B{
	public:
		virtual void foo(int i){cout << i << " inside D " << endl;}
		// here the foo function i shidden and derived from B
};
	

int main(){
	
	/// virtual esercize 
	D d;
	B b;
	B *pb=&b;
	
	b.foo(9.5);  // 9.5 inside B
	
	d.foo(9.5);  // 9.5 inside D
	pb->foo(8.7);  // 8.7 inside B  
	
	
	return 0 ;
}