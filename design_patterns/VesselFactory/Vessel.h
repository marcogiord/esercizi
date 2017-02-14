//Creator.h

#include <iostream>
#include <map>

#ifndef _VESSEL_H
#define _VESSEL_H

using namespace std;

enum vType{RCA,LCX,LAD};

class Meas{
	public:
	    Meas(){};
		double gethpv() const{return(this->_hpv);};
		void sethpv(double chpv){this->_hpv=chpv;};
	private:
		double _hpv;
};


class Vessel{
	public:
		typedef std::map<vType, Meas* > VesselMapType;
		typedef std::map<vType, Meas* >::iterator VesselMapIter;
		typedef std::pair<vType, Meas* > VesselMapElement;
	public:
		Vessel() {};
		~Vessel() {};
		virtual void info()=0;
		
};

// ypu mudst move all the characteristics to the parent class and leave in the child only the information on the segments 

// CREATE A VESSEL CASE WITH A MAP 
class VesselCase: public Vessel{
	public:	
		VesselCase(int id): Vessel(), _id(id) {
			this->info();
		}; // constructor
		
	void info(){
			cout<<"Vessel ID" << this-> getID() << endl;
				};
				
	int getID() const{return(_id);};
	
	void addVesselToCase(vType ctype, Meas *measurement){
		//_vMap[ctype]=measurement;		
		_vMap.insert(VesselMapElement(ctype,measurement));
	};
	
	
	private:
		int _id;
		//std::map<vType, Meas* > _vMap;
		VesselMapType _vMap;
};

/*class VesselImpl: public Vessel{
	public:	
		VesselImpl(int id, vType ctype): Vessel(), _id(id), _type(ctype) {
			this->info();
			
		}; // constructor
				
		void info(){
			cout<<"Vessel type " << this->_type << endl
				<<"Vessel ID  : " << this-> getID() << endl;
				};
				
		int getID() const{return(_id);};
		
	private:
		int _id;
		std::map<int, Meas* > _vMap;
		vType _type;
};*/

// this is subooptiimal because the code is repeated, maybe increase the levels of abstraction.
#endif






/*class VesselFactory {
	public:
		VesselFactory();
		Vessel* requestVessel();
		int getNumVessels() const;
	protected:
		virtual Vessel* createVessel() ;   // 
	private:
		
};*/

// should i implement the sub factories... not needed if the creator is not virtual 

/*class Vessel {
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
};*/



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
