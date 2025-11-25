#ifndef SCALENETRIANGLE_HPP
#define SCALENETRIANGLE_HPP

#include "Triangle.hpp"

class ScaleneTriangle : public Triangle
{
public:
    bool validate() override;
};

#endif // SCALENETRIANGLE_HPP