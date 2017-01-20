#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

// to compile 
// g++ -std=c++11 main.cpp -o main.exe

template <typename ForwardIterator>
void square (ForwardIterator first, ForwardIterator last)
{
	
	for(; first!=last; first++)
		*first = (*first) * (*first);
}

template <typename BidirectionalIterator>
bool isPalindrome (BidirectionalIterator first, BidirectionalIterator last){
	
	while(true){
		
		last--;//decrement last
		if(last==first)
			break; // you got to the middle of the work 
		
		if(*last!=*first)
			return false;
		
		first++;
		if(first==last)
			break;
	}
	return true;
	
}

//void outvec(int i){cout<<i<<endl;}

//fvec = [](int i){cout<<i<<endl;}
void incr(int& i){static int n=1;i=n++;}
	//[](int& i){static int n=1;i=n++;}
//auto fincr = [](int& i){static int n=1;i=n++;};


int main(){
	
	std::cout << __cplusplus << "\n";
	
	
	// some maps 
	map<unsigned long, string> worker;
	unordered_map<unsigned long,unsigned> payroll;
	unsigned total_pay=0;
	
	worker[99567800] = "Harold Fish";
	payroll[99567800] = 63700;
	worker[8885978] = "Philips Fish";
    payroll[8885978] = 85000;
	
	for (auto p=worker.begin(); p!=worker.end(); ++p)
		cout << "worker id "<< (*p).first << " name " << (*p).second << endl;
	
	for (auto c=payroll.begin(); c!=payroll.end(); ++c)
		cout << "worker id "<< (*c).first << " salary " << (*c).second << endl;
	
	// algorithms 
	string words[5]={"my","hop","mop","hope","cope"};
	
	string* where;
	
	where = find(words,words+5,"hop");
	cout << " what is after " << *++where << endl;
	sort(words,words+5);
	where = find(words,words+5,"hop");
	cout << " what is after (after sorting) " << *++where << endl;
	
	
	// palindrome
	std::vector<char> v{'a','b','b','a'};
    	
	cout << " is palindrome" << isPalindrome(v.begin(),v.end()) << endl;
	cout << " plot vector " << v[0] << v[1] << endl; 
	
	
	// 
	vector<int> newvec(6);
	
	//for (auto c=newvec.begin(); c!=payroll.end(); ++c)
	//	cout << "worker id "<< (*c).first << " salary " << (*c).second << endl;
	
	// lambda functions 
	for_each(newvec.begin(),newvec.end(),[](int& i){static int n=1;i=n++;});	
	for_each(newvec.begin(),newvec.end(),[](int i){cout<<i<<endl;});
	
	// algorithms 
	double v1[3]={1.0, 2.5, 4.6}, v2[3]={1.0,2.0,3.0};
	double sum, inner_p;
	
	sum= accumulate(v1,v1+3,0.0);
	inner_p=inner_product(v1,v1+3,v2,sum);
	
	cout << " accumlate is  " << sum << endl;
		cout << " innerproduct is  " <<  inner_p<< endl;

	sum= accumulate(v1,v1+3,0.0,minus<int>());
	cout << " accumulate (with minus)) is  " << sum << endl;
}