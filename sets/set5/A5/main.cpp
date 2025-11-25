
#include <fstream>
#include <iostream>

#include "Polygon.h"

using namespace std;

int main()
{
    try
    {

        ifstream fin("./polygon.dat");
        if (fin.fail())
        {
            // TODO: throw ifstream error
        }

        string line;
        while (getline(fin, line))
        {
            char polygonType = line[0];
            cout << polygonType << endl;
        }

        fin.close();
        return 0;
    }
    catch (...)
    {
        return -1;
    }
}