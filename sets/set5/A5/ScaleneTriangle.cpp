#include "ScaleneTriangle.h"
#include "Coordinate.h"
#include <cmath>

bool ScaleneTriangle::validate()
{
    // step 1: use the helper from Triangle to perform common checks
    if (!this->isAValidTriangle())
    {
        return false;
    }

    double side0 = this->getDistance(vertices[0], vertices[1]);
    double side1 = this->getDistance(vertices[0], vertices[2]);
    double side2 = this->getDistance(vertices[1], vertices[2]);

    const double EPSILON = 1e-9;

    // step 2: specific check for scalene triangle
    // all three side lengths are different
    if (std::abs(side0 - side1) < EPSILON ||
        std::abs(side0 - side2) < EPSILON ||
        std::abs(side1 - side2) < EPSILON)
    {
        return false;
    }

    return true;
}
