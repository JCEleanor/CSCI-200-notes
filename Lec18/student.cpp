#include "Student.h"
#include <iostream>

using namespace std;

Student::Student()
{
    cwid = 1111;
    gpa = 4.0;
    name = "no name";
}

Student::Student(const int C, const double G, const std::string N)
{
    cwid = C;

    if (G < 0 || G > 4)
    {
        gpa = 4.0;
    }
    else
    {
        gpa = G;
    }
    name = N;
}

void Student::printInfo()
{
    cout << "CWID: " << cwid << " gpa: " << gpa << " name: " << name << endl;
}

void Student::setGPA(const double G)
{
    if (G < 0 || G > 4)
    {
        gpa = 4.0;
    }
    else
    {
        gpa = G;
    }
}

double Student::getGPA() const
{
    return gpa;
}
