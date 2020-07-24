#include <iostream>
#include "roster.h"
#include <string>
using namespace std;
Roster::Roster()
{
     const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Test,ok,temptemptemp@gmail.com,22,50,58,40,SOFTWARE" };
         
    string tempstring; //creates a temporary string that will be used to parse
    for (int i = 0; i < 5; i++) { //cycles through each student in the student data array
    tempstring = studentData[i];

    //parses all the values E2.a
    parsedStudentID = (tempstring.substr(0, tempstring.find(',')));
    tempstring = tempstring.substr(tempstring.find(',') + 1);
    parsedFirstName = (tempstring.substr(0, tempstring.find(',')));
    tempstring = tempstring.substr(tempstring.find(',') + 1);
    parsedLastName = (tempstring.substr(0, tempstring.find(',')));
    tempstring = tempstring.substr(tempstring.find(',') + 1);
    parsedEmail = (tempstring.substr(0, tempstring.find(',')));
    tempstring = tempstring.substr(tempstring.find(',') + 1);
    parsedAge = (stoi(tempstring.substr(0, tempstring.find(','))));
    tempstring = tempstring.substr(tempstring.find(',') + 1);
    parsedDaysInCourse1 = (stoi(tempstring.substr(0, tempstring.find(','))));
    tempstring = tempstring.substr(tempstring.find(',') + 1);
    parsedDaysInCourse2 = (stoi(tempstring.substr(0, tempstring.find(','))));
    tempstring = tempstring.substr(tempstring.find(',') + 1);
    parsedDaysInCourse3 = (stoi(tempstring.substr(0, tempstring.find(','))));
    tempstring = tempstring.substr(tempstring.find(',') + 1);
    parsedDegreeProgram = (strToDeg(tempstring.substr(0)));
     
    //calls the add method with parsed values to Add each student object to classRosterArray. E2.b
    add(parsedStudentID, parsedFirstName, parsedLastName, parsedEmail, parsedAge, parsedDaysInCourse1, parsedDaysInCourse2, parsedDaysInCourse3, parsedDegreeProgram);
    }
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int tmpArray[3] = { daysInCourse1,daysInCourse2,daysInCourse3 };
	Student* newStudent = nullptr;
	newStudent = new Student(studentID, firstName,lastName,emailAddress,age,tmpArray,degreeProgram);

	classRosterArray.push_back(newStudent);
	
} //^ creates a new student object with paramaters then adds it to the classRosterArray

void Roster::remove(string studentID) //removes a student with studentID from classRosterArray
{
    for (size_t i = 0; i < classRosterArray.size(); i++) {

        if (classRosterArray.at(i)->getStudentID() == studentID) {
            classRosterArray.erase(classRosterArray.begin() + i);
            return;
        }
    }
    cout << "No student with id: " << studentID << " was found" << endl;
}

void Roster::printAll() //prints all student info in classRosterArray
{
    for (size_t  i = 0; i < classRosterArray.size(); i++) {
        classRosterArray.at(i)->print();
    }
    cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) //prints average of course days for student
{
    int tmpAvg;
    for (size_t i = 0; i < classRosterArray.size(); i++) {
       
        if (classRosterArray.at(i)->getStudentID() == studentID) {
            tmpAvg = classRosterArray.at(i)->getNumDaysToCompleteCourse()[0] + classRosterArray.at(i)->getNumDaysToCompleteCourse()[1] + classRosterArray.at(i)->getNumDaysToCompleteCourse()[2]; 
            cout << "The average days left for student with id " << studentID << " is: " << tmpAvg / 3 << endl;

            return;
        }
       

    }
    cout << "No student with " << studentID << " Found." << endl;
    
}


void Roster::printInvalidEmails() //prints all emails that are invalid along with their student ID
{
    string tmpID;
    string tmpEmail;
    for (size_t i = 0; i < classRosterArray.size(); i++) {
        tmpID = classRosterArray.at(i)->getStudentID();
        tmpEmail = classRosterArray.at(i)->getEmailAddress();
        if (tmpEmail.find('@' != -1) && tmpEmail.find('.') != -1 && tmpEmail.find(' ') != -1) {
            cout << "Student with id: " << tmpID << " has the invalid email address: " << tmpEmail << endl;
        }

    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) //Prints all students in a given degree
{
    cout << "The Following students are in the " << degToStr(degreeProgram) << " degree program" << endl;
    for (size_t i = 0; i < classRosterArray.size(); i++) {
        if ((classRosterArray.at(i)->getDegreeProgram()) == degreeProgram) {

            classRosterArray.at(i)->print();
        }
    }
}

int Roster::getRosterSize() //allows main.cpp (or other files) to see classRosterSize
{
    return classRosterArray.size();
}

Student* Roster::getStudentPtr(int indexInRoster) //allows main.cpp (or other files) to have a pointer to student
{
    return classRosterArray[indexInRoster];
}

Roster::~Roster() //releases memory allocated in Roster
{
    cout << "Destructor Called";
	for (size_t i = 0; i < classRosterArray.size(); i++)
	{
		delete this->classRosterArray[i];
	}
	delete this;
}

DegreeProgram Roster::strToDeg(const std::string& str) //used for enum conversions of DegreeProgram
{
		if (str == "SECURITY") return SECURITY;
		else if (str == "NETWORK") return NETWORK;
		else if (str == "SOFTWARE") return SOFTWARE;
		else {
			return SOFTWARE;
		}
	}
string Roster::degToStr(DegreeProgram deg)//used for enum conversions of DegreeProgram
{
    if (deg == SECURITY) return "SECURITY";
    else if (deg == NETWORK) return "NETWORK";
    else if (deg == SOFTWARE) return "SOFTWARE";
    else {
        return "invalid degree";
    }
}
