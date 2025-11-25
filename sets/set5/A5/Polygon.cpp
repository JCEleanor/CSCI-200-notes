#include "Polygon.h"
/**
 * @brief Construct a new Polygon:: Polygon object
 * default constructor -
 * sets the color to white,
 * specifies the number of vertices as 0,
 * sets the vertices array to be a nullptr
 */
Polygon::Polygon()
{
    this->color = sf::Color::White;
    this->numVertices = 0;
    this->vertices = nullptr;
}

/**
 * @brief
 * deallocate the vertices array
 */
Polygon::~Polygon()
{
    delete[] this->vertices;
    this->vertices = nullptr;
}

/**
 * @brief sets the private color data member
 *
 */
void Polygon::setColor(sf::Color color)
{
    this->color = color;
}

/**
 * @brief
 * creates a ConvexShape, sets the points for each coordinate,
 * sets the fill color, draws it to the provided window
 * @param window
 */
void Polygon::draw(sf::RenderTarget &window)
{
    sf::ConvexShape convexShape;
    convexShape.setPointCount(this->numVertices);
    convexShape.setFillColor(this->color);

    for (short i = 0; i < numVertices; i++)
    {
        sf::Vector2f point(vertices[i].x, vertices[i].y);
        convexShape.setPoint(i, point);
    }

    window.draw(convexShape);
}

/**
 * @brief sets the corresponding coordinate in the vertices array
 *
 * @param index
 * @param coordinate
 */
void Polygon::setCoordinate(int index, const Coordinate &coordinate)
{
    this->vertices[index] = coordinate;
}
