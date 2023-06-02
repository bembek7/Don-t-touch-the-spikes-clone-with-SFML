#include "Spike.hpp"
#include "Level.hpp"

void Level::DrawUpperSpikes(sf::RenderWindow &window) const
{
    for (auto& spike : upperSpikes)
    {
        spike.Draw(window);
    }
}

void Level::DrawLowerSpikes(sf::RenderWindow &window) const
{
    for (auto& spike : lowerSpikes)
    {
        spike.Draw(window);
    }
}

void Level::Draw(sf::RenderWindow &window) const
{
    DrawLowerSpikes(window);
    DrawUpperSpikes(window);
}

void Level::CheckCollison(Player &player) const
{
    for (auto& spike : lowerSpikes)
    {
        if(spike.PlayerHit(player.GetCollider()))
        {
            player.Die();
            return;
        }
    }

    for (auto& spike : upperSpikes)
    {
        if(spike.PlayerHit(player.GetCollider()))
        {
            player.Die();
            return;
        }
    }
    // kolejne pętle z bocznymi

    if(leftWall.CheckCollision(player.GetCollider()))
    {
        player.TurnRight();
        //generowanie prawej ściany
        //increment ilość odbić - score
        return;
    }

    if(rightWall.CheckCollision(player.GetCollider()))
    {
        player.TurnLeft();
        //generowanie lewej ściany
        //increment ilość odbić - score
        return;
    }
}

void Level::CreateUpperLowerSpikes()
{
    float tempWidth = mapWidth;
    while (tempWidth > 0)
    {
        Spike lowspike(tex);
        Spike upspike(tex);
        lowerSpikes.push_back(lowspike);
        upperSpikes.push_back(upspike);
        tempWidth -= float(lowspike.GetWidth());
    }
    tempWidth = 0;

    for (auto& spike : lowerSpikes)
    {
        spike.SetPosition(sf::Vector2f(tempWidth, mapHeight - spike.GetHeight()));
        tempWidth += float(spike.GetWidth());
    }

    tempWidth = 0;

    for (auto& spike : upperSpikes)
    {
        spike.SetPosition(sf::Vector2f(tempWidth, 0));
        spike.RotateSprite180X();
        tempWidth += float(spike.GetWidth());
    }
}
