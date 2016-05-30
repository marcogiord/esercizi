#include "Grid.h"
#include "GridChar.h"

#include<iostream>

int main(int argc, char ** argv){

	Grid<double> myIntGrid(3,3);
	myIntGrid.setElementAt(0,0,10.0);
	
	std::cout<<"element is "<<myIntGrid.getElementAt(0,0)<<std::endl;
	
	
	Grid<double> grid2(myIntGrid);
	Grid<double> anothergrid=grid2;
	
	std::cout<<"element is "<<anothergrid.getElementAt(0,0)<<std::endl;
	std::cout<<"element is "<<anothergrid.getElementAt(1,1)<<std::endl;
	
	Grid<char *> chargrid(3,3);
	chargrid.setElementAt(1,1,"my first string");
	std::cout<<"element char grid is "<<chargrid.getElementAt(1,1)<<std::endl;
	
	Grid<char *> chargrid2(3,3);
	//chargrid2=chargrid;
	chargrid2.copyFrom(chargrid);
	
	std::cout<<"element char grid is "<<chargrid2.getElementAt(1,1)<<std::endl;
	

    return(0);
}