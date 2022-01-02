#include "common_external_includes.h"

namespace FIELD_CONSTS 
{

    const size_t MAX_OBSTACLES = 50;

    const int MAX_TIME_BETWEEN_OBSTACLES = 500;

    const int MIN_TIME_BETWEEN_OBSTACLES = 1000;

}

namespace OBSTACLE_CONSTS
{

    const int INITIAL_Y_POSITION = -200;

    const int MINIMUM_SPEED = 80.0f;

    const int MAXIMUM_SPEED = 120.0f;

}

namespace SHIP_CONSTS 
{

    const std::string PATH_TO_TEXTURE = "resources/shiptexture.png";

    const float SHIP_RADIUS = 25.f;

    const size_t POINT_COUNT = 160;

    const float INITIAL_X_VELOCITY = 0;

    const float MAXIMUM_VELOCITY = 100.f;

    const unsigned int INITIAL_HEALTH = 100;

    const sf::Vector2f INITIAL_POSITION = {360.f, 500.f};

    const sf::IntRect TEXTURE_RECT = sf::IntRect(0, 0, 50, 50);

    const float THRUST_L1 = 100.f;

}

namespace GAME_CONSTS 
{
    
    const sf::Vector2f INITIAL_VELOCITY = {0, 0};

    const std::string WINDOW_NAME = "FeelsRocketMan";

}

namespace DISPLAY_CONSTS 
{

    const unsigned int WIDTH = 720;

    const unsigned int HEIGHT = 720;

}

namespace ERROR_CODES
{

    const unsigned int FILE_NOT_FOUND = 1;

}
