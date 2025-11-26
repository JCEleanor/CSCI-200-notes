#include "Coordinate.h"
#include "Quadrilateral.h"

/**
 * @brief
 * sets the number of vertices to be four and allocates the vertex array to hold four coordinates
 *
 */
Quadrilateral::Quadrilateral() : Polygon()
{
    this->numVertices = 4;
    this->vertices = new Coordinate[static_cast<std::size_t>(numVertices)];
    ;
}