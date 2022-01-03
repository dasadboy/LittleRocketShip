#include "field.h"

typedef std::mt19937 rng_t;

std::random_device Field::ranDevice;
rng_t Field::generator (Field::ranDevice());


Field::Field()
{
    this->currY = 0;
    this->obstacleGenerationTimeCutoff = INT_MAX;
    std::random_device ranDevice; // init random device
    this->generator.seed(ranDevice()); // spawn generator with seed from ranDevice
    this->udist = std::uniform_int_distribution<int>(FIELD_CONSTS::MIN_TIME_BETWEEN_OBSTACLES, FIELD_CONSTS::MAX_TIME_BETWEEN_OBSTACLES); // uniform distribution
    
}

void Field::move(float dy)
{
    for (auto& ob : this->obstacles)
    {
        ob.move(dy);
    }
    sort(this->obstacles.begin(), this->obstacles.end(), ObstacleCompare());
}

void Field::generateObstacle() 
{
    obstacles.emplace_back();
}

void Field::draw(sf::RenderWindow& window)
{
    // TODO: implement draw
}
