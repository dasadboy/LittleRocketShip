#include "game.h"

typedef std::mt19937 rng_t;

std::random_device Game::ranDevice;
rng_t Game::generator (Game::ranDevice());
std::uniform_real_distribution<float> Game::timeDist (GAME_CONSTS::MIN_TIME_BETWEEN_OBSTACLES, GAME_CONSTS::MAX_TIME_BETWEEN_OBSTACLES); // uniform distribution

Game::Game()
{
    this->LMBHeldDown = false;
    this->obstacleGenerationTimeCutoff = GAME_CONSTS::MAX_TIME_BETWEEN_OBSTACLES;
}

int Game::init()
{
    int returnCode = 0;
    returnCode = Ship::loadTexture();
    if (returnCode != 0)
        return returnCode;
    returnCode = ObstacleHolder<Obstacle1>::loadTexture();
    if (returnCode != 0)
        return returnCode;
    returnCode = ObstacleHolder<Obstacle2>::loadTexture();
    if (returnCode != 0)
        return returnCode;
    returnCode = ObstacleHolder<Obstacle3>::loadTexture();
    if (returnCode != 0)
        return returnCode;
    returnCode = ObstacleHolder<Obstacle4>::loadTexture();
    if (returnCode != 0)
        return returnCode;
    returnCode = ObstacleHolder<Obstacle5>::loadTexture();
    if (returnCode != 0)
        return returnCode;
    this->window.create(sf::VideoMode(DISPLAY_CONSTS::WIDTH, DISPLAY_CONSTS::HEIGHT), GAME_CONSTS::WINDOW_NAME);
    return returnCode;
}

void Game::run()
{
    while (this->window.isOpen())
    {
        moveShip();
        if (this->obstacleGenerationTimer.getElapsedTime().asMilliseconds() > this->obstacleGenerationTimeCutoff)
        {
            this->field.generateObstacle();
            this->field.removeObstacles();
            this->obstacleGenerationTimer.restart();
            this->obstacleGenerationTimeCutoff = Game::timeDist(Game::generator);
        }
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                terminate();
            }
            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                auto [shipx, shipy] = this->ship.getPosition();
                auto [mousex, mousey] = sf::Mouse::getPosition(this->window);
                this->ship.setVelocity(SHIP_CONSTS::THRUST_L1, std::atan2(shipy -  static_cast<float>(mousey), shipx - static_cast<float>(mousex)));
                this->LMBHeldDown = false;
            }
            else if ((event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) || this->LMBHeldDown == true)
            {
                auto [shipx, shipy] = this->ship.getPosition();
                auto [mousex, mousey] = sf::Mouse::getPosition(this->window);
                this->ship.trackMouse(std::atan2(shipy -  static_cast<float>(mousey), shipx - static_cast<float>(mousex)));
                this->LMBHeldDown = true;
            }
        }

        this->window.clear(sf::Color::Black);
        drawScreen();
        this->window.display();
    }
}

void Game::moveShip() 
{
    float dt = this->deltat.getElapsedTime().asSeconds();
    this->ship.move(dt);
    this->field.move(dt);
    this->deltat.restart();
}

void Game::terminate()
{
    this->window.close();
}

void Game::drawScreen()
{
    this->ship.draw(this->window);
    this->field.draw(this->window);
}
