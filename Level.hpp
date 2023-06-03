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
    Level(const sf::Texture& spikeTexture, const float& width, const float& height, const float& playerHeight)
    {
        tex = spikeTexture;
        mapWidth = width;
        mapHeight = height;
        leftWall = BoxCollider(0, 0, 1, height);
        rightWall = BoxCollider(width-1, 0, 1, height);
        CreateUpperLowerSpikes();
        CreateLeftRightSpikes();
        safeSpotWidth = playerHeight * 3 / upperSpikes[0].GetWidth() + 1;
        MakeWallInvisibile(rightSpikes);
    }
    void DrawUpperSpikes(sf::RenderWindow &window) const;
    void DrawLowerSpikes(sf::RenderWindow &window) const;
    void DrawLeftSpikes(sf::RenderWindow &window) const;
    void DrawRightSpikes(sf::RenderWindow &window) const;
    void Draw(sf::RenderWindow &window) const;
    void CheckCollison(Player& player);

private:
    BoxCollider leftWall;
    BoxCollider rightWall;
    void MakeWallInvisibile(std::vector<Spike> &wall);
    void CreateUpperLowerSpikes();
    void CreateLeftRightSpikes();
    void ChangeLeftRightSpikes(std::vector<Spike>& wall);
    sf::Texture tex;
    float mapWidth;
    float mapHeight;
    unsigned int safeSpotWidth; // it's in spikes
    unsigned int safeSpots;
    unsigned int spikesToCreate = 0;
    std::vector <Spike> upperSpikes;
    std::vector <Spike> lowerSpikes;
    std::vector <Spike> leftSpikes;
    std::vector <Spike> rightSpikes;
};

#endif // LEVEL_H