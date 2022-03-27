#include "obstacles.h"


std::random_device Obstacle::ranDevice;
rng_t Obstacle::generator (Obstacle::ranDevice());
std::uniform_int_distribution<int> Obstacle::speedUDist (OBSTACLE_CONSTS::MINIMUM_SPEED_PX_PER_S, OBSTACLE_CONSTS::MAXIMUM_SPEED_PX_PER_S);
std::uniform_real_distribution<float> Obstacle::scaleUDist (OBSTACLE_CONSTS::MIN_SPRITE_SCALE, OBSTACLE_CONSTS::MAX_SPRITE_SCALE);
std::uniform_real_distribution<float> Obstacle::xPosUDist (0, DISPLAY_CONSTS::WIDTH);

#define FINDCENTRE(x) ( x ) * .5f

Obstacle::Obstacle()
{
    this->speed = this->speedUDist(generator);

    this->sprite = sf::RectangleShape(OBSTACLE_CONSTS::MAX_RECT_DIMENSIONS);
    // this->sprite.setFillColor(sf::Color::White);

    sf::Vector2f centre = FINDCENTRE(this->sprite.getSize());

    this->sprite.setOrigin( centre );

    this->pos = {this->xPosUDist(this->generator), OBSTACLE_CONSTS::INITIAL_Y_POSITION};
    this->sprite.setPosition(this->pos);
}

void Obstacle::move(float dt)
{
    this->pos.y += this->speed * dt;
    this->sprite.setPosition(this->pos);
}

const sf::Vector2f& Obstacle::getPosition()
{
    return this->pos;
}

void Obstacle::draw(sf::RenderWindow& window) {
    window.draw(this->sprite);
}

template <> std::string ObstacleHolder<BufferObstacle>::textureFilename = "";

template <> sf::Texture ObstacleHolder<BufferObstacle>::texture = sf::Texture();

template <> std::vector<sf::Vector2f> ObstacleHolder<BufferObstacle>::outerPixels = {};

template <> std::string ObstacleHolder<Obstacle1>::textureFilename = "resources/obstacles/obstacle1.png";

template <> sf::Texture ObstacleHolder<Obstacle1>::texture = sf::Texture();

template <> std::vector<sf::Vector2f> ObstacleHolder<Obstacle1>::outerPixels = {};

template <> std::string ObstacleHolder<Obstacle2>::textureFilename = "resources/obstacles/obstacle2.png";

template <> sf::Texture ObstacleHolder<Obstacle2>::texture = sf::Texture();

template <> std::vector<sf::Vector2f> ObstacleHolder<Obstacle2>::outerPixels = {};

template <> std::string ObstacleHolder<Obstacle3>::textureFilename = "resources/obstacles/obstacle3.png";

template <> sf::Texture ObstacleHolder<Obstacle3>::texture = sf::Texture();

template <> std::vector<sf::Vector2f> ObstacleHolder<Obstacle3>::outerPixels = {};

template <> std::string ObstacleHolder<Obstacle4>::textureFilename = "resources/obstacles/obstacle4.png";

template <> sf::Texture ObstacleHolder<Obstacle4>::texture = sf::Texture();

template <> std::vector<sf::Vector2f> ObstacleHolder<Obstacle4>::outerPixels = {};

template <> std::string ObstacleHolder<Obstacle5>::textureFilename = "resources/obstacles/obstacle5.png";

template <> sf::Texture ObstacleHolder<Obstacle5>::texture = sf::Texture();

template <> std::vector<sf::Vector2f> ObstacleHolder<Obstacle5>::outerPixels = {};
