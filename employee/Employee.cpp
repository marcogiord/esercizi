//Employee.cpp

#include <iostream>
#include "Employee.h"

using namespace std;

namespace Records {

	Employee::Employee()
	{
		mFirstName= "";
		mLastName = "";

		mEmployeeNumber = -1;
		mSalary = kDefaultStartingSalary;
		fHired=false;
	}

	
	
	void Employee::promote(int inRaiseAmount )
	{
		setSalary(getSalary()+inRaiseAmount ;
	}

	
	void Employee::demote(int inDemeritAmount )
	{
		setSalary(getSalary()+inDemeritAmount ;
	}




