#include <cmath>

#include "Coordinate.h"
#include "Triangle.h"

/**
 * @brief check if three sizes are non-zero & the sum of any two is greater than the third
 *
 */
bool Triangle::isAValidTriangle() const
{
    double side0 = getDistance(vertices[0], vertices[1]);
    double side1 = getDistance(vertices[0], vertices[2]);
    double side2 = getDistance(vertices[1], vertices[2]);

    const double EPSILON = 1e-9;

    // check 1: all three sides are non-zero
    if (side0 < EPSILON || side1 < EPSILON || side2 < EPSILON)
    {
        return false;
    }

    // check 2: the sum of any two is greater than the third
    if (side0 + side1 <= side2 || side0 + side2 <= side1 || side1 + side2 <= side0)
    {
        return false;
    }

    return true;
}

Triangle::Triangle() : Polygon()
{
    this->numVertices = 3;
    this->vertices = new Coordinate[numVertices];
}
