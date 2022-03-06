#include "button.h"

const sf::Color Button::activeColor(0xffffffff);
const sf::Color Button::inactiveColor(0xffffffb0);

Button::Button(const std::string& filename, const sf::Vector2f& position)
{
    this->textureFilename = filename;
    this->position = position;
}

int Button::loadTexture()
{
    if(!this->buttonTexture.loadFromFile(this->textureFilename))
    {
        std::cout << "Could not load " << this->textureFilename << ".\n";
        return STATUS_CODES::FILE_NOT_FOUND;
    }
    this->buttonTexture.setSmooth(true);
    return STATUS_CODES::SUCCESS;
}

void Button::createShape()
{
    this->sprite.setSize(BUTTON_CONSTS::SIZE);
    this->sprite.setPosition(this->position);
    this->sprite.setFillColor(inactiveColor);
    this->sprite.setTexture(&this->buttonTexture);
    this->sprite.setTextureRect(BUTTON_CONSTS::TEXTURE_RECT);
}

bool Button::isCoordOnButton(const sf::Vector2f& coord)
{
    return (coord.x > position.x && coord.x < (position.x + BUTTON_CONSTS::SIZE.x)) && (coord.y > position.y && coord.y < (position.y + BUTTON_CONSTS::SIZE.y));
}

void Button::mouseOver()
{
    this->sprite.setFillColor(activeColor);
}

void Button::mouseOff()
{
    this->sprite.setFillColor(inactiveColor);
}

void Button::draw(sf::RenderWindow& window)
{
    window.draw(this->sprite);
}
