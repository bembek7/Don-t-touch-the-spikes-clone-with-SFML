#ifndef LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Spike.hpp"
#include "BoxCollider.hpp"
#include "Player.hpp"
#include <iostream>
#include <memory>

class Level
{
public:
    Level() = default;
    Level(const sf::Texture& spikeTexture, const float& width, const float& height, const float& playerHeight)
    {
        tex = spikeTexture;
        mapWidth = width;
        mapHeight = height;
        leftWall = BoxCollider(0, 0, 1, height);
        rightWall = BoxCollider(width-1, 0, 1, height);
        CreateUpperLowerSpikes();
        CreateLeftRightSpikes();
        safeSpotWidth = playerHeight * 2.5f / upperSpikes[0]->GetWidth() + 1;
        MakeWallInvisibile(rightSpikes);
        MakeWallInvisibile(leftSpikes);
    }
    void Draw(sf::RenderWindow &window) const;
    void CheckCollison(Player& player);
    void Reset();
private:
    BoxCollider leftWall;
    BoxCollider rightWall;
    void DrawUpperSpikes(sf::RenderWindow &window) const;
    void DrawLowerSpikes(sf::RenderWindow &window) const;
    void DrawLeftSpikes(sf::RenderWindow &window) const;
    void DrawRightSpikes(sf::RenderWindow &window) const;
    void MakeWallInvisibile(std::vector <std::unique_ptr<Spike>> &wall);
    void SpikeWallCollision(std::vector <std::unique_ptr<Spike>> &wall, Player& player) const;
    void MoveSpikeWall(std::vector <std::unique_ptr<Spike>> &wall, const int &offset);
    void CreateUpperLowerSpikes();
    void CreateLeftRightSpikes();
    void ChangeLeftRightSpikes(std::vector <std::unique_ptr<Spike>>& wall);
    sf::Texture tex;
    float mapWidth;
    float mapHeight;
    int offsetToWall = 0;
    unsigned int safeSpotWidth; // it's in spikes
    unsigned int safeSpots = 2;
    unsigned int spikesToCreate = 0;
    unsigned int score = 0;
    std::vector <std::unique_ptr<Spike>> upperSpikes;
    std::vector <std::unique_ptr<Spike>> lowerSpikes;
    std::vector <std::unique_ptr<Spike>> leftSpikes;
    std::vector <std::unique_ptr<Spike>> rightSpikes;
};

#endif // LEVEL_H