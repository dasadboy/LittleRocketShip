#pragma once
#include "constants.h"

class Ship
{
    private:
        float radius;
        unsigned int health;
        static sf::Texture texture;
        sf::CircleShape shipSprite;
        float vel;

    public:

        Ship();

        static int loadTexture() {
            if (!Ship::texture.loadFromFile(SHIP_CONSTS::PATH_TO_TEXTURE))
            {
                throw "Texture file '" + SHIP_CONSTS::PATH_TO_TEXTURE + "' could not be loaded";
                return ERROR_CODES::FILE_NOT_FOUND;
            }
            Ship::texture.setSmooth(true);
            return 0;
        }

        bool collides(sf::Vector2f& pixelPos) const;

        void trackMouse(float deg);

        void move(float dx);

        float getAngle() const;

        sf::Vector2f getPosition() const;

        void draw(sf::RenderWindow& window);

};