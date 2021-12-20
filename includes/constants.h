#include "common_external_includes.h"

namespace FIELD_CONSTS 
{

    const size_t MAX_OBSTACLES = 50;

    const int MAX_DIST_BETWEEN_OBSTACLES = 50;

}

namespace SHIP_CONSTS 
{

    const std::string PATH_TO_TEXTURE = "resources/shiptexture.png";

    const float SHIP_RADIUS = 25.f;

    const size_t POINT_COUNT = 160;

    const sf::Vector2f INITIAL_VELOCITY = {0, 0};

    const float MAXIMUM_VELOCITY = 100.f;

    const unsigned int INITIAL_HEALTH = 100;

    const sf::Vector2f INITIAL_POSITION = {360.f, 645.f};

    const sf::IntRect TEXTURE_RECT = sf::IntRect(0, 0, 50, 50);

}

namespace DISPLAY_CONSTS 
{

    const unsigned int WIDTH = 720;

    const unsigned int HEIGHT = 720;

}
