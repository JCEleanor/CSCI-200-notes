/* CSCI 200: Lab 1A: Math Equation Solver
 *
 * Author: Eleanor Chiu
 *
 * More complete description here...
 */

// The include section adds extra definitions from the C++ standard library.
#include <cmath>    // For math
#include <iostream> // For cin, cout, etc.

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

// calculate distance from origin using d = √(x² + y²)
double calculateDistance(double x, double y)
{
    return sqrt(x * x + y * y);
}

// calculate volume of sphere using V = (4/3)πr³
double calculateSphereVolume(double r)
{
    return (4 / 3) * M_PI * r * r * r;
}

// get valid douuble from user input
double getValidDouble(const string prompt)
{
    double value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            return value;
        }
        else
        {
            cout << "Error: Please enter a valid number." << endl;
            // end the loop
            cin.clear();
        }
    }
}

// Must have a function named "main", which is the starting point of a C++ program.
int main()
{
    // Get x and y coordinates for distance calculation
    cout << "Let's calculate distance according to x and y coordinates:" << endl;
    double x = getValidDouble("Enter the x coordinate: ");
    double y = getValidDouble("Enter the y coordinate: ");
    double distance = calculateDistance(x, y);
    cout << "The distance is: " << distance << endl;
    cout << endl;

    // Get radius for sphere volume calculation
    cout << "Let's calculate sphere volume according to radius" << endl;
    double r = getValidDouble("Enter the radius: ");
    double volume = calculateSphereVolume(r);
    cout << "The sphere volume is: " << volume << endl;

    return 0; // signals the operating system that our program ended OK.
}
