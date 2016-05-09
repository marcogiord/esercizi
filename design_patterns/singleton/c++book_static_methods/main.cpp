#include "Logger.h"
#include <vector>
#include <string>

using namespace std;
int main(){
	
	// log in single message
	Logger::log("ciao bello",Logger::kLogLevelInfo);
	// prepare multi messages 
	vector<string> mymessages;
	mymessages.push_back("message 1");
	mymessages.push_back("message 2");
	// call l the logger for the mmulti message
	Logger::log(mymessages,Logger::kLogLevelError);
	// close file 
	Logger::teardown();
		
}