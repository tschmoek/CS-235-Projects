#include "GPA.h"
using namespace  std;

GPA::GPA()
{
}


GPA::~GPA()
{
	clear();
}
double GPA::calcGpa(string LetterGrade)//Calc grade with two parameters
{
	double gradepoint = 0;
	if (LetterGrade == "A")
	{
		gradepoint = 4;//This is the points alloted if the grade is equal to specified letter
	}
	else if (LetterGrade == "A-")
	{
		gradepoint = 3.7;
	}
	else if (LetterGrade == "B+")
	{
		gradepoint = 3.4;
	}
	else if (LetterGrade == "B")
	{
		gradepoint = 3;
	}
	else if (LetterGrade == "B-")
	{
		gradepoint = 2.7;
	}
	else if (LetterGrade == "C+")
	{
		gradepoint = 2.4;
	}
	else if (LetterGrade == "C")
	{
		gradepoint = 2;
	}
	else if (LetterGrade == "C-")
	{
		gradepoint = 1.7;
	}
	else if (LetterGrade == "D+")
	{
		gradepoint = 1.4;
	}
	else if (LetterGrade == "D")
	{
		gradepoint = 1;
	}
	else if (LetterGrade == "D-")
	{
		gradepoint = .7;
	}
	else if (LetterGrade == "E")
	{
		gradepoint = 0;
	}
		return gradepoint;// Calculates points from the If statement
}

/*
* getMap()
*
* Returns the map storing the student information.
* The key of the map should be the student ID.
*/
  map<unsigned long long int, StudentInterface*> GPA::getMap() 
  {
	  return classmap;
  }

/*
* getSet()
*
* Returns the set storing the student information.
*/
  set<StudentInterface*, Comparator> GPA::getSet()
  {
	  return classset;
  }
unsigned long long int GPA::stuidconverter(string id)
{
    unsigned long long int studentid = 0;//number which will contain the result
    stringstream convert(id); // stringstream used for the conversion initialized with the contents of Text
    convert >> studentid;
    return studentid;
}

/*
* importStudents()
*
* Read in and parse through the given files. Each part of an entry in a
* file is given on a separate line in the file. Student ID is first, name is
* second, address is third, and phone is last. There are no blank lines between
* students. The following is an example file:
*
*	 5291738600
* 	 Dick B. Smith
* 	 879 Maple Road, Centralia, Colorado 24222
* 	 312-000-1000
* 	 9251738707
*	 Harry C. Anderson
*	 635 Main Drive, Midville, California 48444
* 	 660-050-2200
*
* If a valid file is given, the new Students should be added to the existing
* map and set.
*
* If an invalid file name is given or if there is a missing entry for a student,
* return false. Duplicate student ID numbers and duplicate students will not be
* tested for. There will never be a student that exists in the map and set. If
* the function returns false, then no changes should have been made to the
* existing map or set.
*
* The key of the map should be the student ID.
*
* Returns false if an invalid filename is given or if there is a missing entry for a
* student, otherwise true.
*/
  bool GPA::importStudents(string mapFileName, string setFileName)
  {
	  ifstream input;
	  ifstream input1;
      string studentid;
	  string address;
	  string name;
	  string phone;
	  unsigned long long int ID = 0;

	  input.open(mapFileName.c_str());

	  if (input.fail())
	  {
		  return false;
	  }

	  string dummy = "";
	  int cnt = 0;
	  while (getline(input, dummy))
	  {
		  cnt++;
	  }
	  if (cnt % 4 != 0)
	  {
		  return false;
	  }
	  input.close();





      input1.open(setFileName.c_str());
      dummy;
      cnt = 0;
      while(getline(input1,dummy))
      {
           cnt++;
      }
      if(cnt%4 != 0)
      {
           return false;
      }
      input1.close();

	  input1.open(setFileName.c_str());
	  if (input1.fail())
	  {
		  return false;
	  }
	  if (!input1.fail())
	  {
          while (getline(input1,studentid))//same
		  {
              getline(input1, name);
              getline(input1, address);
			  getline(input1, phone);

			  ID = stuidconverter(studentid);

              if (!input1.fail())
              {
                  Student* add = new Student(ID, name, address, phone);
                  classset.insert(add);
              }
		  }
	  }
      input1.close();


      

      input.open(mapFileName.c_str());
      if (!input.fail())
      {
          while (getline(input,studentid))//same
		  {
              getline(input,name);
              getline(input,address);
              getline(input,phone);
			  ID = stuidconverter(studentid);
			 
              Student* add = new Student(ID, name, address, phone);
              classmap.insert(pair<long long unsigned int, Student*>(ID, add));
		  }
		  input.close();
		  return true;
       }
	input.close();
    return false;
  }

