#pragma once
// #include "common_external_includes.h"
// #include "constants.h"
#include "obstacles.h"

typedef std::mt19937 rng_t;

struct ObstacleCompare
{
    bool operator()(Obstacle* a, Obstacle* b)
    {
        return a->getYPosition() < b->getYPosition();
    }

    bool operator()(std::unique_ptr<Obstacle>& a, std::unique_ptr<Obstacle>& b)
    {
        return a->getYPosition() < b->getYPosition();
    }
};

class Field
{
    private:
        int currY;
        std::vector<std::unique_ptr<Obstacle>> obstacles;
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
