/* CSCI 200: Lec07 - Functions
 *
 * Author: XXXX (_INSERT_YOUR_NAME_HERE_)
 *
 * Learning about functions in C++
 */

#include <iostream>
using namespace std;



int main() {
    int length(20), width(11), height(9), boxVolume;
    boxVolume = length * width * height;
    cout << "The volume is " << boxVolume << endl;
    length = length + 5;
    boxVolume = length * width * height;
    cout << "The new volume is " << boxVolume << endl;
    return 0;
}