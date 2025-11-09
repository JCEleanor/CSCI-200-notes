#include <SFML/Graphics.hpp>

class Bubble
{
public:
    Bubble() {};
    ~Bubble() {};
    void draw(sf::RenderWindow &window);

private:
    /**
     * @brief the circle shape of the bubble
     */
    sf::CircleShape _circle;
    float _xDir;
    float _yDir;
};