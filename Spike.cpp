#include "Spike.hpp"

void Spike::RotateSprite180()
{
    sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + GetHeight());
    sprite.setScale(sprite.getScale().x, sprite.getScale().y*-1);
}

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
    collider.SetPosition(pos.x, pos.y);
}

float Spike::GetHeight() const
{
    return height;
}

unsigned int Spike::GetWidth() const
{
    return width;
}