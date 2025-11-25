#ifndef ISOSCELESTRIANGLE_HPP
#define ISOSCELESTRIANGLE_HPP

#include "Triangle.hpp"

class IsoscelesTriangle : public Triangle
{
public:
    bool validate() override;
};

#endif // ISOSCELESTRIANGLE_HPP
