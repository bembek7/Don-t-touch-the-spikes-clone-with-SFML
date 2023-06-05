#include "Game.hpp"
#include <iostream>
void Game::Play()
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Don't touch it!", sf::Style::Titlebar | sf::Style::Close);
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.setPosition(sf::Vector2i(desktop.width / 2 - windowWidth / 2, desktop.height / 2 - windowHeight / 2));
    float deltaTime = 0.0f;
    bool startGame = false;
    Player player = Player(playerTextures);;
    Level level = Level(spikeTexture, windowWidth, windowHeight, player.GetHeight());
    sf::Clock clock;
    sf::RectangleShape gameOverButton = sf::RectangleShape(sf::Vector2f(200.0f, 50.0f));
    gameOverButton.setFillColor(sf::Color::Red);
    gameOverButton.setPosition(100.0f, 100.0f);

    window.clear(sf::Color(0,255,0,255));
    level.Draw(window);
    player.Draw(window);
    window.display();

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
                    if (!player.getAlive() && isMouseOverButton(gameOverButton, mousePos))
                    {
                        player.Reset();
                        level.Reset();
                        startGame = false;
                        window.clear(sf::Color(0,255,0,255));
                        level.Draw(window);
                        player.Draw(window);
                        window.display();
                    }
                    else if(player.getAlive())
                    {
                        startGame = true;
                    }
                }
            }  
        }

        if(!startGame)continue;

        if (!player.getAlive())
        {
            window.draw(gameOverButton);
            window.display();
            continue;
        }
        player.Update(deltaTime);
        window.clear(sf::Color(0,255,0,255));
        level.CheckCollison(player);
        level.Draw(window);
        player.Draw(window);
        window.display();
    }
}

bool isMouseOverButton(const sf::RectangleShape& button, const sf::Vector2f& mousePos)
{
    sf::FloatRect buttonBounds = button.getGlobalBounds();
    return buttonBounds.contains(mousePos);
}