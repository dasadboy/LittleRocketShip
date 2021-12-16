#include "field.h"

typedef std::mt19937 rng_t;

Field::Field(sf::RenderWindow& w):
window(w)
{
    currY = 0;
    distanceToFurthestObstacle = 0;
    std::random_device seed; // get seed
    generator.seed(seed); // set seed for generator
    udist = std::uniform_int_distribution<int>(0, FIELD_CONSTS::MAX_DIST_BETWEEN_OBSTACLES); // uniform distribution
    
}

int Field::generateObstacle() 
{
    return distanceToFurthestObstacle + udist(generator);
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

void Field::draw()
{
    // TODO: implement draw
}
