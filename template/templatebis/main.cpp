#include "Grid.h"

int main(int argc, char **argv){
	
	// heap allocation
	//Grid<int>* myGrid=new Grid<int>();
	//myGrid->setElementAt(0,0,34);
	
	Grid<int> myNewGrid;
	Grid<int> testNewGrid;
	myNewGrid.setElementAt(0,0,34);
	// use copy constructor 
	Grid<int> myNewGrid2(myNewGrid);
	testNewGrid=myNewGrid2;
	std::cout<< " element is " << testNewGrid.tElementAt << std::endl;
	
}