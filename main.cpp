#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Spike.hpp"
#include "Level.hpp"

static const float height = 600;
static const float width = 400;

bool isMouseOverButton(const sf::RectangleShape& button, const sf::Vector2f& mousePos)
{
    sf::FloatRect buttonBounds = button.getGlobalBounds();
    return buttonBounds.contains(mousePos);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Test", sf::Style::Titlebar | sf::Style::Close);
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.setPosition(sf::Vector2i(desktop.width / 2 - width / 2, desktop.height / 2 - height / 2));
    sf::Texture playerTexture;
    playerTexture.loadFromFile("Knight.png");
    Player player = Player(playerTexture);
    sf::Texture spikeTexture;
    spikeTexture.loadFromFile("Pawn.png");
    Level level(spikeTexture, width, height, player.GetHeight());
    float deltaTime = 0.0f;
    bool startGame = false;
    sf::Clock clock;

    // Game Over button
    sf::RectangleShape gameOverButton(sf::Vector2f(200.0f, 50.0f));
    gameOverButton.setFillColor(sf::Color::Red);
    gameOverButton.setPosition(100.0f, 100.0f);

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
                    if (!player.getAlive() && isMouseOverButton(gameOverButton, mousePos))
                    {
                        player = Player(playerTexture);
                        //level.Reset();
                        startGame = false;

                    }
                    else
                    {
                        startGame = true;
                    }
                }
            }  
        }
        if (!player.getAlive())
        {
            window.clear(sf::Color(0,255,0,255));
            level.DrawUpperSpikes(window);
            level.DrawLowerSpikes(window);
            window.draw(gameOverButton);
            player.Draw(window);
            window.display();
            // Poczekaj, aż gracz wciśnie czerwony przycisk
            continue;
        }

        if (!startGame)
        {
            window.clear(sf::Color(0,255,0,255));
            level.DrawUpperSpikes(window);
            level.DrawLowerSpikes(window);
            player.Draw(window);
            window.display();
            // Poczekaj, aż gracz wciśnie lewy przycisk myszy
            continue;
        }

        player.Update(deltaTime);
        window.clear(sf::Color(0,255,0,255));
        level.CheckCollison(player);
        level.Draw(window);
        player.Draw(window);
        window.display();
        
    }

    return 0;
}