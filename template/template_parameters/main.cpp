#include "Grid.h"

int main(int argc, char **argv){
	
	// heap allocation
	//Grid<int>* myGrid=new Grid<int>();
	//myGrid->setElementAt(0,0,34);
	
	Grid<int> myNewGrid;
	Grid<int, 10> testNewGrid;
	Grid<int, 25, 25> testNewGrid2;
	//myNewGrid.setElementAt(5,5,(testNewGrid.getElementAt(0,0));
	// use copy constructor 
	
	//testNewGrid=myNewGrid;
	std::cout<< " element is " << myNewGrid.getElementAt(25,25) << std::endl;
	std::cout<< " height " << myNewGrid.getHeight() << std::endl;
	std::cout<< " height " << myNewGrid.getWidth() << std::endl;
	
	std::cout<< " height " << testNewGrid2.getHeight() << std::endl;
	std::cout<< " widht " << testNewGrid2.getWidth() << std::endl;
	
	myNewGrid=testNewGrid;
	//myNewGrid=testNewGrid2;
	
}