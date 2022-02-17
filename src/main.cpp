// #include "common_external_includes.h"
#include "game.h"

int main ()
{
    int returnCode;
    returnCode = Game::loadTextures();
    if (returnCode != 0) return returnCode;
    sf::RenderWindow window;
    window.create(sf::VideoMode(DISPLAY_CONSTS::WIDTH, DISPLAY_CONSTS::HEIGHT), GAME_CONSTS::WINDOW_NAME);
    Game game(window);
    game.run();
    return STATUS_CODES::SUCCESS;
}
