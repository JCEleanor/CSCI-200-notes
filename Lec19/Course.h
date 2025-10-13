#ifndef STUDENT_H
#define STUDENT_H

#include <string>
// for header file, we will not using namespace to prevent name collision and colluted namespace
// for some companies you're not allowed to use namespace in main.cpp
// using namespace std;

class Course
{
private:
    int _enrollment = 0;
    std::string _title = "CSM101";

public:
    Course();                  // default constructor
    Course(const std::string); // parematerized
    std::string getTitle() const;
    int getEnrollment() const;
    void registrationStudent();
    void withdrawStudent();
};

#endif