#include <cmath>

#include "Rhombus.h"

/**
 * @brief
 * Given the four vertex coordinates,
 * compute the length of each side.
 *  If the four sides form two isosceles triangles
 * (comprised of vertices 0, 1, 2 & 0, 2, 3) AND
 * all four of the four sides are equal in length, then return true.
 * If the sides do not form a rhombus, return false.
 * (Note: for this assignment, we can assume the points will form a simple polygon and the edges will not cross themselves.)
 *
 * @return true
 * @return false
 */
bool Rhombus::validate()
{
    double side01 = getDistance(this->vertices[0], this->vertices[1]);
    double side12 = getDistance(this->vertices[1], this->vertices[2]);
    double side23 = getDistance(this->vertices[2], this->vertices[3]);
    double side30 = getDistance(this->vertices[3], this->vertices[0]);

    // check 1: non zero
    const double EPSILON = 1e-9;
    if (side01 < EPSILON || side12 < EPSILON || side23 < EPSILON || side30 < EPSILON)
    {
        return false;
    }

    // check 2: four equal sides
    if (std::abs(side01 - side12) < EPSILON &&
        std::abs(side01 - side23) < EPSILON &&
        std::abs(side01 - side30) < EPSILON)
    {
        return true;
    }
    else
    {

        return false;
    }
}
