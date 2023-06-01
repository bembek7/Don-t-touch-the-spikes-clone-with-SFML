#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Spike.hpp"
#include "Level.hpp"

static const float height = 600;
static const float width = 400;


int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Test", sf::Style::Titlebar | sf::Style::Close);
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    window.setPosition(sf::Vector2i(desktop.width / 2 - width / 2, desktop.height / 2 - height / 2));
    sf::Texture playerTexture;
    playerTexture.loadFromFile("Knight.png");
    Player player(playerTexture);
    sf::Texture spikeTexture;
    spikeTexture.loadFromFile("Pawn.png");
    Level level(spikeTexture, width, height);
    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        player.Update(deltaTime, width, height);
        window.clear(sf::Color(0,255,0,255));
        level.CheckCollison(player);
        level.Draw(window);
        player.Draw(window);
        window.display();
    }

    return 0;
}