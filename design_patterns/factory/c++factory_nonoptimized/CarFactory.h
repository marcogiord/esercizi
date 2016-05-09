// CarFactory.harderr
//thiis immentatio does not use the virtual car factories ....
//A similar pattern can be implemented 
// in a single class instead of a class hierarchy. In that case, a singlecreate() 
//method takes a type or string parameter from which it decides which object to create. For example, aCarFactory object 
//would provide abuildCar() method that takes a string representing the type of car and constructs the appropriate type. 
//However, that technique is less interesting and less flexible than the factory hierarchy described previously.
#include <vector>
#include "Car.h"
class CarFactory
{
	public:
		CarFactory();
		Car* requestCar(const std::string& inCarName);
		int getNumCarsInProduction() const;
	protected:
		//virtual Car* createCar(std::string& inCarName)=0;//pure virtual method, thsi class can not be instatiated		
		Car* createCar(const std::string& inCarName);// this would be non virtual because a facory can be instatiated 
	private:
		int mNumCarsInProduction;
};

//Car* CarFactory::createCar(std::string& inCarName)
/*class FordFactory : public CarFactory
{
	protected:
	       Car* createCar();	
};

class ToyotaFactory : public CarFactory
{
	protected:
	       Car* createCar();
};*/

//CarFactory* getLeastBusyFactory(const std::vector<CarFactory*>& inFactories);