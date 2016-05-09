// CarFactory.harderr

#include "Car.h"
#include <vector>

class CarFactory
{
	public:
		CarFactory();
		Car* requestCar();
		int getNumCarsInProduction() const;
	protected:
		virtual Car* createCar()=0;//pure virtual method, thsi class can not be instatiated		
	private:
		int mNumCarsInProduction;
};


class FordFactory : public CarFactory
{
	protected:
	       Car* createCar();	
};

class ToyotaFactory : public CarFactory
{
	protected:
	       Car* createCar();
};

//CarFactory* getLeastBusyFactory(const std::vector<CarFactory*>& inFactories);