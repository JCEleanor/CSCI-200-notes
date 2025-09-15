/* CSCI 200: Lec07 - Functions
 *
 * Author: XXXX (_INSERT_YOUR_NAME_HERE_)
 *
 * Learning about functions in C++
 */

#include <iostream>
using namespace std;

/**
 * @brief
 *
 * @param length
 * @param width
 * @param height
 * @return int
 */
int compute_value(int length, int width, int height)
{
    int value = length * width * height;
    return value;
}

int main()
{
    // int length(20) is like directly putting value into the constructor, because int is a class underneath
    int length(20), width(11), height(9), boxVolume;
    boxVolume = length * width * height;
    cout << "The volume is " << boxVolume << endl;
    length = length + 5;
    boxVolume = length * width * height;
    cout << "The new volume is " << boxVolume << endl;
    return 0;
}

// int i;
// for (i = 0; i < 8; i += 2)
// {
//     ++i;
// }
// cout << i;