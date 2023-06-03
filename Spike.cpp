#include "Spike.hpp"

void Spike::RotateSprite180X()
{
    sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + GetHeight());
    sprite.setScale(sprite.getScale().x, sprite.getScale().y*-1);
}

void Spike::RotateSprite90()
{
    sprite.setRotation(90.0f);
}

void Spike::RotateSprite270()
{
    sprite.setRotation(270.0f);
}

void Spike::SetIndex(const unsigned int &newIndex)
{
    index = newIndex;
}

unsigned int Spike::GetIndex() const
{
    return index;
}

bool Spike::PlayerHit(const BoxCollider &playerCollider) const
{
    return isVisible && collider.CheckCollision(playerCollider);
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

void Spike::SetVisibile(const bool &vis)
{
    isVisible = vis;
}

bool Spike::GetVisibile() const
{
    return isVisible;
}

float Spike::GetHeight() const
{
    return height;
}

unsigned int Spike::GetWidth() const
{
    return width;
}