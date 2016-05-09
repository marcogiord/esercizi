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
	
     const std::string myford_car="Ford";
	 const std::string mytoyota_car="Toyota";
	
	std::vector<CarFactory*> factories;
	// create 4facories 
	CarFactory* factory1 = new CarFactory();
	CarFactory* factory2 = new CarFactory();
	//FordFactory* factory3 = new FordFactory();
	//ToyotaFactory* factory4 = new ToyotaFactory();
	
	// order some cars (need a CAR as output ??)
	Car* mycar = factory1->requestCar(mytoyota_car);
	mycar->info();
	
	Car* mycar2 = factory1->requestCar(myford_car);
	mycar2->info();
	
	std::cout<< "car in production  "<<factory1->getNumCarsInProduction()<<std::endl;
	
	//factory2->requestCar();
	//factory3->requestCar();
	//factory4->requestCar();
	
	
	factories.push_back(factory1);
	factories.push_back(factory2);
	//factories.push_back(factory3);
	//factories.push_back(factory4);
	
	std::cout<< "Loopinf for 10 cars "<<std::endl;
	
	// build 10 card from the least busy factory 
	for (int i=0; i<10; i++){
		CarFactory* myfactory = getLeastBusyFactory(factories);
		Car* mycar=myfactory->requestCar(mytoyota_car);
		mycar->info();
		}
	
}