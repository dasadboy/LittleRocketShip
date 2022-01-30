#include "field.h"

typedef std::mt19937 rng_t;

std::random_device Field::ranDevice;
rng_t Field::generator (Field::ranDevice());
std::uniform_real_distribution<float> Field::timeDist (FIELD_CONSTS::MIN_TIME_BETWEEN_OBSTACLES, FIELD_CONSTS::MAX_TIME_BETWEEN_OBSTACLES); // uniform distribution
std::uniform_int_distribution<int> Field::randomObstacleDist(FIELD_CONSTS::OBSTACLE_NUMBERS_LOWER, FIELD_CONSTS::OBSTACLE_NUMBERS_UPPER);

Field::Field()
{
    this->obstacleGenerationTimeCutoff = FIELD_CONSTS::MAX_TIME_BETWEEN_OBSTACLES;
    Obstacle* bufr = new BufferObstacle();
    this->obstacles.push_back(bufr);
}

void Field::move(float dy, float dt)
{
    for (Obstacle* ob : this->obstacles)
    {
        ob->move(dy, dt);
    }
    sort(this->obstacles.begin(), this->obstacles.end(), ObstacleCompare());
}

void Field::removeObstacles()
{
    for (auto back = this->obstacles.end() - 1; (*back)->getYPosition() > FIELD_CONSTS::OBSTACLE_DELETION_CUTOFF; --back)
    {
        if ((*back)->getYPosition() > FIELD_CONSTS::OBSTACLE_DELETION_CUTOFF)
        {
            this->obstacles.pop_back();
        }
    }
}

void Field::generateObstacle() 
{   
    if (this->obstacleGenerationTimer.getElapsedTime().asMilliseconds() < this->obstacleGenerationTimeCutoff)
        return;
    int obstacleNum = Field::randomObstacleDist(Field::generator);
    Obstacle* newObstacle;
    switch(obstacleNum)
    {
        case 1:
            newObstacle = new Obstacle1();
            break;
        case 2:
            newObstacle = new Obstacle2();
            break;
        case 3:
            newObstacle = new Obstacle3();
            break;
        case 4:
            newObstacle = new Obstacle4();
            break;
        case 5:
            newObstacle = new Obstacle5();
            break;
    }
    this->obstacles.push_back(newObstacle);
    this->obstacleGenerationTimer.restart();
    this->obstacleGenerationTimeCutoff = Field::timeDist(Field::generator);
}

void Field::draw(sf::RenderWindow& w)
{
    for (Obstacle* obs: this->obstacles)
    {
        obs->draw(w);
    }
}
