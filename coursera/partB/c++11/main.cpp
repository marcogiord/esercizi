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

template <class T, int n>
class my_container {
	public:
	// default constructor
		my_container(){
			a = new T[n];
			cout << "default constructor"  << endl;
			}; 
		
	// one arg constructor - conversion (explicit is to suppress automati conversion from one type to another )
		explicit my_container(T* b):my_container(){     
			for(int i; i<n; ++i)
				a[i]=b[i];
			cout << "one arg constructor"  << endl;
		};
	// copy  arg constructor - conversion
		my_container(const my_container &b):my_container(){ 
			for(int i; i<n ; ++i)
				a[i]=b.a[i];
			cout << "copy constructor"  << endl;
		};
	
		
		/*my_container& my_container::operator=(my_container&& b)noexcept{
			a = b.a;
			b.a=nullptr;
			return(*this);
		};*/
		
		T& operator[](int x){
			cout << "subscipt operato"  << endl;
			
			if(x<0){
				throw out_of_range("");
			}
			
            return(a[x]);			
		};
				
		void swap(my_container& b){
				my_container temp = move(b);
				b = move(*this);
				*this = move(temp);
			};

 
		~my_container(){delete[] a;};
	private:
		T* a;
};





int main(){
	
	cout << "first construction "  << endl;
	my_container<int,5> data;
	
	int* d = new int[5];
	d[0]=5;
	d[1]=3;
	// content of ds?
	
	cout << "second construction "  << endl;
	my_container<int,5> data2(d);
	cout << "third construction "  << endl;
	my_container<int,5> data3(data);
	
	cout << "move assignemnt "  << endl;
	my_container<int,5> data4 = data2;
	cout << "content of data 2 "  << data2[0] << data4[1] << endl;
	cout << "content of data 4 "  << data4[0] << data4[1] << endl;
	
	
	return 0 ;
}