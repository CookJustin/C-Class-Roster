#pragma once
#include <iostream>
#include "degree.h"
using namespace std;
class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int numDaysToCompleteCourse[3] = { 0,0,0 };
	DegreeProgram deg;
	
public:
	Student();//student constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDaysToCompleteCourse[3], DegreeProgram degreeProgram);
	void print();
	void setStudentID(string setStudentID);
	void setFirstName(string setFirstName);
	void setLastName(string setLastName);
	void setEmailAddress(string setEmailAddress);
	void setAge(int setAge);
	void setNumDaysToCompleteCourse(int setNumDaysToCompleteCourse[3]);
	void setDegreeProgram(DegreeProgram setDegreeProgram);

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getNumDaysToCompleteCourse();
	DegreeProgram getDegreeProgram();
};