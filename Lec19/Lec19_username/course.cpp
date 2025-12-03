#include "Course.h"
#include <iostream>

using namespace std;

// default
Course::Course()
{
    _title = "CSM101";
}
// paremeterized
Course::Course(const std::string INPUT)
{
    Course::_title = INPUT;
}
std::string Course::getTitle() const
{
    return _title;
}

int Course::getEnrollment() const
{
    return _enrollment;
}

void Course::registrationStudent()
{
    // TODO: check negative
    Course::_enrollment += 1;
}
void Course::withdrawStudent()
{
    // TODO: check negative
    Course::_enrollment -= 1;
}
