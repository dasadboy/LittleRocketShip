#pragma once
#include "common_external_includes.h"

namespace FIELD_CONSTS 
{

    const size_t MAX_OBSTACLES = 50;

    const float OBSTACLE_DELETION_CUTOFF = 1120;

    const int OBSTACLE_NUMBERS_LOWER = 1;

    const int OBSTACLE_NUMBERS_UPPER = 5;

}

namespace OBSTACLE_CONSTS
{

    const float INITIAL_Y_POSITION = -200.f;

    const float MINIMUM_SPEED = 120.0f;

    const float MAXIMUM_SPEED = 160.0f;

    const sf::IntRect TEXTURE_RECT = sf::IntRect(0, 0, 400.f, 400.f);

    const float MIN_SPRITE_SCALE = 0.5;

    const float MAX_SPRITE_SCALE = 1;

    const sf::Vector2f MAX_RECT_DIMENSIONS = {200.f, 200.f};

    const float TEXTURE_ORIGIN = 200;

    const float BUFFER_Y_POSITION = -1000;

}

namespace SHIP_CONSTS 
{

    const std::string PATH_TO_TEXTURE = "resources/shiptexture.png";

    const float SHIP_RADIUS = 25.f;

    const float INITIAL_X_VELOCITY = 0;

    const float MAXIMUM_VELOCITY = 140.f;

    const unsigned int INITIAL_HEALTH = 100;

    const sf::Vector2f INITIAL_POSITION = {360.f, 500.f};

    const sf::IntRect TEXTURE_RECT = sf::IntRect(0, 0, 50, 50);

    const float THRUST_L1 = 100.f;

    const float INITIAL_VELOCITY = 0.f;

    const float INITIAL_ANGLE = 90;

}

namespace GAME_CONSTS 
{
    
    const sf::Vector2f INITIAL_VELOCITY = {0, 0};

    const std::string WINDOW_NAME = "FeelsRocketMan";

    const int MAX_TIME_BETWEEN_OBSTACLES = 3000;

    const int MIN_TIME_BETWEEN_OBSTACLES = 2000;

}

namespace DISPLAY_CONSTS 
{

    const unsigned int WIDTH = 720;

    const unsigned int HEIGHT = 720;

}

namespace ERROR_CODES
{

    const unsigned int FILE_NOT_FOUND = -1;

}
