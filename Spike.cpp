#include "Spike.hpp"

void Spike::RotateSprite180X()
{
    sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + GetHeight());
    sprite.setScale(sprite.getScale().x, sprite.getScale().y*-1);
}

void Spike::RotateSprite90()
{
    sprite.setPosition(sprite.getPosition().x + GetHeight(), sprite.getPosition().y);
    unsigned int collHeight = collider.GetHeight();
    collider.SetHeight(collider.GetWidth());
    collider.SetWidth(collHeight);
    sprite.setRotation(90.0f);
}

void Spike::RotateSprite270()
{
    sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + GetWidth());
    unsigned int collHeight = collider.GetHeight();
    collider.SetHeight(collider.GetWidth());
    collider.SetWidth(collHeight);
    sprite.setRotation(270.0f);
}

void Spike::Move(sf::Vector2f offset)
{
    sprite.move(offset);
    collider.Move(offset);
}

bool Spike::PlayerHit(const BoxCollider &playerCollider) const
{
    return isVisible && collider.CheckCollision(playerCollider);
}

void Spike::Draw(sf::RenderWindow &window) const
{
    window.draw(sprite);
}

void Spike::SetPosition(sf::Vector2f pos)
{
    sprite.setPosition(pos);
    collider.SetPosition(pos.x, pos.y);
}

void Spike::SetVisibile(bool vis)
{
    isVisible = vis;
    collider.SetActive(vis);
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