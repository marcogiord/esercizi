//main.cpp
#include <vector>
#include "Grid.h"

using namespace std;


int main(int argc, char ** argv)
{

	Grid<int, vector> myGrid; 
	
	myGrid.setElementAt(3,4,5);
	myGrid.getElementAt(3,4);
	
	Grid<int, vector> myIntGrid2(myGrid);
	
	
	return (0);
}

