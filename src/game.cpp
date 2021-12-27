#include "game.h"

#define PI 3.14159265f
#define CCW90 90.f
#define DEGREES_IN_A_CIRCLE 360.f

Game::Game()
{
    this->LMBHeldDown = false;
    this->velocity = 0.f;
    this->angle = 90.f;
}

void Game::init()
{
    this->window.create(sf::VideoMode(DISPLAY_CONSTS::WIDTH, DISPLAY_CONSTS::HEIGHT), GAME_CONSTS::WINDOW_NAME);
}

void Game::run()
{
    while (this->window.isOpen())
    {
        moveShip();
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
                this->angle = (std::atan2(shipy -  static_cast<float>(mousey), shipx - static_cast<float>(mousex)) * 180.f/(PI));
                this->LMBHeldDown = false;
            }
            else if ((event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) || this->LMBHeldDown == true)
            {
                auto [shipx, shipy] = this->ship.getPosition();
                auto [mousex, mousey] = sf::Mouse::getPosition(this->window);
                this->ship.trackMouse(std::atan2(shipy -  static_cast<float>(mousey), shipx - static_cast<float>(mousex)) * 180.f/(PI) + CCW90);
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
    float deltap = this->deltat.getElapsedTime().asSeconds() * this->velocity;
    this->deltat.restart();
    this->ship.move(deltap * std::cos(this->angle * (PI)/180.f));
    this->field.move(deltap * std::sin(this->angle * (PI)/180.f));
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
