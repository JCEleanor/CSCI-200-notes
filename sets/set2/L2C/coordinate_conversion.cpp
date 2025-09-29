
#include <cmath>
#include "coordinate_conversion.h"

void polar_to_cartesian(const double radius, const double angle, double *xCoord, double *yCoord)
{
    *xCoord = radius * cos(angle);
    *yCoord = radius * sin(angle);
}

void cartesian_to_polar(double xCoord, double yCoord, double *radius, double *angle)
{
    *radius = sqrt(xCoord * xCoord + yCoord * yCoord);
    *angle = atan2(yCoord, xCoord);
}