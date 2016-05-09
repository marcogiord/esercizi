#include "myclass.h"
#include <iostream>

Super::Super(){
}

void Super::SomeMethod(){
std::cout << "This is Super version of somemethod "<<std::endl;
}

Sub::Sub(){};
void Sub::SomeMethod(){
std::cout << "This is Sub version of somemethod "<<std::endl;
}

/*void Sub::SomeOtherMethod(){
std::cout << "This is Sub version of someothermethod "<<std::endl;
}*/