#include "CarFactory.h"
#include <vector>
// function to look for least busy factory  

CarFactory* getLeastBusyFactory(const std::vector<CarFactory*>& inFactories)
{
	if(inFactories.size() == 0 ) return NULL;
	// initialize
	CarFactory* leastBusyfactory=inFactories[0];
	for (size_t i=1; i< inFactories.size(); i++ ){
		if( leastBusyfactory->getNumCarsInProduction() > inFactories[i]->getNumCarsInProduction()  ){
			leastBusyfactory=inFactories[i];
		}
	}
	return leastBusyfactory;
}


int main(){
	
	 std::cout << __cplusplus << "\n";
	

	
	std::vector<CarFactory*> factories;
	// create 4facories 
	FordFactory* factory1 = new FordFactory();
	FordFactory* factory2 = new FordFactory();
	FordFactory* factory3 = new FordFactory();
	ToyotaFactory* factory4 = new ToyotaFactory();
	std::cout<< "creted facatory "<<std::endl;
	// order some cars (need a CAR as output ??)
	factory1->requestCar();
	factory2->requestCar();
	factory3->requestCar();
	factory4->requestCar();
	std::cout<< "creted carsy "<<std::endl;
	
	factories.push_back(factory1);
	factories.push_back(factory2);
	factories.push_back(factory3);
	factories.push_back(factory4);
	
	std::cout<< "creted factor "<<std::endl;
	
	// build 10 card from the least busy factory 
	for (int i=0; i<10; i++){
		CarFactory* myfactory = getLeastBusyFactory(factories);
		Car* mycar=myfactory->requestCar();
		mycar->info();
		}
	
}