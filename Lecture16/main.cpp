#include <fstream>
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    ifstream fin("data.txt");
    if( fin.fail() ) {
      cerr << "Could not open data.txt" << endl;
      return -1;
    }

    int value1, value5;
    double value2;
    char value3, value4;
    fin >> value1 >> value2 >> value3 >> value4 >> value5;

    cout << "Read: \"" << value1 << "\" \"" 
                       << value2 << "\" \""
                       << value3 << "\" \""
                       << value4 << "\" \""
                       << value5 << "\"" << endl;

    fin.close();

    return 0;
}
