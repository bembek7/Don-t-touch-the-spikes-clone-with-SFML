#ifndef LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Spike.hpp"
#include "BoxCollider.hpp"
#include "Player.hpp"

class Level
{
public:
    Level(const sf::Texture& spikeTexture, const float& width, const float& height)
    {
        tex = spikeTexture;
        mapWidth = width;
        mapHeight = height;
        CreateUpperLowerSpikes();
    }
    void DrawUpperSpikes(sf::RenderWindow &window) const;
    void DrawLowerSpikes(sf::RenderWindow &window) const;
    void Draw(sf::RenderWindow &window) const;
    void CheckCollison(Player& player) const;

private:
    void CreateUpperLowerSpikes();
    sf::Texture tex;
    float mapWidth;
    float mapHeight;
    std::vector <Spike> upperSpikes;
    std::vector <Spike> lowerSpikes;
};

#endif // LEVEL_H