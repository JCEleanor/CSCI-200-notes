/* CSCI 200: Pass-by-Value & Pass-by-Pointer
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

#include "coordinate_conversion.h"

// void polar_to_cartesian(const double radius, const double angle, double *xCoord, double *yCoord)
// {
//     *xCoord = radius * cos(angle);
//     *yCoord = radius * sin(angle);
// }

// void cartesian_to_polar(double xCoord, double yCoord, double *radius, double *angle)
// {
//     *radius = sqrt(xCoord * xCoord + yCoord * yCoord);
//     *angle = atan2(yCoord, xCoord);
// }

/**
 * @brief https://cs-courses.mines.edu/csci200/labs/lab2c.html
 * covert Polar to Cartesian or convert Cartesian to Polar
 * @return int
 */
int main()
{

    int userInput;
    cout << "Enter 1 to covert Polar to Cartesian or 2 to convert Cartesian to Polar: ";
    cin >> userInput;

    if (userInput == 1)
    {
        double radius, angle, xCoord, yCoord;

        cout << "Enter radius: ";
        cin >> radius;
        cout << "Enter angle: ";
        cin >> angle;

        polar_to_cartesian(radius, angle, &xCoord, &yCoord);
        cout << "Cartesian coordinate is " << "(" << xCoord << " , " << yCoord << ")" << endl;
    }
    else if (userInput == 2)
    {
        double radius, angle, xCoord, yCoord;

        cout << "Enter x coordinate: ";
        cin >> xCoord;
        cout << "Enter y coordinate: ";
        cin >> yCoord;

        cartesian_to_polar(xCoord, yCoord, &radius, &angle);
        cout << "Polar coordinate is " << "(" << radius << " , " << angle * 180.0 / M_PI << " degrees)" << endl;
    }
    else
    {
        cout << "Please enter 1 or 2";
        return 1;
    }

    return 0;
}