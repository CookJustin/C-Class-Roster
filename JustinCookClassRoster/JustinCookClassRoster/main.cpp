// JustinCookClassRoster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Student.h"
#include "roster.h"
int main() //Main starts program
{

    Roster* classRoster = nullptr; //creates a roster pointer
    classRoster = new Roster; //assigns roster pointer to new roster object
 
    classRoster->printAll(); //prints all students in the roster;
    classRoster->printInvalidEmails(); //prints users id and the invalid email

    for (int i = 0; i < classRoster->getRosterSize(); i++) { //loops through class roster printing studentID with avg days in course
        classRoster->printAverageDaysInCourse(classRoster->getStudentPtr(i)->getStudentID());
    }

    classRoster->printByDegreeProgram(SOFTWARE); //prints all students in the degree Software

    classRoster->remove("A3"); //removes student with id A3
    classRoster->printAll(); //prints remaining students
    classRoster->remove("A3"); //attempts to remove a student that doesnt exist

    return 0;
}
