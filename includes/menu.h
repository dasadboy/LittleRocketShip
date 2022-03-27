#pragma once
// #include "common_external_includes.h"
#include "button.h"

class PreGameMenu
{

    sf::RenderWindow& window;
    Button playButton;

public:

    PreGameMenu(sf::RenderWindow& window);

    int run();

    void drawScreen();

    void terminate();

};

class PauseMenu
{

    sf::RenderWindow& window;
    Button resumeButton;
    Button restartButton;
    Button quitgameButton;

public:

    PauseMenu(sf::RenderWindow& window);

    int run();

    void drawScreen();

    void terminate();

};
