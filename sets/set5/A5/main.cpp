
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Polygon.h"
#include "Coordinate.h"
#include "Triangle.h"
#include "Quadrilateral.h"
#include "ScaleneTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Rhombus.h"

using namespace std;

int main()
{
    vector<Polygon *> polygons;
    try
    {
        /**
         * @brief
         *
         * Where each value is:
            T - a char denoting the polygon type. One of S, I, E, or R
            x1 - the double x coordinate for vertex 1
            y1 - the double t coordinate for vertex 1
            x2 - the double x coordinate for vertex 2
            y2 - the double t coordinate for vertex 2
            x3 - the double x coordinate for vertex 3
            y3 - the double t coordinate for vertex 3
            x4 - the double x coordinate for vertex 4 (will only be present if type is R)
            y4 - the double t coordinate for vertex 4 (will only be present if type is R)
            r - the int red component of the color
            g - the int green component of the color
            b - the int blue component of the color
         *
         */
        ifstream fin("./polygons.dat");
        if (fin.fail())
        {
            std::cerr << "Error: Could not open polygons.dat" << std::endl;
            return -1;
        }

        string line;
        while (getline(fin, line))
        {
            stringstream ss(line);
            char polygonType;
            ss >> polygonType;
            Polygon *p = nullptr;
            double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0, x4 = 0.0, y4 = 0.0;
            int r = 0, g = 0, b = 0;

            // case 1: triangle
            if (polygonType == 'S' || polygonType == 'I' || polygonType == 'E')
            {

                ss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> r >> g >> b;
                switch (polygonType)
                {
                case 'S':
                    p = new ScaleneTriangle();
                    break;
                case 'I':
                    p = new IsoscelesTriangle();
                    break;
                case 'E':
                    p = new EquilateralTriangle();
                    break;
                }

                if (p != nullptr)
                {
                    p->setCoordinate(0, Coordinate(x1, y1));
                    p->setCoordinate(1, Coordinate(x1, y1));
                    p->setCoordinate(2, Coordinate(x1, y1));
                }
            }
            // case 2: quadrilaterals (rhombus)
            else if (polygonType == 'R')
            {
                ss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> r >> g >> b;
                p = new Rhombus();
                if (p != nullptr)
                {
                    p->setCoordinate(0, Coordinate(x1, y1));
                    p->setCoordinate(1, Coordinate(x2, y2));
                    p->setCoordinate(2, Coordinate(x3, y3));
                    p->setCoordinate(3, Coordinate(x4, y4));
                }
            }

            if (p != nullptr)
            {
                if (p->validate())
                {
                    p->setColor(sf::Color(r, g, b));
                    polygons.push_back(p);
                }
                else
                {
                    std::cout << "polygon is invalid - \"" << line << "\"" << std::endl;
                    // clean up
                    delete p;
                    p = nullptr;
                }
            }
        }

        fin.close();

        sf::RenderWindow window(sf::VideoMode({800, 600}), "Polygon Land");
        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                }
            }

            // step 3: draw
            window.clear();
            for (const auto &polygon : polygons)
            {
                polygon->draw(window);
            }

            window.display();
        }

        return 0;
    }
    catch (...)
    {
        return -1;
    }
}