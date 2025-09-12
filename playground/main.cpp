#include <iostream>
#include <random>
using namespace std;

int main()
{
    int x = 0;
    int b = x++;
    int c = ++x;

    cout << "x: " << x << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;

    return 0;
}