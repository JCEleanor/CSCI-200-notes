#include <SFML/Graphics.hpp>
#include "Bubble.h"
#include <iostream>

using namespace std;

int main()
{
    // create a window
    sf::Vector2u windowSize(640, 640);
    sf::RenderWindow window(sf::VideoMode(windowSize), "A House");

    vector<Bubble> bubbles;
    for (int i = 0; i < 5; i++)
    {
        // emplace_back is more efficient than push_back because
        // it takes the constructor arguments for the object you want to create
        // and then constructs that object directly within the vector's memory
        // it avoids the overhead of creating a temporary object and
        //  then copying or moving it into the vector.
        bubbles.emplace_back();
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

            // is press spacebar, generate a bubble. Allow up to 10
            if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->code == sf::Keyboard::Key::Space)
                {
                    if (bubbles.size() < 10)
                    {
                        bubbles.emplace_back();
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