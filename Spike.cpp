#include "Spike.hpp"
#include "Player.hpp"

bool Spike::PlayerHit(const BoxCollider &playerCollider) const
{
    return collider.CheckCollision(playerCollider);
}

void Spike::Draw(sf::RenderWindow &window) const
{
    window.draw(sprite);
}

void Spike::SetPosition(const sf::Vector2f& pos)
{
    sprite.setPosition(pos);
    collider = BoxCollider(pos.x, pos.y, sprite.getTextureRect().width * std::abs(sprite.getScale().x), sprite.getTextureRect().height * std::abs(sprite.getScale().y));
}

float Spike::GetHeight()
{
    return height;
}

unsigned int Spike::GetWidth()
{
    return width;
}