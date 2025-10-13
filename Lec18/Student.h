#ifndef STUDENT_H
#define STUDENT_H

#include <string>
// for header file, we will not using namespace to prevent name collision and colluted namespace
// for some companies you're not allowed to use namespace in main.cpp
// using namespace std;

class Student
{
    // for naming convention, a prefix _
private: // access control
    double gpa;
    int cwid;
    std::string name;

public: // access cosntrol
    // constructor
    Student(); // default constructor
    // for the string you prob want to pass by reference
    Student(const int C, const double G, const std::string N); // parameterized constructor
    void printInfo();
    // getters are constant functions, it will change member data
    double getGPA() const;
    void setGPA(const double G);
};

#endif