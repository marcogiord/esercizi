//Creator.h

#include <iostream>
#include <map>

#ifndef _VESSEL_H
#define _VESSEL_H

using namespace std;

enum vType{RCA,LCX,LAD};

class Meas{
	public:
	    Meas(double hpv):_hpv(hpv){};
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
		virtual int getID() const{};
		virtual void addVesselToCase(vType ctype, Meas *measurement){};
};

// ypu mudst move all the characteristics to the parent class and leave in the child only the information on the segments 

// CREATE A VESSEL CASE WITH A MAP 
class VesselCase: public Vessel{
	public:	
	// constructor
		VesselCase(int id): Vessel(), _id(id) {
			this->info();
		}; 
		
	void info(){
			cout<<"Info: Vessel ID " << this-> getID() << endl;
			};
				
	int getID() const{return(_id);};
	
	void addVesselToCase(vType ctype, Meas *measurement){
		cout<<" insering vessel of type  "<< ctype <<  endl;
		_vMap.insert(VesselMapElement(ctype,measurement));
	};
		
	private:
		int _id;
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



