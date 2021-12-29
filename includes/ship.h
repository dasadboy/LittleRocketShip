#include "constants.h"

class Ship
{
    private:
        float radius;
        unsigned int health;
        sf::Texture texture;
        sf::CircleShape shipSprite;
        float vel;

    public:

        Ship();

        int loadTexture();

        bool collides(sf::Vector2f& pixelPos) const;

        void trackMouse(float deg);

        void move(float dx);

        float getAngle() const;

        sf::Vector2f getPosition() const;

        void draw(sf::RenderWindow& window);

};