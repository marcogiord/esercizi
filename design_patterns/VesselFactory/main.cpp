#include "VesselFactory.h"

#include <iostream>
#include <vector>
 
using namespace std;

int main()
{
	
	// to compile 
// g++ -std=c++11 main.cpp -o main.exe
  std::cout << __cplusplus << "\n";
	
   	
	std::vector<VesselFactory*> factories;
	// create 4facories 
	VesselFactory* factory1 = new VesselFactory("HPV experiment");	
	VesselFactory* factory2 = new VesselFactory("HPV validatiton");
	
	factory1->requestVessel(LCX,8);
	factory1->requestVessel(LCX,9);
	factory2->requestVessel(LAD,3);
	// how do i get a vessel 
	std::vector<Vessel*> vesvector;
	
	vesvector.push_back(factory1->requestVessel(LCX,8));
	std::cout<< "vessels present in production  "<<factory1->getNumVesselPresent()<<std::endl;
	// get the info of al vessels 	
	vesvector[0]->info();
	
	// order some cars (need a CAR as output ??)
	//Vessel* tempvessel = 
	//Vessel* tempvessel = factory1->requestVessel(LCX,8);
	//delete  tempvessel;
	
	//Vessel* tempvessel = factory1->requestVessel(LCX,9);
	//delete  tempvessel;
	
	//Vessel* tempvessel = factory2->requestVessel(LCX,3);
	//tempvessel->info();
	//delete  tempvessel;
	
	
}  