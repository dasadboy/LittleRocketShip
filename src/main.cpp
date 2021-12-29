// #include "common_external_includes.h"
#include "game.h"

int main ()
{
    Game game;
    int returnCode = game.init();
    if (returnCode) return returnCode;
    game.run();
    return 0;
}
