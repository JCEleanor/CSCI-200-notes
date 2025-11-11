#include <SFML/Graphics.hpp>
#include "Bubble.h"
#include <iostream>
#include <vector>

using namespace std;

// define constants for window dimensions
const unsigned int WINDOW_WIDTH = 640;
const unsigned int WINDOW_HEIGHT = 640;

int main()
{
    // create a window using the constants
    sf::Vector2u windowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "A House");

    vector<Bubble> bubbles;
    for (int i = 0; i < 5; i++)
    {
        // pass the window size to the constructor
        bubbles.emplace_back(windowSize);

        // emplace_back is more efficient than push_back because
        // it takes the constructor arguments for the object you want to create
        // and then constructs that object directly within the vector's memory
        // it avoids the overhead of creating a temporary object and
        //  then copying or moving it into the vector.
        // bubbles.push_back(Bubble());
    }

    sf::Clock clock;
    const sf::Time timePerFrame = sf::seconds(1.f / 60.f);

    while (window.isOpen())
    {
        // step 1: handle events
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                // presses the Q or Escape key, automatically close the window.
                if (keyPressed->code == sf::Keyboard::Key::Q || keyPressed->code == sf::Keyboard::Key::Escape)
                {
                    window.close();
                }

                // is press spacebar, generate a bubble. Allow up to 10
                if (keyPressed->code == sf::Keyboard::Key::Space)
                {
                    if (bubbles.size() < 10)
                    {
                        bubbles.emplace_back(windowSize);
                    }
                }
            }

            if (const auto *mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
            {
                for (auto it = bubbles.begin(); it != bubbles.end();)
                {
                    if (it->checkClicked(mouseButtonPressed->position.x, mouseButtonPressed->position.y))
                    {
                        it = bubbles.erase(it);
                    }
                    else
                    {
                        ++it;
                    }
                }
            }
        }

        // step 2: update state
        if (clock.getElapsedTime() >= timePerFrame)
        {
            for (Bubble &bubble : bubbles)
            {
                bubble.updatePosition(windowSize);
            }

            clock.restart();
        }

        // step 3: draw
        window.clear();
        for (const Bubble &bubble : bubbles)
        {
            bubble.draw(window);
        }
        window.display();
    }
    return 0;
}