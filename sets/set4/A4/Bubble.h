#include <SFML/Graphics.hpp>

class Bubble
{
public:
    Bubble(sf::Vector2u windowSize);
    ~Bubble() {};
    void draw(sf::RenderWindow &window) const;
    void updatePosition(sf::Vector2u windowSize);
    float getXDir() const;
    float getYDir() const;
    bool checkClicked(float mouseX, float mouseY) const;

private:
    /**
     * @brief the circle shape of the bubble
     */
    sf::CircleShape _circle;
    float _xDir;
    float _yDir;
};