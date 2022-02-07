// #include "common_external_includes.h"
#include "game.h"

int main ()
{
    int returnCode;
    returnCode = Game::loadTextures();
    if (returnCode != 0) return returnCode;
    sf::RenderWindow window;
    Game game(window);
    game.run();
    return 0;
}
