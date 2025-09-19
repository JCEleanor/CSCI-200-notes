#include <iostream>
#include <random>
using namespace std;

int main()
{
    /**
     * @brief
     *
     * Select all possible missing pieces of code so the following code snippet will print out "0.5".
        int numer = 3, denom = 6;
        cout << __________ << endl;
     *
     */

    int numer = 3, denom = 6;
    cout << numer / denom << endl;
    cout << double(numer / denom) << endl;
    cout << double(numer) / denom << endl;
    cout << numer / double(denom) << endl;

    int i;
    for (i = 0; i < 8; i += 2)
    {
        ++i;
    }
    cout << "i: " << i << endl;

    return 0;
}