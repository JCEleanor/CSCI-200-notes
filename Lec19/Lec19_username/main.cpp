#include "Course.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{

    vector<string> courses;
    // create vector of courses
    for (int i = 0; i < 3; i++)
    {
        string name;
        cout << "Enter course name: " << endl;
        cin >> name;
        courses.push_back(name);
    }

    // loop thru the array
    // for
    return 0;
}