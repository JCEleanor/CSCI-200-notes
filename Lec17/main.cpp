/* Lecture 17 - Collections
 * Vectors - STL templated list
 * Strings - list of characters
 */

#include <iostream>
#include <string>
#include <vector>

// Add includes for the collections being used in your file

using namespace std;

const int CLASS_SIZE = 3;

int main()
{
    cout << "Collections - Vectors and Strings \n\n";

    // Declare a vector specifying the data type for the list
    vector<int> cwidList;

    // Declare and initialize a vector, size is CLASS_SIZE and all are set to the same value
    vector<double> gpaList(CLASS_SIZE, 4.0);

    // Declare and initialize a string / A vector of strings
    vector<string> nameList(CLASS_SIZE);
    string name = "";

    // Loop to enter CWIDs and names
    int cwid;
    double gpa;

    for (int i = 0; i < CLASS_SIZE; i++)
    {
        // Get CWID
        cout << "Enter CWID: ";
        cin >> cwid;

        // Get GPA
        cout << "Enter GPA: ";
        cin >> gpa;

        // Get first name
        cout << "Enter First Name: ";
        cin >> name;

        // add elements to back of list and grow the list
        cwidList.push_back(cwid);

        // Set the element at a position
        // warning: implicit conversion changes signedness: 'int' to 'size_type' (aka 'unsigned long') [-Wsign-conversion]
        gpaList.at(i) = gpa;
        // warning: implicit conversion changes signedness: 'int' to 'size_type' (aka 'unsigned long') [-Wsign-conversion]
        nameList.at(i) = name;
    }

    // Display CWIDs, names and grades
    for (size_t i = 0; i < cwidList.size(); i++)
    {
        cout << cwidList.at(i) << " " << nameList.at(i) << " " << gpaList.at(i) << endl;
    }

    // Element access is protected -- Access element 100
    cout << cwidList[100] << endl; // don't do this
    // cout << cwidList << endl; // is for loop the only way to print out the vector?

    return 0;
}