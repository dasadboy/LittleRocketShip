#include "ship.h"

Ship::Ship() {
    this->radius = SHIP_CONSTS::SHIP_RADIUS;
    this->vel = SHIP_CONSTS::INITIAL_VELOCITY;
    this->health = SHIP_CONSTS::INITIAL_HEALTH;

    sf::Texture texture;
    if (!texture.loadFromFile(SHIP_CONSTS::PATH_TO_TEXTURE))
    {
        std::cout << "ship texture could not be loaded.\n";
    }
    texture.setSmooth(true);
    this->shipSprite = sf::CircleShape(this->radius, 80);
    this->shipSprite.setTexture(&texture);
    this->shipSprite.setPosition(SHIP_CONSTS::INITIAL_POSITION);
}

bool Ship::collides(sf::Vector2f& pixelPos)
{
    float dx = pixelPos.x - this->origin.x, dy = pixelPos.y - this->origin.y;
    return this->radius < std::sqrt(dx * dx + dy * dy);
}

void Ship::boost(sf::Vector2f& accel)
{
    this->vel += accel;
}

void Ship::decelerate()
{
    this->vel.x -= this->vel.x/3;
    this->vel.y -= this->vel.y/3;
}

void Ship::draw(sf::RenderWindow& window)
{
    window.draw(shipSprite);
}
