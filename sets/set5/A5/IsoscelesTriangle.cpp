#include <cmath>

#include "IsoscelesTriangle.h"

/**
 * @brief Given the three vertex coordinates, compute the length of each side.
 * If the three sides form a triangle
 * (that is - all three sides are non-zero and the sum of any two is greater than the third)
 *  AND
 *  at least two of the three sides are equal in length,
 *  then return true. If the sides do not form an isosceles triangle, return false.
 *
 * @return true
 * @return false
 */
bool IsoscelesTriangle::validate()
{
    // step 1: use the helper from Triangle to perform common checks
    if (!this->isAValidTriangle())
    {
        return false;
    }

    // step 2: at least two of the three sides are equal in length
    double side0 = getDistance(this->vertices[0], this->vertices[1]);
    double side1 = getDistance(this->vertices[0], this->vertices[2]);
    double side2 = getDistance(this->vertices[1], this->vertices[2]);

    const double EPSILON = 1e-9;
    if (std::abs(side0 - side1) < EPSILON ||
        std::abs(side0 - side2) < EPSILON ||
        std::abs(side1 - side2) < EPSILON)
    {
        return true;
    }
    else
    {

        return false;
    }
}