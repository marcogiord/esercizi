#include "CarFactory.h"
#include <vector>
// initialize to zeror when the factory is created 
CarFactory::CarFactory() : mNumCarsInProduction(0) {}

// iincvrememnty the number and reeturn the car 
Car* CarFactory::requestCar(){
	mNumCarsInProduction++;
	return createCar();
	// here you have to select what object will be created 
}

int CarFactory::getNumCarsInProduction() const
{
	return mNumCarsInProduction;	
}


Car* FordFactory::createCar()
{
	return new Ford();  
}

Car* ToyotaFactory::createCar(){
	return new Toyota(); 
}

