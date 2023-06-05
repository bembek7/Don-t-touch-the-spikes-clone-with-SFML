#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Spike.hpp"
#include "Level.hpp"
#include <string>

class Game
{
public:
    Game(const unsigned int& WindowWidth, const unsigned int& WindowHeight, const std::vector<sf::Texture>& texes, const std::string& spikeTextureFilename)
    {
        windowWidth = WindowWidth;
        windowHeight = WindowHeight;
        playerTextures = texes;
        spikeTexture.loadFromFile(spikeTextureFilename);
    }

    void Play();

private:
    sf::RenderWindow window;
    std::vector<sf::Texture> playerTextures;
    sf::Texture spikeTexture;
    unsigned int windowWidth;
    unsigned int windowHeight;
};

bool isMouseOverButton(const sf::RectangleShape& button, const sf::Vector2f& mousePos);

#endif // GAME_H