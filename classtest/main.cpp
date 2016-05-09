#include "myclass.h"

int main(int argc, char ** argv)
{

	Super mySuper;
	Sub mySub;

	Super &ref=mySub;

	mySuper.SomeMethod();
	mySub.SomeMethod();

	ref.SomeMethod();
	return (0);
}

