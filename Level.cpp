#include "Spike.hpp"
#include "Level.hpp"
#include <algorithm>
#include <random>
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

void Level::DrawLeftSpikes(sf::RenderWindow &window) const
{
    for (auto& spike : leftSpikes)
    {
        if(spike.GetVisibile())spike.Draw(window);
    }
}

void Level::DrawRightSpikes(sf::RenderWindow &window) const
{
    for (auto& spike : rightSpikes)
    {
        if(spike.GetVisibile())spike.Draw(window);
    }
}

void Level::Draw(sf::RenderWindow &window) const
{
    DrawLowerSpikes(window);
    DrawUpperSpikes(window);
    DrawLeftSpikes(window);
    DrawRightSpikes(window);
}

void Level::CheckCollison(Player* player)
{
    for (auto& spike : lowerSpikes)
    {
        if(spike.PlayerHit(player->GetCollider()))
        {
            player->Die();
            return;
        }
    }

    for (auto& spike : upperSpikes)
    {
        if(spike.PlayerHit(player->GetCollider()))
        {
            player->Die();
            return;
        }
    }
    // kolejne pętle z bocznymi

    if(leftWall.CheckCollision(player->GetCollider()))
    {
        if(spikesToCreate < leftSpikes.size()-safeSpots * safeSpotWidth)spikesToCreate++;
        score++;
        player->TurnRight();
        ChangeLeftRightSpikes(rightSpikes);
        MakeWallInvisibile(leftSpikes);
        MoveSpikeWall(leftSpikes, offsetToWall*-1);
        if(score % 10 == 0 && safeSpots > 1) safeSpots--;
        return;
    }

    if(rightWall.CheckCollision(player->GetCollider()))
    {
        if(spikesToCreate < leftSpikes.size()-safeSpots * safeSpotWidth)spikesToCreate++;
        score++;
        player->TurnLeft();
        ChangeLeftRightSpikes(leftSpikes);
        MakeWallInvisibile(rightSpikes);
        MoveSpikeWall(rightSpikes, offsetToWall*-1);
        if(score % 10 == 0 && safeSpots > 1) safeSpots--;
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

void Level::CreateLeftRightSpikes()
{
    float tempHeight = mapHeight;
    while (tempHeight > 0)
    {
        Spike leftspike(tex);
        Spike rightspike(tex);
        if (tempHeight <= 2 * leftspike.GetHeight() + leftspike.GetWidth())
        {
            tempHeight = leftspike.GetHeight();
            break;
        }
        leftSpikes.push_back(leftspike);
        rightSpikes.push_back(rightspike);
        tempHeight -= float(leftspike.GetWidth());
    }

    for (auto& spike : leftSpikes)
    {
        spike.SetPosition(sf::Vector2f(spike.GetHeight(), tempHeight));
        spike.RotateSprite90();
        tempHeight += float(spike.GetWidth());
    }
    Spike spike(tex);
    tempHeight = spike.GetHeight() + spike.GetWidth();

    for (auto& spike : rightSpikes)
    {
        spike.SetPosition(sf::Vector2f(mapWidth - spike.GetHeight(), tempHeight));
        spike.RotateSprite270();
        tempHeight += float(spike.GetWidth());
    }

}

void Level::ChangeLeftRightSpikes(std::vector<Spike>& wall)
{
    std::random_device dev;
	std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distSpikeWidth(0, leftSpikes[0].GetWidth()/2);
    offsetToWall = distSpikeWidth(rng);
    if(offsetToWall % 2) offsetToWall *= -1;
    MoveSpikeWall(wall, offsetToWall);
    MakeWallInvisibile(wall);
    std::vector<unsigned int> positions;
    for (unsigned int i = 0; i < wall.size(); i++)
    {
        positions.push_back(i);
    }
    for (unsigned int i = 0; i < safeSpots; i++)
    {
        std::uniform_int_distribution<std::mt19937::result_type> dist(0, positions.size()-1-safeSpotWidth);
        unsigned int rand = dist(rng);
        positions.erase(positions.begin() + rand, positions.begin() + rand + safeSpotWidth);
    }
    std::shuffle(std::begin(positions), std::end(positions), rng);
    for (unsigned int i = 0; i < spikesToCreate; i++)
    {
        wall[positions.back()].SetVisibile(true);
        positions.pop_back();
    }

}

void Level::MakeWallInvisibile(std::vector<Spike>& wall)
{
    for (auto& spike : wall)
    {
        spike.SetVisibile(false);
    }
}

void Level::MoveSpikeWall(std::vector<Spike> &wall, const int& offset)
{
    for (auto& spike : wall)
    {
        spike.Move(sf::Vector2f(0, offset));
    }
}
