// #include "common_external_includes.h"
#include "game.h"

int main ()
{
    Game game;
    int returnCode;
    returnCode = game.init();
    if (returnCode != STATUS_CODES::SUCCESS) return returnCode;
    game.run();
    return STATUS_CODES::SUCCESS;
}
