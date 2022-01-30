#include "ship.h"

sf::Texture Ship::texture;

Ship::Ship() {
    this->radius = SHIP_CONSTS::SHIP_RADIUS;
    this->health = SHIP_CONSTS::INITIAL_HEALTH;

    this->shipSprite = sf::CircleShape(this->radius);
    this->shipSprite.setFillColor(sf::Color::White);
    this->shipSprite.setOrigin({this->radius, this->radius});
    this->shipSprite.setPosition(SHIP_CONSTS::INITIAL_POSITION);
    this->shipSprite.setTexture(&Ship::texture);
    this->shipSprite.setTextureRect(SHIP_CONSTS::TEXTURE_RECT);
}

bool Ship::collides(sf::Vector2f& pixelPos) const
{
    auto [x, y] = this->shipSprite.getPosition();
    float dx = pixelPos.x - x, dy = pixelPos.y - y;
    return this->radius < std::sqrt(dx * dx + dy * dy);
}

void Ship::trackMouse(float deg)
{
    shipSprite.setRotation(deg);
}

void Ship::move(float dx) 
{
    auto [currX, currY]  = this->shipSprite.getPosition();
    float x = currX + dx;
    this->shipSprite.setPosition(x + (x < 0) * DISPLAY_CONSTS::WIDTH - (x >= DISPLAY_CONSTS::WIDTH) * DISPLAY_CONSTS::WIDTH, currY);
}

float Ship::getAngle() const 
{
    return this->shipSprite.getRotation();
}

sf::Vector2f Ship::getPosition() const 
{
    return this->shipSprite.getPosition();
}

void Ship::draw(sf::RenderWindow& window)
{
    window.draw(shipSprite);
}
