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
        leftWall = BoxCollider(0, 0, 1, height);
        rightWall = BoxCollider(width-1, 0, 1, height);
        CreateUpperLowerSpikes();
        CreateLeftRightSpikes();
    }
    void DrawUpperSpikes(sf::RenderWindow &window) const;
    void DrawLowerSpikes(sf::RenderWindow &window) const;
    void DrawLeftSpikes(sf::RenderWindow &window) const;
    void DrawRightSpikes(sf::RenderWindow &window) const;
    void Draw(sf::RenderWindow &window) const;
    void CheckCollison(Player& player) const;

private:
    BoxCollider leftWall;
    BoxCollider rightWall;
    void CreateUpperLowerSpikes();
    void CreateLeftRightSpikes();
    sf::Texture tex;
    float mapWidth;
    float mapHeight;
    std::vector <Spike> upperSpikes;
    std::vector <Spike> lowerSpikes;
    std::vector <Spike> leftSpikes;
    std::vector <Spike> rightSpikes;
};

#endif // LEVEL_H