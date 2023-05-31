#include "Spike.hpp"
#include "Player.hpp"
//void Spike::Update(const float& deltaTime, const float& windowWidth, const float& windowHeight){}

bool Spike::PlayerHit(const BoxCollider &playerCollider) const
{
    return collider.CheckCollision(playerCollider);
}

void Spike::Draw(sf::RenderWindow &window) const
{
    window.draw(sprite);
}