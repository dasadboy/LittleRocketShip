#include "constants.h"

class Ship
{
    private:
        float radius;
        unsigned int health;
        sf::Texture texture;
        sf::CircleShape shipSprite;
        sf::Vector2f origin;
        sf::Vector2f vel;

    public:

        Ship();

        bool collides(sf::Vector2f& pixelPos);

        void boost(sf::Vector2f& accel);

        void decelerate();

        void draw(sf::RenderWindow& window);

};