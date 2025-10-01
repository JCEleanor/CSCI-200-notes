#include <iostream>

// 1. include the fstream library
#include <fstream>

using namespace std;

int main()
{
    // step 2 & 3: decalre and open the file
    ifstream fin;
    fin.open("data.txt"); // look for local dir

    ofstream fout;
    // what it's locked by some other program and we failed to access it?
    fout.open("output.txt");

    if (!fout)
    {
        cerr << "Error opening output file" << endl;
        return -1;
    }

    fout << "some text to dump into the output file" << endl;

    // step 2 & 3 in one line
    // ifstream fin("./data.txt")

    // step 4: handle error
    // (such as file 404, permission error, hit max limit...)
    if (fin.fail()) // or  if ( !fin ) or if (! f.is_open() )
    {
        // cerr and cout is the same
        cerr << "Error opening input file" << endl;
        return -1;
    }

    // step 5: read information from the file
    int num;
    double dnum;
    char c;

    fin >> num >> dnum >> c;
    cout << num << " " << dnum << " " << c << endl;
    fout << num << " " << dnum << " " << c << endl;

    fin.get(c); // read the \n and ignore

    for (int i = 0; i <= 4; i++)
    {
        fin.get(c); // c = (char)f.get() (this will return an ineger, so we have to type cast it into a char)
        cout << c;
        fout << c;
    }

    // step 6: close the file for both input/output
    fin.close();
    fout.close();

    return 0;
    // TODO: what to do if you want to append to the file? cuz every time you open it it erases the content
}
