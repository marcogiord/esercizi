#include "Grid.h"

int main(int argc, char **argv){
	
	// heap allocation
	//Grid<int>* myGrid=new Grid<int>();
	//myGrid->setElementAt(0,0,34);
	
	Grid<int> myNewGrid(10,10);
	myNewGrid.setElementAt(9,9,6);
	
	Grid<double> myNewGrid2(9,9);
	myNewGrid2=myNewGrid;
	
	
	// use copy constructor 
	
	//testNewGrid=myNewGrid;
	std::cout<< " element myNewGridv is " << myNewGrid.getElementAt(9,9) << std::endl;
	std::cout<< " element myNewGrid2 is " << myNewGrid2.getElementAt(10,10) << std::endl;
	std::cout<< " height " << myNewGrid2.getHeight() << std::endl;
	std::cout<< " height " << myNewGrid2.getWidth() << std::endl;
	
	//std::cout<< " height " << testNewGrid2.getHeight() << std::endl;
	//std::cout<< " widht " << testNewGrid2.getWidth() << std::endl;
	
		
}