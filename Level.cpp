#include "Spike.hpp"
#include "Level.hpp"

void Level::CreateLowerSpikes()
{
    float tempWidth = mapWidth;
    while (tempWidth > 0)
    {
        Spike spike(tex);
        lowerSpikes.push_back(spike);
        tempWidth -= float(Spike::GetWidth());
    }
    tempWidth = 0;

    for (auto& spike : lowerSpikes)
    {
        spike.SetPosition(sf::Vector2f(tempWidth, mapHeight - spike.GetHeight()));
        tempWidth += float(spike.GetWidth());
    }
    
}

void Level::DrawLowerSpikes(sf::RenderWindow &window) const
{
    for (auto& spike : lowerSpikes)
    {
        spike.Draw(window);
    }
}