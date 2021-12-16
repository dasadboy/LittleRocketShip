#include "ship.h"

Ship::Ship(sf::RenderWindow& w): window(w)
{
    this->sprite = sf::CircleShape(100.f, 80);
}
