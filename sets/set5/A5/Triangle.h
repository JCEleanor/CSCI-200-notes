#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.h"

// public inheritance
class Triangle : public Polygon
{
public:
    Triangle();

protected:
    // helper function to check for common triangle properties
    bool isAValidTriangle() const;
};

#endif // TRIANGLE_H