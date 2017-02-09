//Creator.h

#include <iostream>
#include <string>
# include "Vessel.h"

#ifndef _VESSELFACTORY_H
#define _VESSELFACTORY_H

using namespace std;

class VesselFactory{
	public:
		VesselFactory(const std::string name) : mNumVesselsPresent(0), _nameVesselFactory(name){};
		Vessel* requestVessel(vType ctype, int ID);
		int getNumVesselPresent() const;
		std::string getnameVesselFactory() const;
	protected:
		Vessel* createVessel(vType ctype, int ID);// thiis method is not virtual it can be instatiated 
	private:
		int mNumVesselsPresent;
		std::string _nameVesselFactory;
};

Vessel* VesselFactory::requestVessel(vType ctype, int ID){
	std::cout<< "The VesselFactory <"<< getnameVesselFactory() << 
	"> has requested a vessel of type "<< ctype << "currently this factory has nr vessels: "<<  
	mNumVesselsPresent<<std::endl;
	
	mNumVesselsPresent++;
	return createVessel(ctype, ID);
}

std::string VesselFactory::getnameVesselFactory() const{
	return(_nameVesselFactory);	
}


int VesselFactory::getNumVesselPresent() const{
	return(mNumVesselsPresent);
}


Vessel* VesselFactory::createVessel(vType ctype, int segmentID)
{
	std::cout<< "Creation of a vessel   "<<std::endl;
	return new VesselImpl(segmentID,ctype);
}

#endif

/*Vessel* VesselFactory::createVessel(vType ctype, int segmentID)
{
	if(ctype==LCX){
		std::cout<< "Selected a LCX creation "<<std::endl;
		return new LCXVessel(mNumVesselsPresent,ctype,segmentID);
	}
    else if(ctype==LAD) {
		std::cout<< "Selected a LAD for creation "<<std::endl;
		return new LADVessel(mNumVesselsPresent,ctype,segmentID);
	} else {
		std::cout<< "The requested vessel type was not found  "<<std::endl;
		return(NULL);
	}
}*/




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
