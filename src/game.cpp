#include "game.h"

Game::Game()
{}

void Game::init()
{
    this->window.create(sf::VideoMode(640, 640), "FeelsRocketMan");
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
        }
        this->window.clear(sf::Color::Black);
        std::cout << "Black" << std::endl;
        // drawScreen();
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
