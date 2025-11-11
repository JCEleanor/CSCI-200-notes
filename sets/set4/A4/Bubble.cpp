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

int generateRandomInt(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

Bubble::Bubble()
{
    // give each Bubble a random radius between 10 and 50.
    int circleRadius = generateRandomInt(10, 50);
    _circle.setRadius(circleRadius);

    // give each Bubble a random color so we can tell them apart.
    int r = generateRandomInt(0, 255);
    int g = generateRandomInt(0, 255);
    int b = generateRandomInt(0, 255);
    _circle.setFillColor(sf::Color(static_cast<uint8_t>(r), static_cast<uint8_t>(g), static_cast<uint8_t>(b)));

    // TODO: change window size to global var
    // give each Bubble a random starting position for X and Y so the bubble will be created within the window and not on an edge.
    _circle.setPosition({generateRandomFloat(0.f, 640.f - (2 * circleRadius)), generateRandomFloat(0.f, 640.f - (2 * circleRadius))});

    // set a random direction for X and Y in the range [-0.8, +0.8] for the bubble's entire life.
    _xDir = generateRandomFloat(-0.8f, 0.8f);
    _yDir = generateRandomFloat(-0.8f, 0.8f);

    if (_xDir == 0.f)
    {
        _xDir = 0.5f;
    }

    if (_yDir == 0.f)
    {
        _yDir = 0.5f;
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