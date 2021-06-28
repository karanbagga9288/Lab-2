// COMP2006 Lab 2: Constructors
// File: main.cpp, Enrollment.h, Enrollment.cpp
// Version: 3.0
// Date: 2021/06/10
// Student Name: Karan Bagga
// Student Number: 200449124
// code a class for simple objects
// define a constructor that sets an object to a safe empty state
// overload a constructor to receive information from a client
//////////////////////////////////////////////////////////////////

#include <iostream>
#include "Enrollment.h"

#define BAD_DATA_ARRAY 9

using namespace std;


void displayEnrollments(const Enrollment& e1, const Enrollment& e2);

int main()
{
    // constructors
    Enrollment e1("Math for the Computer Industry", "MATH 1003", 2021, 1, 5);
    Enrollment e2, e3;
    Enrollment badData[BAD_DATA_ARRAY] = {
        Enrollment("Programming Fundamentals", "COMP1030", 2020, 1, 5),
        Enrollment(nullptr, "COMP1030", 2020, 1, 5),
        Enrollment("Programming Fundamentals", nullptr, 2020, 1, 5),
        Enrollment("", "COMP1030", 2020, 1, 5),
        Enrollment("Programming Fundamentals", "", 2020, 1, 5),
        Enrollment("Programming Fundamentals", "COMP1030", 2019, 1, 5),
        Enrollment("Programming Fundamentals", "COMP1030", 2020, 0, 5),
        Enrollment("Programming Fundamentals", "COMP1030", 2020, 4, 5),
        Enrollment("Programming Fundamentals", "COMP1030", 2020, 1, 0)
    };

    cout << "Testing Enrollment objects" << endl << endl;

    // testing two invalid Enrollments
    displayEnrollments(e3, e2);

    // testing valid and invalid Enrollments
    displayEnrollments(e1, e2);

    // setting the second one to BTP200
    e2.set("Object Oriented Programming in C++", "COMP2006", 2020, 1, 5);

    displayEnrollments(e1, e2);

    // setting the enrollment to true;
    e2.set("Object Oriented Programming in C++", "COMP2006", 2020, 1, 5, true);

    displayEnrollments(e1, e2);

    // removing conflict;
    e2.set("Object Oriented Programming in C++", "COMP2006", 2020, 1, 6);

    displayEnrollments(e1, e2);

    // making sure all the conditions are met for an invalid Enrollment.
    cout << endl << "Only index 0 should be valid:" << endl;
    for (int i = 0; i < BAD_DATA_ARRAY; i++)
    {
        cout << "index: " << i << " - " << (badData[i].isValid() ? "V" : "Not v") << "alid." << endl;
    }

    return 0;
}

void displayEnrollments(const Enrollment& e1, const Enrollment& e2)
{
    cout << "----------------------------------------------" << endl;
    e1.display();
    cout << (e1.isEnrolled() ? "E" : "Not e") << "nrolled" << endl;
    e2.display();
    cout << endl << "There is " << (e1.hasConflict(e2) ? "" : "not ") << "a conflict!" << endl;
}