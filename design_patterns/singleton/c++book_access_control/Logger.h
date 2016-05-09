// Logger.h defiinition of a singleton logger class implemented with access control

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
		
		// return a reference to the singleton logger object (this retrieve an instantiiation of this class)
		static Logger& instance();
		// Log a single message at a given message level
		void log(const std::string& inMessage,
		                const std::string& inLogLevel );
						
		// Log a vector of messages at a given message level
		void log(const std::vector<std::string>& inMessages,
		                const std::string& inLogLevel );
						
	protected:
		// static variable for the only instance ( this is a instantiation of this class, this object can be retrived by calling instance() )
		static Logger sInstance;
		
		static const char* const kLogFileName;
		             
		//static bool sInitialized;// not needed 
		std::ofstream mOutputStream;
	
	private:
		Logger(); //{}
		~Logger();
};
//#endif 