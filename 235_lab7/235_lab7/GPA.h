#pragma once
#include "GPAInterface.h"
#include "StudentInterface.h"
#include "Student.h"
#include <iostream>
#include <fstream>
#include <sstream>

class GPA :
	public GPAInterface
{
protected:
	map<unsigned long long int, StudentInterface*> classmap;
	set<StudentInterface*, Comparator> classset;
public:
	GPA();
	~GPA();
	 double calcGpa(string LetterGrade);
     unsigned long long int stuidconverter(string id);
	 map<unsigned long long int, StudentInterface*> getMap();
	 set<StudentInterface*, Comparator> getSet();
	 bool importStudents(string mapFileName, string setFileName);
	 bool importGrades(string fileName);
	 string querySet(string fileName);
	 string queryMap(string fileName);
	 void clear();
};

/*

LAB 7 Help Session

GPA Interface is really a class, a group of session.

No duplicate students

Sets dont allow duplicate

Maps - Key value pair - ID is the key and Student object is the value(ie Name, Grade, ID and address)

Student
Name
long long unsigned int - ID
address
double totalgpa -  sum gradepoint
double totalclass - sum classes

add one to class count for every gpa increase


GPAINTERFACE

map of students
set of students

file name for both

import students
readin students, check for format, create new objects.

import grades
look through both map and set for student with that id to add the grades to the record

queurymap
search for id's use an iterator while (iter != map.end())
iter->first;
iter->second
iter = map.begin()
iter++

output information as string

queryset
search for id's use an iterator
output information as string

MEMORY LEAKS






*/
