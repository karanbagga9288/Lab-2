// Student Name: Karan Bagga
// Student Number: 200449124

#ifndef ENROLLMENT_H_
#define ENROLLMENT_H_

#define MAX_NAME 30
#define MAX_CODE 10


class Enrollment
{
private:
    //code for completing this
    char name[MAX_NAME + 1];
    char code[MAX_CODE + 1];
    int year;
    int semester;
    int timeSlot;
    bool enrolled;

public:
    Enrollment();
    Enrollment(const char*, const char*, int, int, int);//fixed it
    void set(const char*, const char*, int, int, int, bool = false);
    bool hasConflict(const Enrollment&) const;
    void display(bool = false) const;
    bool isValid() const;
    void setEmpty();
    bool isEnrolled() const;
    
};


#endif
