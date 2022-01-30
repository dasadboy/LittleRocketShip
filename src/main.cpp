// #include "common_external_includes.h"
#include "game.h"

int main ()
{
    Game game;
    int returnCode;
    returnCode = game.init();
    if (returnCode != 0) return returnCode;
    game.run();
    return 0;
}
