#pragma once
// #include "common_external_includes.h"
#include "constants.h"

class Button
{
private:
    
    static const sf::Color activeColor;
    static const sf::Color inactiveColor;
    std::string textureFilename;
    sf::Texture buttonTexture;
    sf::RectangleShape sprite;
    sf::Vector2f position;

public:

    Button(const std::string& filename, const sf::Vector2f& position);

    int loadTexture();

    void createShape();

    bool isCoordOnButton(const sf::Vector2f& coord);

    void mouseOver();

    void mouseOff();

    void draw(sf::RenderWindow& window);

};
