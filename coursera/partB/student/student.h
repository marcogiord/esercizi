#include <iostream>
#include <vector>
#include <string>

using namespace std;

// to compile 
// g++ -std=c++11 main.cpp -o main.exe


#ifndef _STUDENT_H
#define _STUDENT_H

class sudent{
	public:
		enum year {fesh, soph, junior, senior,grad};
		student(char* nm, int id, double g, year x):student_id(id),gpa(g),y(x){
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
		enum support{ta,ra,fellowship,other};
		grad_student(char* nm, int id, double g, year x, 
		support t,char* d, char* th):student(nm,id,g,x),s(t){
			strcpy(dept,d); strcpy(thesis,th);}
		void print() const;
	protected:
		support s;
		char dept[10];
		char thesis[80];
}



#endif