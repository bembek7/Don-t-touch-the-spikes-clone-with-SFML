#include <SFML/Graphics.hpp>
#include "Player.hpp"

static const float height = 700;
static const float width = 400;


int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Test", sf::Style::Titlebar | sf::Style::Close);
    sf::Texture playerTexture;
    playerTexture.loadFromFile("Knight.png");
    Player player(playerTexture);
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
        player.Draw(window);
        window.display();
    }

    return 0;
}