// Logger.cpp

#include <string>
#include "Logger.h"

using namespace std;

const string Logger::kLogLevelDebug= "DEBUG";// static data member it exists for the class 
const string Logger::kLogLevelInfo = "INFO" ;// static data member it exists for the class 
const string Logger::kLogLevelError ="ERROR";// static data member it exists for the class 

const char* const Logger::kLogFileName= "log.out";
              
bool Logger::sInitialized=false;
ofstream Logger::sOutputStream;

void Logger::log(const string& inMessage, const string& inLogLevel )
{
	if(!sInitialized){
		init();
	}
	sOutputStream  <<  inLogLevel << ": "<< inMessage<< endl;
}

void Logger::log(const vector<string>& inMessages, const string& inLogLevel)
{
	for(size_t i=0; i<inMessages.size(); i++ ){
		log(inMessages[i],inLogLevel );
	}
}

void Logger::teardown()
{
	if(sInitialized){
		sOutputStream.close();
		sInitialized= false;
	}
}

void Logger::init()
{
	if(!sInitialized){
		sOutputStream.open(kLogFileName,ios_base::app);
        if(!sOutputStream.good()){
			cerr<<"Unable to iniitialize the logger!"<<endl;
			return;
		}
		sInitialized=true;
	}
}
