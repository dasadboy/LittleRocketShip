#include "game.h"

#define PI 3.14159265f
#define CCW90 90.f
#define DEGREES_IN_A_CIRCLE 360.f
#define radToDegrees(rad) rad * 180.f / (PI)
#define degreesToRad(deg) deg * (PI) / 180.f

Game::Game()
{
    this->LMBHeldDown = false;
    this->velocity = 0.f;
    this->angle = 90.f;
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
        this->field.generateObstacle();
        this->field.removeObstacles();
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
                this->velocity = SHIP_CONSTS::THRUST_L1;
                this->angle = (radToDegrees(std::atan2(shipy -  static_cast<float>(mousey), shipx - static_cast<float>(mousex))));
                this->LMBHeldDown = false;
            }
            else if ((event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) || this->LMBHeldDown == true)
            {
                auto [shipx, shipy] = this->ship.getPosition();
                auto [mousex, mousey] = sf::Mouse::getPosition(this->window);
                this->ship.trackMouse((radToDegrees(std::atan2(shipy -  static_cast<float>(mousey), shipx - static_cast<float>(mousex)))) + CCW90);
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
    float deltap = dt * this->velocity;
    this->deltat.restart();
    this->ship.move(deltap * std::cos((degreesToRad(this->angle))));
    this->field.move(deltap * -std::sin((degreesToRad(this->angle))), dt);
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
