#include "Logger.h"
#include <vector>
#include <string>

using namespace std;
int main(){
	
	// log in single message
	Logger::instance().log("ciao bello",Logger::kLogLevelError);
	// prepare multi messages 
	vector<string> mymessages;
	mymessages.push_back("message 1");
	mymessages.push_back("message 2");
	// call l the logger for the mmulti message
	Logger::instance().log(mymessages,Logger::kLogLevelError);
	//Logger::instance().sOutputStream.open("log.out",ios_base::app);
}