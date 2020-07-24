#pragma once
#include <vector>
#include "Student.h"
using namespace std;
class Roster {
public:
	Roster(); //constructor
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	int getRosterSize(); //used to pass the rosterSize to main.cpp
	Student* getStudentPtr(int indexInRoster); //used to pass the student pointer to main.cpp
	~Roster(); //destructor
	DegreeProgram strToDeg(const std::string& str);
	string degToStr(DegreeProgram deg);
	
private:
	vector<Student*> classRosterArray; //creates a dynamic array for more flexability 
	DegreeProgram parsedDegreeProgram = SOFTWARE;
	string parsedStudentID = "";
	string parsedFirstName = "";
	string parsedLastName = "";
	string parsedEmail = "";
	int parsedAge = 0;
	int parsedDaysInCourse1 = 0;
	int parsedDaysInCourse2 = 0;
	int parsedDaysInCourse3 = 0;
};