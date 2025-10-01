#ifndef COORDINATE_CONVERSION_H
#define COORDINATE_CONVERSION_H

/**
 * @brief Converts polar (r, theta) to cartesian (x, y).
 * Input:
    double passed by constant value corresponding to the radius
    double passed by constant value corresponding to the angle
    double passed by pointer corresponding to the xCoordinate
    double passed by pointer corresponding to the yCoordinate
    Output: None
 */
void polar_to_cartesian(const double radius, const double angle, double *xCoord, double *yCoord);

/**
 * @brief Converts cartesian (x, y) to polar (r, theta).
 * Input:
    double passed by constant value corresponding to the xCoordinate
    double passed by constant value corresponding to the yCoordinate
    double passed by pointer corresponding to the radius
    double passed by pointer corresponding to the angle
    Output: None
 */
void cartesian_to_polar(double xCoord, double yCoord, double *radius, double *angle);

#endif