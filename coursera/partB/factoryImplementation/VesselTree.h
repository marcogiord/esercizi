#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "Vessel.h"

#ifndef _VESSELTREE_H
#define _VESSELTREE_H

using namespace std;


class VesselTree
{
	public:
		VesselTree(){}		
		~VesselTree() {}
		//Vessel* requestCar();
		
	protected:
		virtual Vessel* createVessel()=0;
	private: 
		int numVesselsCurrentTree;
		std::vector <Vessel> VessselData;
};

 
 #endif
 

  

