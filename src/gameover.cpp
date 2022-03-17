#include "gameover.h"

GameOver::GameOver(sf::RenderWindow& window) : window(window)
{}

int GameOver::generateText()
{
    if (!this->font.loadFromFile(GAME_OVER_SCREEN_CONSTS::FONT_FILE_PATH))
    {
        std::cout << "Font file " << GAME_OVER_SCREEN_CONSTS::FONT_FILE_PATH << " was not found.";
        return STATUS_CODES::FILE_NOT_FOUND;
    }
    this->gameOverText.setFont(this->font);
    this->gameOverText.setCharacterSize(GAME_OVER_SCREEN_CONSTS::GAME_OVER_TEXT_SIZE);
    this->gameOverText.setString(GAME_OVER_SCREEN_CONSTS::MSG);
    this->gameOverText.setPosition(GAME_OVER_SCREEN_CONSTS::HORIZONTAL_OFFSET, GAME_OVER_SCREEN_CONSTS::GAME_OVER_TEXT_VERTICAL_OFFSET);

    this->scoreText.setFont(this->font);
    this->scoreText.setCharacterSize(GAME_OVER_SCREEN_CONSTS::SCORE_TEXT_SIZE);
    this->scoreText.setString("0");
    this->gameOverText.setPosition(GAME_OVER_SCREEN_CONSTS::HORIZONTAL_OFFSET, GAME_OVER_SCREEN_CONSTS::SCORE_TEXT_SIZE);
    return STATUS_CODES::SUCCESS;
}

int GameOver::run()
{
    while (this->window.isOpen())
    {
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                return STATE_CONSTS::PREGAME_MENU;
            }
        }
        this->window.clear(sf::Color::Black);
        this->draw();
        this->window.display();
    }
    return 0;
}

void GameOver::draw()
{
    this->window.draw(this->gameOverText);
    this->window.draw(this->scoreText);
}