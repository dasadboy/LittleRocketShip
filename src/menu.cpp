#include "menu.h"


// Pregame menu
PreGameMenu::PreGameMenu(sf::RenderWindow& window) :
window(window),
playButton(PREGAME_MENU_BUTTON_CONSTS::PLAY_BUTTON_TEXTURE_FILE_PATH, PREGAME_MENU_BUTTON_CONSTS::PLAY_BUTTON_POSITION)
{
    this->playButton.loadTexture();
    this->playButton.createShape();
}

int PreGameMenu::run()
{
    while (this->window.isOpen())
    {
        auto [mousex, mousey] = sf::Mouse::getPosition(this->window);
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            bool isCoordOnPlayButton = this->playButton.isCoordOnButton( { static_cast<float>(mousex), static_cast<float>(mousey) } );
            if (event.type == sf::Event::Closed)
            {
                terminate();
            }
            else if ( isCoordOnPlayButton )
            {
                if ( ( event.type == sf::Event::MouseButtonReleased ) && ( event.mouseButton.button == sf::Mouse::Left ) )
                {
                    return STATE_CONSTS::GAME;
                }
                this->playButton.mouseOver();
            }
            else if ( !isCoordOnPlayButton )
            {
                this->playButton.mouseOff();
            }
        }

        this->window.clear(sf::Color::Black);
        drawScreen();
        this->window.display();
    }
    return 0;
}

void PreGameMenu::drawScreen()
{
    this->playButton.draw(this->window);
}

void PreGameMenu::terminate()
{
    this->window.close();
}


// Pause Menu
PauseMenu::PauseMenu(sf::RenderWindow& window) :
window(window),
resumeButton(PAUSE_MENU_BUTTON_CONSTS::RESUME_BUTTON_TEXTURE_FILE_PATH, PAUSE_MENU_BUTTON_CONSTS::RESUME_BUTTON_POSITION),
restartButton(PAUSE_MENU_BUTTON_CONSTS::RESTART_BUTTON_TEXTURE_FILE_PATH, PAUSE_MENU_BUTTON_CONSTS::RESTART_BUTTON_POSITION),
quitgameButton(PAUSE_MENU_BUTTON_CONSTS::QUIT_BUTTON_TEXTURE_FILE_PATH, PAUSE_MENU_BUTTON_CONSTS::QUIT_BUTTON_POSITION)
{
    this->resumeButton.loadTexture();
    this->resumeButton.createShape();
    this->restartButton.loadTexture();
    this->restartButton.createShape();
    this->quitgameButton.loadTexture();
    this->quitgameButton.createShape();
}



int PauseMenu::run()
{

    while (this->window.isOpen())
    {
        auto [mousex, mousey] = sf::Mouse::getPosition(this->window);
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            bool isCoordOnResumeButton = this->resumeButton.isCoordOnButton( { static_cast<float>(mousex), static_cast<float>(mousey) } );
            bool isCoordOnRestartButton = this->restartButton.isCoordOnButton( { static_cast<float>(mousex), static_cast<float>(mousey) } );
            bool isCoordOnQuitgameButton = this->quitgameButton.isCoordOnButton( { static_cast<float>(mousex), static_cast<float>(mousey) } );
            if (event.type == sf::Event::Closed)
            {
                terminate();
            }
            else if ( isCoordOnResumeButton )
            {
                this->resumeButton.mouseOver();
                this->restartButton.mouseOff();
                this->quitgameButton.mouseOff();
                if ( ( event.type == sf::Event::MouseButtonReleased ) && ( event.mouseButton.button == sf::Mouse::Left ) )
                {
                    return STATE_CONSTS::GAME;
                }
            }
            else if ( isCoordOnRestartButton )
            {
                this->resumeButton.mouseOff();
                this->restartButton.mouseOver();
                this->quitgameButton.mouseOff();
                if ( ( event.type == sf::Event::MouseButtonReleased ) && ( event.mouseButton.button == sf::Mouse::Left ) )
                {
                    return STATE_CONSTS::RESTART;
                }
            }
            else if ( isCoordOnQuitgameButton )
            {
                this->resumeButton.mouseOff();
                this->restartButton.mouseOff();
                this->quitgameButton.mouseOver();
                if ( ( event.type == sf::Event::MouseButtonReleased ) && ( event.mouseButton.button == sf::Mouse::Left ) )
                {
                    terminate();
                }
            }
            else
            {
                this->resumeButton.mouseOff();
                this->restartButton.mouseOff();
                this->quitgameButton.mouseOff();
            }
        }

        this->window.clear(sf::Color::Black);
        drawScreen();
        this->window.display();
    }
    return 0;
}

void PauseMenu::drawScreen()
{
    this->resumeButton.draw(this->window);
    this->restartButton.draw(this->window);
    this->quitgameButton.draw(this->window);
}

void PauseMenu::terminate()
{
    this->window.close();
}
