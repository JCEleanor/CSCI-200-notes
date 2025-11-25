#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <SFML/Graphics.hpp>
#include "Coordinate.hpp"

class Polygon
{
public:
    Polygon();
    virtual ~Polygon();
    void setColor(sf::Color);
    void draw(sf::RenderWindow &);
    // In UML, when a parameter is listed simply as type (e.g., Coordinate), it generally implies pass-by-value
    void setCoordinate(int index, const Coordinate &coordinate);
    virtual bool validate() = 0;

private:
    sf::Color color;

protected:
    short numVertices;
    Coordinate *vertices;
};

#endif // POLYGON_HPP