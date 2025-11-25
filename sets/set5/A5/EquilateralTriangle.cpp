#include <cmath>

#include "EquilateralTriangle.h"

/**
 * @brief Given the three vertex coordinates,
 * compute the length of each side.
 * If the three sides form a triangle
 * (that is - all three sides are non-zero and the sum of any two is greater than the third)
 * AND all three of the three sides are equal in length,
 * then return true.
 * If the sides do not form an equilateral triangle, return false.
 *
 * @return true
 * @return false
 */
bool EquilateralTriangle::validate()
{
    // step 1: use the helper from Triangle to perform common checks
    if (!this->isAValidTriangle())
    {
        return false;
    }

    // step 2: all three of the three sides are equal in length
    double side0 = getDistance(this->vertices[0], this->vertices[1]);
    double side1 = getDistance(this->vertices[0], this->vertices[2]);
    double side2 = getDistance(this->vertices[1], this->vertices[2]);

    const double EPSILON = 1e-9;

    if (std::abs(side0 - side1) < EPSILON &&
        std::abs(side0 - side2) < EPSILON)
    {
        return true;
    }
    else
    {
        return false;
    }
}