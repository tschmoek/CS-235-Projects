#include "Student.h"


Student::Student(long long unsigned int studentid, string name, string address, string phone)
{
	this->studentid = studentid;
	this->name = name;
	this->address = address;
	this->phone = phone;
    GPA = "0.00";
	classcount = 0;
	grade = 0;

}
Student::~Student()
{
	// call the clear function which will call the delete function inside it
}
int Student::getClassCount()
{
	return classcount;
}

/*
* getID()
*
* Returns the ID of the Student.
*/
unsigned long long int Student::getID()
  {
	  return studentid;
  }

/*
* getName()
*
* Returns the name of the Student
*/

string Student::getName()
  {
	  return name;
  }

/*
* getGPA()
*
* Returns the string representation of the Student's GPA.
*/

string Student::getGPA()
  {
	  double GPAval = 0;
	  GPAval = grade / classcount;
	  stringstream ss;
	  ss << setprecision(2) << fixed << GPAval;
	  string strGPAVal = ss.str();
	  GPA = strGPAVal;
	  return GPA;
  }

/*
* addGPA()
*
* Incorporates the given course grade into the Student's overall GPA.
*/

void Student::addGPA(double classGrade)
{
	grade += classGrade;
	classcount++;
}

/*
* toString()
*
* The student object will be put into string representation. Student info will be
* ordered ID, name, address, phone number, and GPA. Each piece of information will
* be on its own line. GPA will not have a newline following it and the precision
* of the GPA will be rounded to two decimal places. For example,
*
* 123456789
* Ben Thompson
* 17 Russell St, Provo, UT 84606
* 555-555-5555
* 3.12
*
* Returns a string representation of the student object There is no trailing new line.
*/
string Student::toString()
  {
    stringstream ss;
    ss << studentid << endl << name << endl << address << endl << phone << endl << GPA;
    return ss.str();
  }
