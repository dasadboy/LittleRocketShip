#pragma once
// #include "common_external_includes.h"
#include "field.h"
#include "ship.h"

class Game
{
    private:
        sf::RenderWindow& window;
        Field field;
        Ship ship;
        // ship sprite will move horizontally while field moves vertically
        // so velocity and angle are placed here
        sf::Clock deltat;
        bool LMBHeldDown;
        static std::random_device ranDevice;
        static rng_t generator;
        static std::uniform_real_distribution<float> timeDist;
        sf::Clock obstacleGenerationTimer;
        int obstacleGenerationTimeCutoff;
        sf::Clock scoreTimer;
        int score;

    public:

        Game(sf::RenderWindow& window);

        static int loadTextures();

        int run();

        void moveShip();

        void terminate();

        void drawScreen();

        void move(sf::Vector2i& mousePos);

        void reset();

        int getScore()
        {
            return this->score;
        }

};