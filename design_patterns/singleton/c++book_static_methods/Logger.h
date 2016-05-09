// Logger.h defiinition of a singleton logger class implemented with static memthods 

#include <iostream>
#include <fstream>
#include <vector>

//#ifndef _LOGGER_H
//#define _LOGGER_H

class Logger
{
  public:
		static const std::string kLogLevelDebug;// static data member it exists for the class 
		static const std::string kLogLevelInfo;// static data member it exists for the class 
		static const std::string kLogLevelError;// static data member it exists for the class 
		
		// Log a single message at a given message level
		static void log(const std::string& inMessage,
		                const std::string& inLogLevel );
						
						
		// Log a vector of messages at a given message level
		static void log(const std::vector<std::string>& inMessages,
		                const std::string& inLogLevel );
						
		// cvloses the log file 
		static void teardown();
		
	protected:
		
		static void init();
		static const char* const kLogFileName;
		             
		static bool sInitialized; 
		static std::ofstream sOutputStream;
	
	private:
		Logger(); //{}
	
};
//#endif 