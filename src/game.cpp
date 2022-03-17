#include "game.h"

typedef std::mt19937 rng_t;

std::random_device Game::ranDevice;
rng_t Game::generator (Game::ranDevice());
std::uniform_real_distribution<float> Game::timeDist (GAME_CONSTS::MIN_TIME_BETWEEN_OBSTACLES, GAME_CONSTS::MAX_TIME_BETWEEN_OBSTACLES);

#define calculatePartialScore(time) ( ( time ) / 10 ) * 10

Game::Game(sf::RenderWindow& window) : window(window)
{
    this->LMBHeldDown = false;
    this->obstacleGenerationTimeCutoff = GAME_CONSTS::MAX_TIME_BETWEEN_OBSTACLES;
    this->score = 0;
}

int Game::loadTextures()
{
    int returnCode = STATUS_CODES::SUCCESS;
    returnCode = Ship::loadTexture();
    if (returnCode != STATUS_CODES::SUCCESS)
        return returnCode;
    returnCode = ObstacleHolder<Obstacle1>::loadTexture();
    if (returnCode != STATUS_CODES::SUCCESS)
        return returnCode;
    returnCode = ObstacleHolder<Obstacle2>::loadTexture();
    if (returnCode != STATUS_CODES::SUCCESS)
        return returnCode;
    returnCode = ObstacleHolder<Obstacle3>::loadTexture();
    if (returnCode != STATUS_CODES::SUCCESS)
        return returnCode;
    returnCode = ObstacleHolder<Obstacle4>::loadTexture();
    if (returnCode != STATUS_CODES::SUCCESS)
        return returnCode;
    returnCode = ObstacleHolder<Obstacle5>::loadTexture();
    if (returnCode != STATUS_CODES::SUCCESS)
        return returnCode;
    return returnCode;
}

int Game::run()
{
    this->deltat.restart();
    this->scoreTimer.restart();
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
        for (const std::unique_ptr<Obstacle>& obstacle: this->field.getObstacles())
        {
            sf::Vector2f pos = obstacle->getPosition();
            for (const sf::Vector2f& p: obstacle->getOuterPixels())
            {
                
                if (this->ship.collides(p + pos))
                {
                    this->score += calculatePartialScore( this->scoreTimer.getElapsedTime().asMilliseconds() );
                    return STATE_CONSTS::GAME_OVER;
                }
            }
        }
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                terminate();
            }
            else if ((event.type == sf::Event::KeyPressed) && (event.key.code = sf::Keyboard::Escape))
            {
                this->score += calculatePartialScore( this->scoreTimer.getElapsedTime().asMilliseconds() );
                return STATE_CONSTS::PAUSE_MENU;
            }
            else if ((event.type == sf::Event::MouseButtonReleased) && (event.mouseButton.button == sf::Mouse::Left))
            {
                auto [shipx, shipy] = this->ship.getPosition();
                auto [mousex, mousey] = sf::Mouse::getPosition(this->window);
                this->ship.setVelocityVector(SHIP_CONSTS::THRUST_L1_PX_PER_S, std::atan2(shipy -  static_cast<float>(mousey), shipx - static_cast<float>(mousex)));
                this->LMBHeldDown = false;
            }
            else if (((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left)) || this->LMBHeldDown == true)
            {
                auto [shipx, shipy] = this->ship.getPosition();
                auto [mousex, mousey] = sf::Mouse::getPosition(this->window);
                this->ship.rotateShip(std::atan2(shipy -  static_cast<float>(mousey), shipx - static_cast<float>(mousex)));
                this->LMBHeldDown = true;
            }
        }

        this->window.clear(sf::Color::Black);
        drawScreen();
        this->window.display();
    }
    return -1;
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

void Game::reset()
{
    this->LMBHeldDown = false;
    this->obstacleGenerationTimeCutoff = GAME_CONSTS::MAX_TIME_BETWEEN_OBSTACLES;

    this->field.reset();
    this->ship.reset();

    this->deltat.restart();
    this->obstacleGenerationTimer.restart();
}
