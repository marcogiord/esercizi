#include "CarFactory.h"
#include <vector>
// initialize to zeror when the factory is created 
CarFactory::CarFactory() : mNumCarsInProduction(0) {}

// iincvrememnty the number and reeturn the car 
Car* CarFactory::requestCar(const std::string& inCarName){
	// message to indentify which factory are we 
	std::cout<< "a car has been requested to our factory which has produced "<<mNumCarsInProduction<<std::endl;
	mNumCarsInProduction++;
	return createCar(inCarName);
}

int CarFactory::getNumCarsInProduction() const
{
	return mNumCarsInProduction;	
}

Car* CarFactory::createCar(const std::string& inCarName)
{
	if(inCarName=="Ford"){
		return new Ford();
	}
    else if(inCarName=="Toyota"){
		return new Toyota();
	}
}


