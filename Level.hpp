#ifndef LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Spike.hpp"

class Level
{
public:
    Level(const sf::Texture& mapTexture, const float& mapWidth, const float& mapHeight)
    {
       tex = mapTexture;
       width = mapWidth;

    }
    void CreateUpperSpikes();
    void CreateLowerSpikes();
    void DrawUpperSpikes();
    void DrawLowerSpikes();
    
private:
    const sf::Texture& tex;
    const float width;
    const float height;
    std::vector <Spike> upperSpikes;
    std::vector <Spike> lowerSpikes;
};

#endif // LEVEL_H