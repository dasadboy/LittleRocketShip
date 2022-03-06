#pragma once
#include "constants.h"

class Ship
{
    private:
        float radius;
        unsigned int health;
        static sf::Texture texture;
        sf::CircleShape shipSprite;
        float velocity;
        float angleInRad;
        sf::Vector2f pos;

    public:

        Ship();

        static int loadTexture() {
            if (!Ship::texture.loadFromFile(SHIP_CONSTS::PATH_TO_TEXTURE))
            {
                std::cout << "Texture file '" + SHIP_CONSTS::PATH_TO_TEXTURE + "' could not be loaded";
                return STATUS_CODES::FILE_NOT_FOUND;
            }
            Ship::texture.setSmooth(true);
            return 0;
        }

        bool collides(const sf::Vector2f& pixelPos) const;

        void rotateShip(float rad);

        void move(float dx);

        void setVelocityVector(float vel, float angle);

        float getAngleInRadians() const;

        sf::Vector2f getPosition() const;

        void reset();

        void draw(sf::RenderWindow& window);

};