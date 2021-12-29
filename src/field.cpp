#include "field.h"

typedef std::mt19937 rng_t;

Field::Field()
{
    this->currY = 0;
    this->distanceToFurthestObstacle = 0;
    std::random_device ranDevice; // init random device
    this->generator.seed(ranDevice()); // spawn generator with seed from ranDevice
    this->udist = std::uniform_int_distribution<int>(0, FIELD_CONSTS::MAX_DIST_BETWEEN_OBSTACLES); // uniform distribution
    
}

void Field::move(float dy) {};

int Field::generateObstacle() 
{
    return this->distanceToFurthestObstacle + this->udist(generator);
}

void Field::fillObstacles()
{
    int obstaclesToGenerate = FIELD_CONSTS::MAX_OBSTACLES;
    while (--obstaclesToGenerate)
    {
        this->distanceToFurthestObstacle = generateObstacle();
        this->obstacles.push_front(this->distanceToFurthestObstacle);
    }
}

void Field::draw(sf::RenderWindow& window)
{
    // TODO: implement draw
}
