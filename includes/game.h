// #include "common_external_includes.h"
#include "field.h"

class Game
{
    private:
        sf::RenderWindow window;
        Field field;
        Ship ship;
        // ship sprite will move horizontally while field moves vertically
        // so velocity and angle are placed here
        sf::Clock deltat;
        float velocity;
        float angle;
        bool LMBHeldDown;

    public:

        Game();

        int init();

        void run();

        void moveShip();

        void terminate();

        void drawScreen();

        void move(sf::Vector2i& mousePos);

};