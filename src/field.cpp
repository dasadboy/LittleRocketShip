#include "field.h"

typedef std::mt19937 rng_t;

std::random_device Field::ranDevice;
rng_t Field::generator (Field::ranDevice());
std::uniform_int_distribution<int> Field::randomObstacleDist(FIELD_CONSTS::OBSTACLE_NUMBERS_LOWER, FIELD_CONSTS::OBSTACLE_NUMBERS_UPPER);

Field::Field()
{
    std::unique_ptr<Obstacle> bufr = std::make_unique<BufferObstacle>();
    this->obstacles.push_back(std::move(bufr));
    this->currY = 0;
}

void Field::move(float dt)
{
    for (std::unique_ptr<Obstacle>& ob : this->obstacles)
    {
        ob->move(dt);
    }
}

void Field::removeObstacles()
{
    sort(this->obstacles.begin(), this->obstacles.end(), ObstacleCompare());
    while ( this->obstacles.back()->getYPosition() > FIELD_CONSTS::OBSTACLE_DELETION_CUTOFF_PX)
    {
        this->obstacles.pop_back();
    }
}

void Field::generateObstacle() 
{   
    int obstacleNum = Field::randomObstacleDist(Field::generator);
    std::unique_ptr<Obstacle> newObstacle;
    switch(obstacleNum)
    {
        case 1:
            newObstacle = std::make_unique<Obstacle1>();
            break;
        case 2:
            newObstacle = std::make_unique<Obstacle2>();
            break;
        case 3:
            newObstacle = std::make_unique<Obstacle3>();
            break;
        case 4:
            newObstacle = std::make_unique<Obstacle4>();
            break;
        case 5:
            newObstacle = std::make_unique<Obstacle5>();
            break;
    }
    this->obstacles.push_back(std::move(newObstacle));
}

void Field::reset()
{
    this->currY = 0;
    this->obstacles.clear();
    std::unique_ptr<Obstacle> bufr = std::make_unique<BufferObstacle>();
    this->obstacles.push_back(std::move(bufr));
}

void Field::draw(sf::RenderWindow& w)
{
    for (std::unique_ptr<Obstacle>& obs: this->obstacles)
    {
        obs->draw(w);
    }
}
