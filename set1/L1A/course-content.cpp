// header file, doing this at compile step
#include <iostream>

// TBD
// if don't use namespace std, you have to mention it everytime
// for example: std::cout << "23" <<
// safer? to use without namesapce
using namespace std;

// int main()
// {
//     cout << "hello world" << endl;

//     // python assume success
//     return 0;
// }

int main()
{
    float temp = 72.0f;

    // it's been stored as a number in the memory
    char letter = 'a';
    cout << " " << (int)letter << endl;

    // signed vs. unsigned
    signed int x = -1;   // 0xFFFFF...?
    unsigned int y = -1; // 0xFFFFF...?
    cout << x << endl;
    cout << y << endl;

    // cout << "Have";
    // cout << "a";
    // cout << " good" << " day";
    return 0;
}

/**
 * [compile]
 * preprocessing detavitives
 *
 *
 * [link]
 * main.cpp -> main.o, produce an object file
 * in this case, we're only linking the command lib iostream
 * g++ is also a linker
 *
 * [execute (or run)]
 *
 */

/**
 * math concern
 * overflow / underflow
 * short everest = 29032
 * short elbert = 14439
 * short total = everest + elbert
 *
 * precision issue -> how computer deals with float
 *
 */