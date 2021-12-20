#include "game.h"

Game::Game()
{}

void Game::init()
{
    this->window.create(sf::VideoMode(DISPLAY_CONSTS::WIDTH, DISPLAY_CONSTS::HEIGHT), "FeelsRocketMan");
}

void Game::run()
{
    while (this->window.isOpen())
    {
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                terminate();
            else if (event.type == sf::Event::MouseButtonPressed)
                terminate();
        }
        this->window.clear(sf::Color::Black);
        drawScreen();
        this->window.display();
    }
}

void Game::terminate()
{
    this->window.close();
}

void Game::drawScreen()
{
    this->ship.draw(this->window);
}
