#include "field.h"

typedef std::mt19937 rng_t;

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
        ob -= dy;
    }
    sort(this->obstacles.begin(), this->obstacles.end(), std::greater<int>());
}

void Field::generateObstacle() 
{
    obstacles.push_back(OBSTACLE_CONSTS::INITIAL_Y_POSITION);
}

void Field::draw(sf::RenderWindow& window)
{
    // TODO: implement draw
}
