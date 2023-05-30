#include "Spike.hpp"

//void Spike::Update(const float& deltaTime, const float& windowWidth, const float& windowHeight){}

void Spike::Draw(sf::RenderWindow& window) const
{
    window.draw(sprite);
}