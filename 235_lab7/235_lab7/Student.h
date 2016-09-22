#pragma once
#include "StudentInterface.h"
#include "GPA.h"
#include <sstream>
#include <string>
#include <iomanip>
class Student :
	public StudentInterface
{
protected:
	long long unsigned int studentid;
	string address;
	string name;
	string phone;
	string GPA;
    double grade;
    int classcount;
public:
	Student(long long unsigned int studentid, string name, string address, string phone);
	~Student();

	  void incramentClassCount();
	  int getClassCount();
	  unsigned long long int getID() ;
	  string getName() ;
	  string getGPA() ;
	  void addGPA(double classGrade) ;
	  string toString() ;
};

