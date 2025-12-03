#include <iostream>
#include <cmath>

#include <SFML/Graphics.hpp>

int main()
{
    // place anything that happens once (such as file I/O) outside of window loop

    // TODO #1
    sf::Vector2u winndowSize(640, 640);
    sf::RenderWindow window(sf::VideoMode(winndowSize), "Window Title");

    // TODO #3
    while (window.isOpen())
    {

        window.clear(sf::Color(155, 0, 255));

        // TODO #6
        sf::CircleShape circ;
        circ.setRadius(20.f);
        circ.setPosition(sf::Vector2f(45.f, 90.f));
        circ.setFillColor(sf::Color::Yellow);
        window.draw(circ);

        // TODO #7
        sf::RectangleShape rect;
        rect.setSize(sf::Vector2f(150.f, 75.f));
        rect.setPosition(sf::Vector2f(115.f, 120.f));
        rect.setFillColor(sf::Color::Blue);
        window.draw(rect);

        // TODO #9:

        // for (float i =0.f; i<-3.14f; )

        // TODO #10

        // TODO #2:

        window.display();

        // TODO #5
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
    }

    // TODO #4

    return EXIT_SUCCESS;
}