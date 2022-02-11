#include "obstacles.h"


std::random_device Obstacle::ranDevice;
rng_t Obstacle::generator (Obstacle::ranDevice());
std::uniform_int_distribution<int> Obstacle::speedUDist (OBSTACLE_CONSTS::MINIMUM_SPEED_PX_PER_S, OBSTACLE_CONSTS::MAXIMUM_SPEED_PX_PER_S);
std::uniform_real_distribution<float> Obstacle::scaleUDist (OBSTACLE_CONSTS::MIN_SPRITE_SCALE, OBSTACLE_CONSTS::MAX_SPRITE_SCALE);
std::uniform_real_distribution<float> Obstacle::xPosUDist (0, DISPLAY_CONSTS::WIDTH);

#define findCentre(x) ( x ) * .5f

Obstacle::Obstacle()
{
    this->speed = this->speedUDist(generator);

    this->sprite = sf::RectangleShape(OBSTACLE_CONSTS::MAX_RECT_DIMENSIONS);
    // this->sprite.setFillColor(sf::Color::White);
    this->sprite.setOrigin(findCentre(this->sprite.getSize()));

    this->posX = this->xPosUDist(this->generator);
    this->posY = OBSTACLE_CONSTS::INITIAL_Y_POSITION;
    this->sprite.setPosition({this->posX, this->posY});
}

void Obstacle::move(float dt)
{
    this->posY += this->speed * dt;
    this->sprite.setPosition({this->posX, this->posY});
}

const float Obstacle::getYPosition()
{
    return this->posY;
}

void Obstacle::draw(sf::RenderWindow& window) {
    window.draw(this->sprite);
}

template <> std::string ObstacleHolder<BufferObstacle>::textureFilename = "";

template <> sf::Texture ObstacleHolder<BufferObstacle>::texture = sf::Texture();

template <> std::vector<std::pair<float, float>> ObstacleHolder<BufferObstacle>::outerPixels = {};

template <> std::string ObstacleHolder<Obstacle1>::textureFilename = "resources/obstacles/obstacle1.png";

template <> sf::Texture ObstacleHolder<Obstacle1>::texture = sf::Texture();

template <> std::vector<std::pair<float, float>> ObstacleHolder<Obstacle1>::outerPixels = {};

template <> std::string ObstacleHolder<Obstacle2>::textureFilename = "resources/obstacles/obstacle2.png";

template <> sf::Texture ObstacleHolder<Obstacle2>::texture = sf::Texture();

template <> std::vector<std::pair<float, float>> ObstacleHolder<Obstacle2>::outerPixels = {};

template <> std::string ObstacleHolder<Obstacle3>::textureFilename = "resources/obstacles/obstacle3.png";

template <> sf::Texture ObstacleHolder<Obstacle3>::texture = sf::Texture();

template <> std::vector<std::pair<float, float>> ObstacleHolder<Obstacle3>::outerPixels = {};

template <> std::string ObstacleHolder<Obstacle4>::textureFilename = "resources/obstacles/obstacle4.png";

template <> sf::Texture ObstacleHolder<Obstacle4>::texture = sf::Texture();

template <> std::vector<std::pair<float, float>> ObstacleHolder<Obstacle4>::outerPixels = {};

template <> std::string ObstacleHolder<Obstacle5>::textureFilename = "resources/obstacles/obstacle5.png";

template <> sf::Texture ObstacleHolder<Obstacle5>::texture = sf::Texture();

template <> std::vector<std::pair<float, float>> ObstacleHolder<Obstacle5>::outerPixels = {};
