#include "Student.h"
#include <iostream>

using namespace std;

int main()
{
    // the design of c++ is to try to push everything into the compiling process so that code runs as fast as possible
    Student ana(1, 2.2, "ana");
    // set member data
    // ana.cwid = 1;
    // ana.gpa = 3.9;

    // cout << "Enter a name: ";
    // cin >> ana.name;

    // Undefined symbols for architecture x86_64: i think it's bc of makefile
    ana.printInfo();

    // random point in memory or default value
    Student bob;
    bob.printInfo();

    // implicitly or explicitly call the constructor
    Student carie(010, 3, "carie");
    // carie.gpa = 5.5;
    carie.setGPA(5.5);
    Student eleanor = Student(123, 4, "eleanor");

    carie.printInfo();
    return 0;
}