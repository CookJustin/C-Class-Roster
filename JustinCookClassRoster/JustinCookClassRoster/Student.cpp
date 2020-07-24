#include "Student.h"
//Constructor 
Student::Student() { //DEFAULT CONSTRUCTOR Sets default values to student object
	int defaultCourseDays[3] = { 20,15,10 };
	setStudentID("DEFAULT");
	setFirstName("DEFAULT");
	setLastName("DEFAULT");
	setEmailAddress("DEFAULT@email.com");
	setAge(18);
	setNumDaysToCompleteCourse(defaultCourseDays);
	setDegreeProgram(SOFTWARE);
}

//OVERLOADED CONSTRUCTOR sets to given values
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDaysToCompleteCourse[3], DegreeProgram degreeProgram)
{

	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->numDaysToCompleteCourse[0] = numDaysToCompleteCourse[0];
	this->numDaysToCompleteCourse[1] = numDaysToCompleteCourse[1];
	this->numDaysToCompleteCourse[2] = numDaysToCompleteCourse[2];
	this->deg = degreeProgram;
	
}
void Student::print() { //prints and tabs all information of a Student Object
	cout << "Student ID: " << studentID << "\t";
	cout << "First Name: " << firstName << "\t";
	cout << "Last Name: " << lastName << "\t";
	cout << "Email Address: " << emailAddress << "\t";
	cout << "Student Age: " << age << "\t";
	cout << "Days Left in Degree Program: {" << numDaysToCompleteCourse[0] << "," << numDaysToCompleteCourse[1] << "," << numDaysToCompleteCourse[2] << "}";
	cout << "Degree Program: " ;
	switch (this->deg)
	{
	case SECURITY: cout << "SECURITY" << "\t";
		break;
	case NETWORK: cout << "NETWORK" << "\t";
		break;
	case SOFTWARE: cout << "SOFTWARE" << "\t";
		break;
	}
	cout << endl;
	return;
}


//SETTERS AND GETTERS BELOW 
void Student::setStudentID(string setStudentID) 
{
	this->studentID = setStudentID;
	return;
}

void Student::setFirstName(string setFirstName)
{
	this->firstName = setFirstName;
	return;
}

void Student::setLastName(string setLastName)
{
	this->lastName = setLastName;
	return;
}

void Student::setEmailAddress(string setEmailAddress)
{
	this->emailAddress = setEmailAddress;
	return;
}

void Student::setAge(int setAge)
{
	this->age = setAge;
	return;
}

void Student::setNumDaysToCompleteCourse(int setNumDaysToCompleteCourse[3])
{ //This should be faster than a for loop because array is always of length 3 
	this->numDaysToCompleteCourse[0] = numDaysToCompleteCourse[0];
	this->numDaysToCompleteCourse[1] = numDaysToCompleteCourse[1];
	this->numDaysToCompleteCourse[2] = numDaysToCompleteCourse[2];
	return;
}

void Student::setDegreeProgram(DegreeProgram setDegreeProgram)
{
	this->deg = setDegreeProgram;
	return;
}

string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

int Student::getAge()
{
	return age;
}

int* Student::getNumDaysToCompleteCourse()
{
	return numDaysToCompleteCourse;
}

DegreeProgram Student::getDegreeProgram()
{
	return deg;
}
