#pragma once
// #include "common_external_includes.h"
// #include "constants.h"
#include "obstacles.h"

typedef std::mt19937 rng_t;

class Field
{
    private:
        int currY;
        std::vector<Obstacle*> obstacles; // int used as placeholder
        static std::random_device ranDevice;
        static rng_t generator;
        static std::uniform_int_distribution<int> randomObstacleDist;

    public:

        Field();

        void move(float dt);

        void generateObstacle();

        void removeObstacles();

        void draw(sf::RenderWindow& w);

};
