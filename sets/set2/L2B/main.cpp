/* CSCI 200: Fix Loop and Function Errors
 *
 * Author: Eleanor
 *
 *
 * Copyright 2025 Dr. Jeffrey Paone
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include <iostream>
using namespace std;

int main()
{
    //  Declare two integers named iNum and iNum2 with initial values 4 and 5 respectively.
    int iNum = 4;
    int iNum2 = 5;

    // Declare two pointers to integers named pINum1 and pINum2 both with initial value nullptr.
    int *pINum1 = nullptr;
    int *pINum2 = nullptr;

    // Assign the address of iNum to pINum1.
    pINum1 = &iNum;
    // Assign the address of iNum2 to pINum2.
    pINum2 = &iNum2;

    // Output the address of iNum and be sure to identify to the user what you are displaying. There are two ways you can do this; you should do both, to convince yourself they are the same.
    cout << "iNum address (&iNum): " << &iNum << endl;
    cout << "iNum address (pINum1): " << pINum1 << endl;

    // Output the address of iNum2 and be sure to identify to the user what you are displaying. There are two ways you can do this; you should do both, to convince yourself they are the same.
    cout << "iNum2 address (&iNum2): " << &iNum2 << endl;
    cout << "iNum2 address (pINum2): " << pINum2 << endl;

    // Use pINum1 to display the value of iNum.
    cout << "pINum1 value: " << *pINum1 << endl;
    // Use pINum2 to display the value of iNum2.
    cout << "pINum2 value: " << *pINum2 << endl;

    // Directly change the value of iNum to 6.
    iNum = 6;

    // Use iNum to output the value of iNum.
    cout << "iNum value: " << iNum << endl;

    // Use pINum1 to output the value of iNum.
    cout << "iNum value: " << *pINum1 << endl;

    // Use pINum1 to change the value it is pointing at to 7.
    *pINum1 = 7;

    // Use iNum to output the value of iNum.
    cout << "iNum value: " << iNum << endl;

    // Assign pINum2 to have the same value as pINum1. Do not reference iNum; instead use the address stored in pINum1.
    pINum2 = pINum1;

    // Output the value of pINum2.  This should be the same as displayed in step 5.
    cout << "pINum2 address: " << pINum2 << endl;

    // Output the value pointed to by pINum2.
    cout << "value pointed to by pINum2: " << *pINum2 << endl;

    // Using pINum2, change the value it is pointing at to 8.
    *pINum2 = 8;

    // Output the value of iNum three times, first using pINum1, then using pINum2, then iNum directly. In each case, identify what the user is seeing appropriately.
    cout << "iNum value using pINum1: " << *pINum1 << endl;
    cout << "iNum value using pINum2: " << *pINum2 << endl;
    cout << "iNum value directly: " << iNum << endl;

    // Output the value of iNum2. It should remain unchanged from the initial value.
    cout << "iNum2 value: " << iNum2 << endl;

    // Declare a pointer to a double named pDNum with initial value nullptr.
    double *pDNum = nullptr;

    // Try to assign the address of iNum to pDNum. Compile your program. What error message do you see? Comment out this bad line of code, but include the error message as a comment with this line.
    // pDNum = &iNum;
    // main.cpp:101:13: error: incompatible pointer types assigning to 'double *' from 'int *'

    // Try to assign the value of pINum1 to pDNum. Compile your program. What error message do you see? Comment out this bad line of code, but include the error message as a comment with this line.
    // pDNum = *pINum1;
    // main.cpp:105:13: error: incompatible integer to pointer conversion assigning to 'double *' from 'int'

    // Declare a double named dNum with initial value 14.25.
    double dNum = 14.25;

    // Assign the address of dNum to pDNum.
    pDNum = &dNum;
    // Output the address and then the value of dNum using pDNum for both.
    cout << "dNum address using pDNum: " << pDNum << endl;
    cout << "dNum value using pDNum: " << *pDNum << endl;

    // Try to assign the value pINum1 is pointing at to the value pDNum is pointing at.
    *pDNum = *pINum1;
    // Output the value of dNum two times, first using dNum then using pDNum.
    cout << "dNum value using dNum: " << dNum << endl;
    cout << "dNum value using pDNum: " << *pDNum << endl;

    return 0;
}