#include <SFML/Graphics.hpp>
#include "Bubble.h"
#include <iostream>
using namespace std;

int main()
{
    // create a window
    sf::Vector2u windowSize(640, 640);
    sf::RenderWindow window(sf::VideoMode(windowSize), "A House");

    // create Bubble
    Bubble bubble;

    while (window.isOpen())
    {
        window.clear();
        bubble.draw(window);

        // bubble.draw(window);

        window.display();
        while (const std::optional event = window.pollEvent())
        {
            // if event type corresponds to pressing window X
            if (event->is<sf::Event::Closed>())
            {
                // tell the window to close
                window.close();
            }
            // check additional event types to handle additional events
        }
    }

    return 0;
}