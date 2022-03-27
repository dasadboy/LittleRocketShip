#pragma once
#include "common_external_includes.h"

enum STATE_CONSTS { CLOSED = -1, PREGAME_MENU, GAME, PAUSE_MENU, RESTART, GAME_OVER };

namespace DISPLAY_CONSTS 
{

    const unsigned int WIDTH = 720;

    const unsigned int HEIGHT = 720;

}

namespace GAME_CONSTS 
{
    
    const sf::Vector2f INITIAL_VELOCITY = {0.f, 0.f};

    const std::string WINDOW_NAME = "FeelsRocketMan";

    const int MAX_TIME_BETWEEN_OBSTACLES = 3000;

    const int MIN_TIME_BETWEEN_OBSTACLES = 2000;

}

namespace FIELD_CONSTS 
{

    const size_t MAX_OBSTACLES = 50;

    const float OBSTACLE_DELETION_CUTOFF_PX = 1120.f;

    const int OBSTACLE_NUMBERS_LOWER = 1;

    const int OBSTACLE_NUMBERS_UPPER = 5;

}

namespace OBSTACLE_CONSTS
{
    const float INITIAL_Y_POSITION = -200.f;

    const float MINIMUM_SPEED_PX_PER_S = 120.0f;

    const float MAXIMUM_SPEED_PX_PER_S = 160.0f;

    const sf::IntRect TEXTURE_RECT = sf::IntRect(0, 0, 400, 400);

    const float MIN_SPRITE_SCALE = .25f;

    const float MAX_SPRITE_SCALE = .5f;

    const sf::Vector2f MAX_RECT_DIMENSIONS = {200.f, 200.f};

    const float TEXTURE_ORIGIN_PX = 200.f;

    const float BUFFER_Y_POSITION_PX = -1000.f;

}

namespace SHIP_CONSTS 
{

    const std::string PATH_TO_TEXTURE = "resources/shiptexture.png";

    const float SHIP_RADIUS_PX = 25.f;

    const float MAXIMUM_VELOCITY_PX_PER_S = 140.f;

    const unsigned int INITIAL_HEALTH = 100;

    const sf::Vector2f INITIAL_POSITION = {360.f, 500.f};

    const sf::IntRect TEXTURE_RECT = sf::IntRect(0, 0, 50, 50);

    const float THRUST_L1_PX_PER_S = 100.f;

    const float INITIAL_VELOCITY_PS_PER_S = 0.f;

    const float INITIAL_ANGLE_RAD = M_PI_2;

    const float SPRITE_INITIAL_ANGLE_RAD = 0.f;

    const float LEFT_BOUND = SHIP_CONSTS::SHIP_RADIUS_PX;

    const float RIGHT_BOUND = DISPLAY_CONSTS::WIDTH - SHIP_CONSTS::SHIP_RADIUS_PX;

    const float UPPER_BOUND = SHIP_CONSTS::SHIP_RADIUS_PX;

    const float LOWER_BOUND = DISPLAY_CONSTS::HEIGHT - SHIP_CONSTS::SHIP_RADIUS_PX;

}

namespace BUTTON_CONSTS
{

    const sf::Vector2f SIZE = {400.f, 150.f};

    const sf::IntRect TEXTURE_RECT = {0, 0, 400, 150};

}

namespace PREGAME_MENU_BUTTON_CONSTS
{

    const std::string PLAY_BUTTON_TEXTURE_FILE_PATH = "resources/buttons/playbutton.png";

    const sf::Vector2f PLAY_BUTTON_POSITION = {( DISPLAY_CONSTS::WIDTH - BUTTON_CONSTS::SIZE.x ) / 2, ( DISPLAY_CONSTS::HEIGHT - BUTTON_CONSTS::SIZE.y ) / 2};

}

namespace PAUSE_MENU_BUTTON_CONSTS
{

    const std::string RESUME_BUTTON_TEXTURE_FILE_PATH = "resources/buttons/resumebutton.png";

    const sf::Vector2f RESUME_BUTTON_POSITION = { DISPLAY_CONSTS::WIDTH / 4 - BUTTON_CONSTS::SIZE.x  / 2,  DISPLAY_CONSTS::HEIGHT / 4 - BUTTON_CONSTS::SIZE.y / 2};
    
    const std::string RESTART_BUTTON_TEXTURE_FILE_PATH = "resources/buttons/restartbutton.png";

    const sf::Vector2f RESTART_BUTTON_POSITION = { 2 * DISPLAY_CONSTS::WIDTH / 4 - BUTTON_CONSTS::SIZE.x  / 2,  2 * DISPLAY_CONSTS::HEIGHT / 4 - BUTTON_CONSTS::SIZE.y / 2};
    
    const std::string QUIT_BUTTON_TEXTURE_FILE_PATH = "resources/buttons/quitbutton.png";

    const sf::Vector2f QUIT_BUTTON_POSITION = { 3 * DISPLAY_CONSTS::WIDTH / 4 - BUTTON_CONSTS::SIZE.x  / 2,  3 * DISPLAY_CONSTS::HEIGHT / 4 - BUTTON_CONSTS::SIZE.y / 2};

}

namespace GAME_OVER_SCREEN_CONSTS
{

    const std::string MSG = "Game Over";

    const std::string FONT_FILE_PATH = "resources/RobotoMono-Bold.ttf";

    const int GAME_OVER_TEXT_SIZE = 48;

    const int GAME_OVER_TEXT_VERTICAL_OFFSET = 256;

    const int SCORE_TEXT_SIZE = 28;

    const int SCORE_TEXT_VERTICAL_OFFSET = 348;

    const int HORIZONTAL_OFFSET = 120;

}

namespace STATUS_CODES
{

    const int SUCCESS = 0;

    const int FILE_NOT_FOUND = -1;

}
