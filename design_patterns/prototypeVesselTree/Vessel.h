//Vessel.h

# include <iostream>

#ifndef _VESSEL_H
#define _VESSEL_H
using namespace std;

class Vessel {
	public:
		Vessel(int _number, std::string _type)
		: vesselNumber(_number), vesselType(_type)
	{
	
	}
		~Vessel();
		void info{std::cout<< "This is a vessel"<<std::endl;}
		
		void set_vesselNumber(const int number);
		void set_vesselType(const string& type);
		const int get_vesselNumber();
		const std::string get_vesselType();
		
		//void set_patientID(const int id);
		//%void set_connection(int start_seed, int end_seed);
		Vessel* createVessel(){
        return new Vessel(*this);}
	private:
	    int vesselNumber
		std::string vesselType;
		//string patientID;
		//vector <int> connection;		
};



/* class LAD : public Vessel {
	
	public:
		//virtual 
		void info(){ {std::cout<< "LAD"<<std::endl;}};
	
	 
};

class LCX : public Vessel {
	
	public:
		//virtual 
		void info(){ {std::cout<< "LCX"<<std::endl;}};
	
	 
}; */
#endif