#pragma once
// #include "common_external_includes.h"
#include "constants.h"

typedef std::mt19937 rng_t;

class Obstacle
{
protected:
    float speed;
    sf::Vector2f pos;
    sf::RectangleShape sprite;
    static std::random_device ranDevice;
    static rng_t generator;
    static std::uniform_int_distribution<int> speedUDist;
    static std::uniform_real_distribution<float> scaleUDist;
    static std::uniform_real_distribution<float> xPosUDist;

public:

    Obstacle();

    virtual void move(float dt);

    virtual const sf::Vector2f& getPosition();

    virtual void draw(sf::RenderWindow& window);

    virtual const std::vector<sf::Vector2f>& getOuterPixels() = 0;

    virtual ~Obstacle() {}

};

class BufferObstacle : public Obstacle
{
    std::vector<sf::Vector2f> emptyVector; // empty vector to pass into getOuterPixels
public:
    BufferObstacle() : Obstacle() {}

    void move(float dt) override {}

    const std::vector<sf::Vector2f>& getOuterPixels() { return emptyVector; }

    void draw(sf::RenderWindow& w) override {}

};

template < typename T >
class ObstacleHolder : public Obstacle
{
protected:
    static std::string textureFilename;
    static std::vector<sf::Vector2f> outerPixels;
    static sf::Texture texture;
public:

    ObstacleHolder() : Obstacle()
    {
        this->sprite.setTexture(&ObstacleHolder<T>::texture);
    }

    static int loadTexture()
    {
        sf::Image textureImage;

        if (!textureImage.loadFromFile(ObstacleHolder<T>::textureFilename))
        {        
            std::cout << "Texture file " + ObstacleHolder<T>::textureFilename + " could not be loaded.";
            return STATUS_CODES::FILE_NOT_FOUND;
        }

        // getting edges
        const sf::Color emptyPixel (0, 0, 0, 0); // transparent pixel
        for (int x = 0, width = OBSTACLE_CONSTS::TEXTURE_RECT.width; x < width; ++x)
        {
            for (int y = 0, height = OBSTACLE_CONSTS::TEXTURE_RECT.height; y < height; ++y)
            {
                // non-empty pixel neighboring one or more empty pixels is on the edge
                if (
                    textureImage.getPixel(x, y).a != 0 && (
                        textureImage.getPixel(x + 1, y).a == 0 ||
                        textureImage.getPixel(x, y + 1).a == 0 ||
                        textureImage.getPixel(x - 1, y).a == 0 ||
                        textureImage.getPixel(x, y - 1).a == 0 )
                )
                {
                    textureImage.setPixel(x, y, sf::Color(0, 255, 0, 255));
                    float relx = (x - OBSTACLE_CONSTS::TEXTURE_ORIGIN_PX) * OBSTACLE_CONSTS::MAX_SPRITE_SCALE, rely = (y - OBSTACLE_CONSTS::TEXTURE_ORIGIN_PX) * OBSTACLE_CONSTS::MAX_SPRITE_SCALE;
                    ObstacleHolder<T>::outerPixels.emplace_back(relx, rely);
                }
            }
        }

        ObstacleHolder<T>::texture.loadFromImage(textureImage);
        ObstacleHolder<T>::texture.setSmooth(true);
        return 0;
    }

    static sf::Texture& getTexture()
    {
        return ObstacleHolder<T>::texture;
    }

    const std::vector<sf::Vector2f>& getOuterPixels()
    {
        return ObstacleHolder<T>::outerPixels;
    }

};

class Obstacle1 : public ObstacleHolder<Obstacle1>
{
public:
    Obstacle1() : ObstacleHolder() {}

};

class Obstacle2 : public ObstacleHolder<Obstacle2>
{
public:
    Obstacle2() : ObstacleHolder() {}

};

class Obstacle3 : public ObstacleHolder<Obstacle3>
{
public:
    Obstacle3() : ObstacleHolder() {}

};

class Obstacle4 : public ObstacleHolder<Obstacle4>
{
public:
    Obstacle4() : ObstacleHolder() {}

};

class Obstacle5 : public ObstacleHolder<Obstacle5>
{
public:
    Obstacle5() : ObstacleHolder() {}

};