/*
* importGrades()
*
* Read in and parse through the given file. Each part of an entry in the file
* is given on a separate line in the file. Student ID is first, course is
* second, and grade is last. There are no blank lines between entries. The
* following is an example file:
*
* 	5291738860
* 	CHEM134
* 	A
* 	9251734870
* 	BOT180
* 	B
* 	9251733870
* 	PE273
* 	D+
* 	5291738760
* 	HIS431
*  	A-
*
* Compute the GPA by finding the average of all the grades with a matching student ID
* in the Grade file. The GPA is calculated by taking a Student's total sum GPA and
* dividing by the number of classes taken. If the given student ID has no matching
* grades in the Grade file, the GPA is 0.00. It is not necessary to store the course
* names so long as the total number of courses taken is counted.
*
* You may assume that the given student ID exists in the map or set.
*
* Use the following point values for each grade.
*
*		  A = 4.0  A- = 3.7
*	B+ = 3.4  B = 3.0  B- = 2.7
*	C+ = 2.4  C = 2.0  C- = 1.7
*	D+ = 1.4  D = 1.0  D- = 0.7
*		  E = 0.0
*
* Returns false if an invalid filename is given, otherwise true.
*/
  bool GPA::importGrades(string fileName)
  {

	  ifstream input;
	  string studentid;
	  string course;
	  string grade;
	  unsigned long long int ID = 0;
	  input.open(fileName.c_str());
	  if (!input.fail())
	  {
		  while (getline(input, studentid))
		  {
			  getline(input, course);
			  getline(input, grade);
			  ID = stuidconverter(studentid);

			  for (auto it = classset.begin(); it != classset.end(); ++it)
			  {
				  
				  if (ID == (*it)->getID())
				  {
					  double gradepoint = 0;
					  gradepoint = calcGpa(grade);
					  (*it)->addGPA(gradepoint);
				  }
			  }
			  for (auto it = classset.begin(); it != classset.end(); ++it)
			  {
				  if (ID == (*it)->getID())
				  {
					  (*it)->getGPA();
				  }
			  }
			  for (auto it = classmap.begin(); it != classmap.end(); ++it)
			  {
				  if (ID == it->first)
				  {
					  double gradepoint = 0;
					  gradepoint = calcGpa(grade);
					  it->second->addGPA(gradepoint);
				  }
			  }
			  for (auto it = classmap.begin(); it != classmap.end(); ++it)
			  {
				  if (ID == it->first)
				  {
					  it->second->getGPA();
				  }
			  }
		  }
		  input.close();
		  return true;
	  }
	  input.close();
	  return false;
  }

/*
* querySet()
*
* Read in and parse through the given file. The 'Query' file contains a list of
* student ID numbers. Each entry in the Query file is a student ID given on a
* line by itself. You are to compute and report the GPA for each of the students
* listed in the Query file. The following is an example Query file:
*
* 	5291738860
* 	9251733870
*
* For each student ID given in the Query file, use the student information stored in
* your set to compute the GPA for the student and create an output string which
* contains the student ID, GPA, and name. If the given student ID does not match any
* student, do not give any output for that student ID. Each line of the output string
* contains student ID, GPA, and name as shown:
*
* 	5291738860 2.85 Dick B. Smith
*	9251733870 3.00 Harry C. Anderson
*
* Return a string representation of the given query. If an invalid file name is given,
* then return an empty string. The precision of the GPA will be rounded to two decimal places.
* There will be a trailing new line.
*/
  string GPA::querySet(string fileName)
  {
	  ifstream input;
	  stringstream ss;
	  string studentid;
	  string output;
	  unsigned long long int ID = 0;
	  input.open(fileName.c_str());
	  if (!input.fail())
	  {
		  while (getline(input,studentid))//same
		  {	
			  ID = stuidconverter(studentid);
			  for (auto it = classset.begin(); it != classset.end(); ++it)
			  {
				  if (ID == (*it)->getID())
				  {
					  ss.clear();
					  ss << (*it)->getID() << " " << (*it)->getGPA() << " " << (*it)->getName() << endl;
					  output = "" + ss.str();
				  }
			  }
		  }
		  input.close();
		  return output;
	  }
	  input.close();
	  return "";
  }

/*
* queryMap()
*
* Read in and parse through the given file. The 'Query' file contains a list of
* student ID numbers. Each entry in the Query file is a student ID given on a
* line by itself. You are to compute and report the GPA for each of the students
* listed in the Query file. The following is an example Query file:
*
* 	5291738860
* 	9251733870
*
* For each student ID given in the Query file, use the student information stored in
* your map to compute the GPA for the student and create an output string which
* contains the student ID, GPA, and name. If the given student ID does not match any
* student, do not give any output for that student ID. Each line of the output string
* contains student ID, GPA, and name as shown:
*
* 	5291738860 2.85 Dick B. Smith
*	9251733870 3.00 Harry C. Anderson
*
* Return a string representation of the given query. if an ivalid file name is given,
* then return an empty string. The precision of the GPA will be rounded to two decimal places.
* There will be a trailing new line.
*/
  string GPA::queryMap(string fileName)
  {
	  ifstream input;
	  unsigned long long int ID = 0;
	  string studentid;
	  string grade = "";
	  string output;
	  stringstream ss;
	  input.open(fileName.c_str());
	  if (!input.fail())
	  {
		  while (getline(input, studentid))//same
		  {
			  ID = stuidconverter(studentid);
			  for (auto it = classmap.begin(); it != classmap.end(); ++it)
			  {
				  if (ID == it->first)
				  {
					  ss.clear();
					  ss << it->second->getID() << " " << it->second->getGPA() << " " << it->second->getName() << endl;  
					  output = "" + ss.str();
				  }
				  
			  }
			  
		  }
		  input.close();
		  return output;
	  }
	  input.close();
	  return grade;
  }

/*
* Clears the students from the map and set.
*/
  void GPA::clear()
  {
      for (auto it = classmap.begin(); it != classmap.end(); ++it)
      {
		  delete it->second;
	  }
      for (auto it = classset.begin(); it != classset.end(); ++it)
      {
		  delete (*it);
      }

	  classmap.clear();
	  classset.clear();
  
  }
