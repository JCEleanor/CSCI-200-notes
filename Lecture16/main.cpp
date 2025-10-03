#include <fstream>
#include <iostream>
using namespace std;

const int SENTINAL_VALUE = -9999;

int main()
{
  cout << "Hello World!" << endl;

  ifstream fin("data.txt");
  if (fin.fail())
  {
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

  int numLines, i1, i2;
  fin >> numLines;

  for (int i = 0; i < numLines; i++)
  {
    fin >> i1 >> i2;
    cout << i1 << i2;
  }

  // second reading paradigms: sentinal control loop
  // rule of thumb: chcek sentinal value before processing
  while (true)
  {
    fin >> i1;

    if (i1 == SENTINAL_VALUE)
    {
      cout << "END THE LOOP" << endl;
      break;
    }

    cout << i1 << endl;
  }

  // third reading paradigms: end-of file loop
  while (!fin.eof())
  {
    fin >> i1;
    cout << i1 << endl;
  }
  cout << "END THE LOOP" << endl;

  fin.close();

  return 0;
}
