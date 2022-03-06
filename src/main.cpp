// #include "common_external_includes.h"
#include "game.h"
#include "menu.h"

int main ()
{
    int returnCode;
    returnCode = Game::loadTextures();
    if (returnCode != 0) return returnCode;
    sf::RenderWindow window;
    window.create(sf::VideoMode(DISPLAY_CONSTS::WIDTH, DISPLAY_CONSTS::HEIGHT), GAME_CONSTS::WINDOW_NAME);
    Game game(window);
    PreGameMenu pregameMenu(window);
    PauseMenu pauseMenu(window);
    int state;
    while (window.isOpen())
    {
        switch (state)
        {
            case STATE_CONSTS::PREGAME_MENU:
                state = pregameMenu.run();
                break;
            case STATE_CONSTS::GAME:
                state = game.run();
                break;
            case STATE_CONSTS::PAUSE_MENU:
                state = pauseMenu.run();
                break;
            case STATE_CONSTS::RESTART:
                game.reset();
                state = STATE_CONSTS::GAME;
                break;
        }
    }
    return STATUS_CODES::SUCCESS;
}
