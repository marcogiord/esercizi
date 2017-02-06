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
	
	
	// order some cars (need a CAR as output ??)
	Vessel* tempvessel = factory1->requestVessel(LCX,8);
	Vessel* tempvessel = factory1->requestVessel(LCX,9);
	Vessel* tempvessel = factory2->requestVessel(LCX,3);
	
	tempvessel->info();
	
	
	std::cout<< "vessels present in production  "<<factory1->getNumVesselPresent()<<std::endl;
}  