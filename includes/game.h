// #include "common_external_includes.h"
#include "field.h"

class Game
{
    private:
        sf::RenderWindow window;
        Ship ship;

    public:

        Game();

        void init();

        void run();

        void terminate();

        void drawScreen();

};