#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// to compile 
// g++ -std=c++11 main.cpp -o main.exe


//  generator 
class gen {
	public:
		gen(double x_zero, double increment)
			:x(x_zero),incr(increment){}
		double operator()(){x+=incr; return x;}
	private:
		double x,incr;
};


double integrate(gen g, int n){
	vector<double> fx(n);
	generate(fx.begin(),fx.end(),g);
    return(accumulate(fx.begin(),fx.end(),0.0) /n );
}



int main(){
	
	std::cout << __cplusplus << "\n";
	
	// algorithms 
	const int n =100;
	
	gen g(0.0,1.0/n);
	
	cout<<"integration x***2"<<endl;
	cout<<integrate(g,n)<<endl; 
	
	
}