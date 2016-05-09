#include <iostream>
#include <string>

#include <string>            // string
#include <vector>            // vector<>
#include <cassert>            // assert()

using namespace std;


int main (int argc, char ** argv)
{

  //typedef vector<float> ImageDataType;
  //typedef ImageDataType::iterator  ImageDataIter;

	vector<float> data;
	vector<float> dataOut;

	vector<float>::const_iterator it;
	vector<float>::iterator iMyiteratorEnd;

	std::cout << "welcome to mytest " <<std::endl;
	std::cout << "******************" <<std::endl;  

	data.push_back(1);
	data.push_back(2);
	data.push_back(3);
	data.push_back(4);

	dataOut.assign(data.begin(), data.end());


		
	for (it = dataOut.begin(); it != dataOut.end(); it++)
		cout<<" "<<*it;

	std::cout <<std::endl;  
	std::cout << "goodbye to mytest " <<std::endl;


}


