#pragma once
#include "constants.h"

class GameOver
{
private:

    sf::RenderWindow& window;

    sf::Font font;

    sf::Text gameOverText;

    sf::Text scoreText;

public:

    GameOver(sf::RenderWindow& window);

    int run();

    int generateText();

    void draw();

};
