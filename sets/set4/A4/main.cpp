#include <SFML/Graphics.hpp>
#include "Bubble.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// define constants for window dimensions
const unsigned int WINDOW_WIDTH = 640;
const unsigned int WINDOW_HEIGHT = 640;

int main()
{
    // create a window using the constants
    sf::Vector2u windowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Pop-A-Bubble");

    vector<Bubble> bubbles;
    for (int i = 0; i < 5; i++)
    {
        // pass the window size to the constructor
        bubbles.emplace_back(windowSize);
    }

    int score = 0;
    float gameTime = 10.f;
    bool gameOver = false;

    sf::Font font;
    if (!font.openFromFile("assets/Roboto_Condensed-Black.ttf"))
    {
        cout << "Error loading font" << endl;
        return -1;
    }

    sf::Text scoreText(font), ballsText(font), timeText(font), gameOverText(font);

    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition({10.f, 10.f});

    ballsText.setFont(font);
    ballsText.setCharacterSize(24);
    ballsText.setFillColor(sf::Color::White);
    ballsText.setPosition({10.f, 40.f});

    timeText.setFont(font);
    timeText.setCharacterSize(24);
    timeText.setFillColor(sf::Color::White);
    timeText.setPosition({10.f, 70.f});

    gameOverText.setFont(font);
    gameOverText.setCharacterSize(24);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setPosition({10.f, WINDOW_HEIGHT / 2.f});

    sf::Clock clock;
    const sf::Time timePerFrame = sf::seconds(1.f / 60.f);

    while (window.isOpen())
    {
        // step 1: handle events
        while (const std::optional event = window.pollEvent())
        {
            // case 1: close event
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            // case 2: keyboard event
            if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->code == sf::Keyboard::Key::Q || keyPressed->code == sf::Keyboard::Key::Escape)
                {
                    window.close();
                }

                if (gameOver && keyPressed->code == sf::Keyboard::Key::R)
                {
                    // reset
                    score = 0;
                    gameTime = 10.f;
                    gameOver = false;
                    gameOverText.setString("");
                    bubbles.clear();
                    for (int i = 0; i < 5; i++)
                    {
                        bubbles.emplace_back(windowSize);
                    }
                }

                if (!gameOver && keyPressed->code == sf::Keyboard::Key::Space)
                {
                    if (bubbles.size() < 10)
                    {
                        bubbles.emplace_back(windowSize);
                    }
                }
            }

            // case 3: mouse event
            if (!gameOver)
            {
                if (const auto *mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
                {
                    for (auto it = bubbles.begin(); it != bubbles.end();)
                    {
                        if (it->checkClicked(mouseButtonPressed->position.x, mouseButtonPressed->position.y))
                        {
                            it = bubbles.erase(it);
                            // increment score when bubble is clicked
                            score++;
                        }
                        else
                        {
                            ++it;
                        }
                    }
                }
            }
        }

        // step 2: update state
        if (clock.getElapsedTime() >= timePerFrame)
        {
            // only update if game is not over
            if (!gameOver)
            {
                // update timer
                gameTime -= timePerFrame.asSeconds();
                if (gameTime <= 0.f)
                {
                    gameTime = 0.f;
                    gameOver = true;

                    gameOverText.setString("Times up! Press Q or Esc to quit, or R to restart");
                    window.draw(gameOverText);
                }

                // update bubble positions
                for (Bubble &bubble : bubbles)
                {
                    bubble.updatePosition(windowSize);
                }
            }
            clock.restart();
        }

        // step 3: draw
        window.clear();

        // update text strings
        scoreText.setString("Score: " + std::to_string(score));
        ballsText.setString("Balls: " + std::to_string(bubbles.size()));
        timeText.setString("Time: " + std::to_string(static_cast<int>(ceil(gameTime))));

        // draw bubbles and text
        for (const Bubble &bubble : bubbles)
        {
            bubble.draw(window);
        }
        window.draw(scoreText);
        window.draw(ballsText);
        window.draw(timeText);
        window.draw(gameOverText);

        window.display();
    }
    return 0;
}