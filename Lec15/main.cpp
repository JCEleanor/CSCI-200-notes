#include <iostream>

#include <fstream>

using namespace std;

int readFileUsingEOF()
{
    ifstream fin("./data.txt");

    if (fin.fail())
    {
        cerr << "Error opening file";
        return -1;
    }

    char c;
    while (!fin.eof())
    {
        fin.get(c);
        cout << "READ: " << c << endl;
    }

    fin.close();
    return 0;
}

int readFile()
{
    ifstream fin("./data.txt");

    if (fin.fail())
    {
        cerr << "Error opening file";
        return -1;
    }

    char c;
    while (fin >> c)
    {
        cout << "READ: " << c << endl;
    }

    fin.close();
    return 0;
}

int readFileUsingGetLine()
{
    fstream fin("./data.txt");

    if (fin.fail())
    {
        cerr << "Error opening file";
        return -1;
    }

    string line;
    while (getline(fin, line))
    {
        cout << line << endl;
    }

    fin.close();
    return 0;
}

int main()
{

    // readFileUsingEOF();
    // readFile();
    readFileUsingGetLine();
    return 0;

    // TODO: what to do if you want to append to the file? cuz every time you open it it erases the content
}
