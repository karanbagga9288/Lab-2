// Student Name: Karan Bagga
// Student Number: 200449124

#include <iostream>
#include <cstring>
#include <string>
#include "Enrollment.h"

using namespace std;


Enrollment::Enrollment()
{
    // completing code here
    setEmpty();
}

Enrollment::Enrollment(const char* n, const char* c, int y, int s, int ts)
{
    set(n, c, y, s, ts);
}

void Enrollment::set(const char* n, const char* c, int y, int s, int ts, bool e)
{
    // completed if and else
    if (y >= 2020 && (s > 0 && s < 4) && (ts > 0 && ts < 6) && n != nullptr && n[0] && c != nullptr && c[0])
    {
        //assigning values of local variables to global variables
        strncpy_s(name, n, 30);
        strncpy_s(code, c, 10);
        year = y;
        semester = s;
        timeSlot = ts;
        enrolled = e;
    }
    else
    {
        setEmpty();
    }
}

bool Enrollment::hasConflict(const Enrollment& other) const
{
    return isValid() && other.isValid() && (other.year == year && other.semester == semester && other.timeSlot == timeSlot);
}

bool Enrollment::isValid() const
{
    return name[0];
}

void Enrollment::setEmpty()
{
    //setting default values when Enrollment is in safe empty state
    name[0] = '\0';
    code[0] = '\0';
    year = 0;
    semester = 0;
    timeSlot = 0;
    enrolled = false;
    //completed
}

bool Enrollment::isEnrolled() const
{
    return enrolled;
}



void Enrollment::display(bool nameOnly) const
{
    if (isValid())
    {
        cout << name;
        if (!nameOnly)
        {
            cout << endl << code << ", Year: " << year << " semester: " << semester << " Slot: " << timeSlot << endl;
            cout << "Status: " << (isEnrolled() ? "E" : "Not e") << "nrolled." << endl;
        }
    }
    else
    {
        cout << "Invalid enrollment!" << endl;
    }

}









