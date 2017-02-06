#include "Vessel.h"
# include <iostream>

#ifndef _VESSELFACTORY_H
#define _VESSELFACTORY_H


class VesselFactory
{
	public:
		VesselFactory();
		//Vessel* requestVessel(const int _number, const std::string _type);
		int getNumVesselinTree() const;
	protected:
		 Vessel* createVessel(const int _number, const std::string _type);//pure virtual method, thsi class can not be instatiated		
	private:
		int mNumVesselinTree;
};


VesselFactory::VesselFactory(): mNumVesselinTree(0) {}


/*Vessel* VesselFactory::requestVessel(const int _number, const std::string _type){
	mNumVesselinTree++;
	return createVessel(_number,_type); 
	
}*/

Vessel* VesselFactory::createVessel(const int _number, const std::string _type){
	mNumVesselinTree++
	return new Vessel(_number,_type);
}


#endif