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
        this->CreateLowerSpikes();
        //this->CreateUpperSpikes();
    }
    //void CreateUpperSpikes();
    void CreateLowerSpikes();
    //void DrawUpperSpikes();
    void DrawLowerSpikes(sf::RenderWindow &window) const;
    void CheckCollison(Player& player) const;

private:
    sf::Texture tex;
    float mapWidth;
    float mapHeight;
    std::vector <Spike> upperSpikes;
    std::vector <Spike> lowerSpikes;
};

#endif // LEVEL_H