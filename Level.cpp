#include "Spike.hpp"
#include "Level.hpp"
#include <algorithm>
#include <random>
void Level::DrawUpperSpikes(sf::RenderWindow &window) const
{
    for (auto& spike : upperSpikes)
    {
        spike->Draw(window);
    }
}

void Level::DrawLowerSpikes(sf::RenderWindow &window) const
{
    for (auto& spike : lowerSpikes)
    {
        spike->Draw(window);
    }
}

void Level::DrawLeftSpikes(sf::RenderWindow &window) const
{
    for (auto& spike : leftSpikes)
    {
        if(spike->GetVisibile())spike->Draw(window);
    }
}

void Level::DrawRightSpikes(sf::RenderWindow &window) const
{
    for (auto& spike : rightSpikes)
    {
        if(spike->GetVisibile())spike->Draw(window);
    }
}

void Level::Draw(sf::RenderWindow &window) const
{
    DrawLowerSpikes(window);
    DrawUpperSpikes(window);
    DrawLeftSpikes(window);
    DrawRightSpikes(window);
}

void Level::CheckCollison(Player& player)
{
    SpikeWallCollision(lowerSpikes, player);
    SpikeWallCollision(upperSpikes, player);
    SpikeWallCollision(leftSpikes, player);
    SpikeWallCollision(rightSpikes, player);

    if(leftWall.CheckCollision(player.GetCollider()))
    {
        if(spikesToCreate < leftSpikes.size()-safeSpots * safeSpotWidth)spikesToCreate++;
        score++;
        player.TurnRight();
        player.IncreaseSpeed();
        ChangeLeftRightSpikes(rightSpikes);
        MakeWallInvisibile(leftSpikes);
        MoveSpikeWall(leftSpikes, offsetToWall*-1);
        if(score % 10 == 0 && safeSpots > 1) safeSpots--;
        return;
    }

    if(rightWall.CheckCollision(player.GetCollider()))
    {
        if(spikesToCreate < leftSpikes.size()-safeSpots * safeSpotWidth)spikesToCreate++;
        score++;
        player.TurnLeft();
        player.IncreaseSpeed();
        ChangeLeftRightSpikes(leftSpikes);
        MakeWallInvisibile(rightSpikes);
        MoveSpikeWall(rightSpikes, offsetToWall*-1);
        if(score % 10 == 0 && safeSpots > 1) safeSpots--;
        return;
    }
}

void Level::Reset()
{
    MakeWallInvisibile(rightSpikes);
    MakeWallInvisibile(leftSpikes);
    offsetToWall = 0;
    safeSpots = 2;
    spikesToCreate = 0;
    score = 0;
}

void Level::CreateUpperLowerSpikes()
{
    float tempWidth = mapWidth;
    while (tempWidth > 0)
    {
        auto spike = std::make_unique<Spike>(tex);
        tempWidth -= float(spike->GetWidth());
        lowerSpikes.push_back(std::move(spike));
        upperSpikes.push_back(std::make_unique<Spike>(tex));
    }
    tempWidth = 0;

    for (auto& spike : lowerSpikes)
    {
        spike->SetPosition(sf::Vector2f(tempWidth, mapHeight - spike->GetHeight()));
        tempWidth += float(spike->GetWidth());
    }

    tempWidth = 0;

    for (auto& spike : upperSpikes)
    {
        spike->SetPosition(sf::Vector2f(tempWidth, 0));
        spike->RotateSprite180X();
        tempWidth += float(spike->GetWidth());
    }
}

void Level::CreateLeftRightSpikes()
{
    float tempHeight = mapHeight;
    while (tempHeight > 0)
    {
        auto leftspike = std::make_unique<Spike>(tex);
        auto rightspike = std::make_unique<Spike>(tex);
        if (tempHeight <= 2 * leftspike->GetHeight() + leftspike->GetWidth())
        {
            tempHeight = leftspike->GetHeight();
            break;
        }
        tempHeight -= float(leftspike->GetWidth());
        leftSpikes.push_back(std::move(leftspike));
        rightSpikes.push_back(std::move(rightspike));
    }

    for (auto& spike : leftSpikes)
    {
        spike->SetPosition(sf::Vector2f(0, tempHeight));
        spike->RotateSprite90();
        tempHeight += float(spike->GetWidth());
    }
    Spike spike(tex);
    tempHeight = spike.GetHeight() + spike.GetWidth();

    for (auto& spike : rightSpikes)
    {
        spike->SetPosition(sf::Vector2f(mapWidth - spike->GetHeight(), tempHeight));
        spike->RotateSprite270();
        tempHeight += float(spike->GetWidth());
    }

}

void Level::ChangeLeftRightSpikes(std::vector <std::unique_ptr<Spike>>& wall)
{
    std::random_device dev;
	std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distSpikeWidth(0, leftSpikes[0]->GetWidth()/2);
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
        wall[positions.back()]->SetVisibile(true);
        positions.pop_back();
    }

}

void Level::MakeWallInvisibile(std::vector <std::unique_ptr<Spike>>& wall)
{
    for (auto& spike : wall)
    {
        spike->SetVisibile(false);
    }
}

void Level::MoveSpikeWall(std::vector <std::unique_ptr<Spike>>& wall, const int& offset)
{
    for (auto& spike : wall)
    {
        spike->Move(sf::Vector2f(0, offset));
    }
}

void Level::SpikeWallCollision(std::vector <std::unique_ptr<Spike>>& wall, Player& player) const
{
    for (auto& spike : wall)
    {
        if(spike->PlayerHit(player.GetCollider()))
        {
            player.Die();
            return;
        }
    }
}