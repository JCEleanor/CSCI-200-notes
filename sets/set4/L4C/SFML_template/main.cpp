#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;

int main()
{
    // create a window
    sf::Vector2u windowSize(640, 640);
    sf::RenderWindow window(sf::VideoMode(windowSize), "A House");

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING

    // perform any file processing once before draw loop begins

    //  END  ANY FILE LOADING
    /////////////////////////////////////

    // while the window is open
    while (window.isOpen())
    {
        // clear any existing contents
        window.clear();

        /////////////////////////////////////
        // BEGIN DRAWING HERE

        // House Body
        sf::RectangleShape houseBody(sf::Vector2f(200, 200));
        houseBody.setPosition(sf::Vector2f(220.f, 300.f));
        houseBody.setFillColor(sf::Color(139, 69, 19)); // Brown

        // Roof
        sf::CircleShape roof(142, 3);
        roof.setPosition(sf::Vector2f(173.f, 100.f));
        roof.setFillColor(sf::Color(255, 0, 0)); // Red

        // Door
        sf::RectangleShape door(sf::Vector2f(50, 80));
        door.setPosition(sf::Vector2f(295.f, 420.f));
        door.setFillColor(sf::Color(165, 42, 42)); // Sienna

        // Windows
        sf::RectangleShape window1(sf::Vector2f(40, 40));
        window1.setPosition(sf::Vector2f(240.f, 350.f));
        window1.setFillColor(sf::Color::Cyan);

        sf::RectangleShape window2(sf::Vector2f(40, 40));
        window2.setPosition(sf::Vector2f(360.f, 350.f));
        window2.setFillColor(sf::Color::Cyan);

        window.draw(houseBody);
        window.draw(roof);
        window.draw(door);
        window.draw(window1);
        window.draw(window2);

        //  END  DRAWING HERE
        /////////////////////////////////////

        // display the current contents of the window
        window.display();

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE
        // check if any events happened since the last time checked
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
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////

        /////////////////////////////////////
        // BEGIN ANIMATION UPDATING HERE

        //  END  ANIMATION UPDATING HERE
        /////////////////////////////////////
    }

    return 0;
}