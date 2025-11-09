#include "Bubble.h"
#include <SFML/Graphics.hpp>

void Bubble::draw(sf::RenderWindow &window)
{

    _circle.setRadius(150);
    _circle.setOutlineColor(sf::Color::Red);
    _circle.setOutlineThickness(5);
    _circle.setPosition({10, 20});
    window.draw(_circle);
}