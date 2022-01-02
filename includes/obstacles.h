// #include "common_external_includes.h"
#include "constants.h"

typedef std::mt19937 rng_t;

class Obstacle
{

    float speed;
    float posY;
    static std::random_device ranDevice;
    static rng_t generator;
    static std::uniform_int_distribution<int> udist;

public:

    Obstacle();

    void move(float dy);

    const inline float getYPosition();

};

class ObstacleCompare
{
    bool operator()(Obstacle a, Obstacle b)
    {
        return a.getYPosition() < b.getYPosition();
    }
};
