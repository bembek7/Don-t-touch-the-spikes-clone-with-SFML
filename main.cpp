#include <SFML/Graphics.hpp>
#include "Player.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 700), "Test");
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
        player.Update(deltaTime, window.getSize().x);
        
        window.clear(sf::Color(0,255,0,255));
        player.Draw(window);
        window.display();
    }

    return 0;
}