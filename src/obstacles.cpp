#include "obstacles.h"


std::random_device Obstacle::ranDevice; // init random device
rng_t Obstacle::generator (Obstacle::ranDevice()); // spawn generator with seed from ranDevice
std::uniform_int_distribution<int> Obstacle::udist (FIELD_CONSTS::MIN_TIME_BETWEEN_OBSTACLES, FIELD_CONSTS::MAX_TIME_BETWEEN_OBSTACLES); // uniform distribution

Obstacle::Obstacle()
{
    this->speed = this->udist(generator);
    this->posY = OBSTACLE_CONSTS::INITIAL_Y_POSITION;
}

void Obstacle::move(float dy)
{
    this->posY += speed + dy;
}

const inline float Obstacle::getYPosition()
{
    return this->posY;
}
