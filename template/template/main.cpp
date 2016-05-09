#include "Grid.h"
#include<iostream>

int main(int argc, char ** argv){

	Grid<double> myIntGrid(3,3);
	myIntGrid.setElementAt(0,0,10.0);
	
	std::cout<<"element is "<<myIntGrid.getElementAt(0,0)<<std::endl;
	
	int x=myIntGrid.getElementAt(0,0);
	
	Grid<double> grid2(myIntGrid);
	Grid<double> anothergrid=grid2;
	
	std::cout<<"element is "<<anothergrid.getElementAt(0,0)<<std::endl;
	std::cout<<"element is "<<anothergrid.getElementAt(1,1)<<std::endl;
	//Grid<int> anothergrid(myIntGrid);

    return(0);
}