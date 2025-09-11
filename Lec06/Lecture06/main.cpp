/*
 * CSCI 200: Lecture 06: Compiler Messages and The Debugger
 *
 * Author: Dr. Jeffrey Paone
 *
 *    This program illustrates a variety of common loop errors.
 *    Fix the errors in each section.
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

const float PI = 3.141f;

int main()
{
  int x = 4;
  cout << "Line #" << __LINE__ << " -> x = " << x << endl;
  // int z = 5;
  int y = 3;

  if (true)
  {
    cout << "Line #" << __LINE__ << " -> x = " << x << endl;
  }

  if (x == 2)
  {
    cout << "Enter x: ";
    cin >> x;
  }

  cout << "Line #" << __LINE__ << " -> x = " << x << endl;

  if (x < 0)
  {
    return -1;
  }

  cout << y << endl;

  cout << "Ready to go?  Enter a positive integer to be praised (zero is a good test): ";
  cin >> x;

  if (x >= 0)
  {
    cout << "Thanks for following directions, " << x << " is indeed positive!" << endl;
  }

  cout << "Time to countdown to zero and blast off!" << endl;
  for (unsigned short counter = 10; counter >= 0; --counter)
  {
    if (counter == 0)
    {
      cout << "BLAST OFF!" << endl;
    }
  }
  cout << "Good luck in space!" << endl;

  return 0;
}