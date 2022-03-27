#pragma once
#include "constants.h"

#define RADTODEGREES(rad) ( ( rad ) * 180.f / ( M_PI ) )
#define DEGREESTORAD(deg) ( ( deg ) * ( M_PI ) / 180.f )

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

        static int loadTexture();

        bool collides(const sf::Vector2f& pixelPos) const;

        void rotateShip(float rad);

        void move(float dx);

        void reset();

        void draw(sf::RenderWindow& window);

        void setVelocityVector(float vel, float angle)
        {
            this->velocity = vel;
            this->angleInRad = angle;
        }

        float getAngleInRadians() const 
        {
            return ( DEGREESTORAD( this->shipSprite.getRotation() ) );
        }

        const sf::Vector2f getPosition() const 
        {
            return this->pos;
        }

};