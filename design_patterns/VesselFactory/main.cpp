#include "VesselFactory.h"

#include <iostream>
#include <vector>
 
using namespace std;

int main()
{
	
	// to compile 
// g++ -std=c++11 main.cpp -o main.exe
  std::cout << __cplusplus << "\n";
	
   	
	//std::vector<VesselFactory*> factories;
	// create 4facories 
	VesselFactory* factory1 = new VesselFactory("HPV experiment");	
	VesselFactory* factory2 = new VesselFactory("HPV validatiton");
	
	factory1->requestVesselCase(8); // by doing this only the number of vessels is increased but the vessel is not stored 
	factory1->requestVesselCase(12);
	factory1->requestVesselCase(13);
	
	
	factory2->requestVesselCase(7);
	factory2->requestVesselCase(8);
	
	factory1->getinfoAllVessels();
	factory2->getinfoAllVessels();
	
	// create a vecxtor of pointers to vessels  
	//std::vector<Vessel*> vesvector;
	
	//vesvector.push_back(factory1->requestVessel(LCX,12));
	//vesvector.push_back(factory1->requestVessel(LCX,13));
	//vesvector.push_back(factory1->requestVessel(LAD,7));
	
	//std::cout<< "################### "<<factory1->getNumVesselPresent()<<std::endl;
	//std::cout<< "##############################  "<<factory1->getNumVesselPresent()<<std::endl;
	// get the info of al vessels 
	//std::cout<< "Vessell factory  "<< factory1->getnameVesselFactory() << " with num vessels: " <<factory1->getNumVesselPresent()<<std::endl;
	//std::cout << "content of each vessel  "<< std::endl;
	//for (auto i: vesvector)
	//	i->info();
	
	//vesvector[0]->info();
	
	
	
}  