// Logger.cpp

#include <string>
#include "Logger.h"

using namespace std;

const string Logger::kLogLevelDebug= "DEBUG";// static data member it exists for the class 
const string Logger::kLogLevelInfo = "INFO" ;// static data member it exists for the class 
const string Logger::kLogLevelError ="ERROR";// static data member it exists for the class 

const char* const Logger::kLogFileName= "log.out";              

//the static instance will be constructed when and program starts and estructed when iit ends
Logger Logger::sInstance;

Logger& Logger::instance(){
	return sInstance;
}

void Logger::log(const string& inMessage, const string& inLogLevel )
{
	mOutputStream <<  inLogLevel << ": "<< inMessage<< endl;
}

void Logger::log(const vector<string>& inMessages, const string& inLogLevel)
{
	for(size_t i=0; i<inMessages.size(); i++ ){
		log(inMessages[i],inLogLevel );
	}
}

Logger::Logger()
{
	mOutputStream.open(kLogFileName,ios_base::app);
	if(!mOutputStream.good()){
		cerr<<"Unable to iniitialize the logger!"<<endl;
	}
}

Logger::~Logger()
{
	mOutputStream.close();
}