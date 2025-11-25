#ifndef POLYGON_H
#define POLYGON_H

#include <SFML/Graphics.hpp>
#include "Coordinate.h"

class Polygon
{
public:
    Polygon();
    virtual ~Polygon();
    void setColor(sf::Color);
    void draw(sf::RenderTarget &window);
    // In UML, when a parameter is listed simply as type (e.g., Coordinate), it generally implies pass-by-value
    void setCoordinate(int index, const Coordinate &coordinate);
    virtual bool validate() = 0;

private:
    /** the color of the triangle as an SFML Color object */
    sf::Color color;

protected:
    /** the number of vertices making up the polygon as a short integer */
    short numVertices;
    /** a Coordinate array */
    Coordinate *vertices;
};

#endif // POLYGON_H