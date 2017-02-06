//Vessel.h

# include <iostream>

#ifndef _VESSEL_H
#define _VESSEL_H
using namespace std;

enum vType{RCA,LCX,LAD};

class Vessel {
	public:
		Vessel(int _number, VesType _type)
		: vesselNumber(_number), vesselType(_type){};
		
		~Vessel();
		
		virtual void info();
		//{std::cout<< "This is a vessel"<<std::endl;}
		
		virtual void set_vesselNumber(const int number);
		virtual void set_vesselType(const string& type);
		
		const int get_vesselNumber(return );
		const std::string get_vesselType();
		
		virtual Vessel* createVessel(){
        return new Vessel(*this);}
	private:
	    int vesselNumber
		vType _vesselType;
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