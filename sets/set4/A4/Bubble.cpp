#include "Bubble.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>

float generateRandomFloat(float min, float max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(min, max);
    return dist(gen);
}

Bubble::Bubble()
{
    _circle.setRadius(10);
    _circle.setOutlineColor(sf::Color::Red);
    _circle.setOutlineThickness(5);
    // start in the middle of a 640x640 window
    _circle.setPosition({320.f, 320.f});

    // set the direction for the bubble's entire life
    _xDir = generateRandomFloat(-0.8f, 0.8f);
    _yDir = generateRandomFloat(-0.8f, 0.8f);

    // in case the random numbers are both zero
    if (_xDir == 0.f && _yDir == 0.f)
    {
        // give it a default rightward movement
        _xDir = 0.5f;
    }
}

void Bubble::draw(sf::RenderWindow &window) const
{
    window.draw(_circle);
}

void Bubble::updatePosition(sf::Vector2u windowSize)
{
    _circle.move({_xDir, _yDir});

    sf::Vector2f pos = _circle.getPosition();
    float radius = _circle.getRadius();

    if (pos.x < 0 || pos.x + (radius * 2) > windowSize.x)
    {
        _xDir *= -1; // reverse horizontal direction
    }

    if (pos.y < 0 || pos.y + (radius * 2) > windowSize.y)
    {
        _yDir *= -1; // reverse vertical direction
    }
}

float Bubble::getXDir() const { return _xDir; };
float Bubble::getYDir() const { return _yDir; };