#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

// to compile 
// g++ -std=c++11 main.cpp -o main.exe


#ifndef _STUDENT_H
#define _STUDENT_H
enum year{fresh,soph,junior,senior,grad}; // placing these enum declaration inside the class does not work (because they are not sees in the main.cpp file )
enum support{ta,ra,fellowship,other};// placing these enum declaration inside the class does not work 

class student{
	public:
		//enum year{fesh,soph,junior,senior,grad}; 
		student(const char* nm, int id, double g, year x):student_id(id),gpa(g),y(x){
			strcpy(name,nm);}//constructor 
		void print() const;
	protected:
		int student_id;
		double gpa;
		year y;
		char name[30];
};

class grad_student: public student{
	public:
		//enum support{ta,ra,fellowship,other};
		grad_student(const char* nm, int id, double g, year x, 
		support t,const char* d, const char* th):student(nm,id,g,x),s(t){
			strcpy(dept,d); strcpy(thesis,th);}
		void print() const;
	protected:
		support s;
		char dept[30];
		char thesis[80];
};

void student::print() const{
	
	cout << name << " , " << student_id << " , " << y << " , " << gpa << endl;
} 

void grad_student::print()const {
	//student::
	student::print();
	cout << dept << " , " << s << " , " << thesis << endl;
}



class B{
	public:
		int i;
		virtual void print_i() const { cout << i << " inside B " << endl; }
};

class D: public B{
	public:
		void print_i() const { cout << i << " inside D " << endl; }
};
	

#endif