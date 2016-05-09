//main.cpp
#include <vector>
#include "Grid.h"

using namespace std;


int main(int argc, char ** argv)
{

	Grid<int, vector<int> > myIntGrid; 
	
	myIntGrid.setElementAt(3,4,5);
	
	Grid<int, vector<int> > myIntGrid2(myIntGrid);
	
	cout << "set element is "<< myIntGrid2.getElementAt(3,4);
	return (0);
}

