#include "BoxCollider.hpp"

void BoxCollider::SetPosition(int X, int Y)
{
    x = X;
    y = Y;
}

void BoxCollider::SetPosition(sf::Vector2f pos)
{   
    x = pos.x;
    y = pos.y;
}

void BoxCollider::Move(sf::Vector2f offset)
{   
    x += offset.x;
    y += offset.y;
}

bool BoxCollider::CheckCollision(const BoxCollider &otherCollider) const
{   
    bool xOverlap = int(x + width) >= otherCollider.GetPosition().x && int(otherCollider.GetPosition().x + otherCollider.GetWidth()) >= x;
    bool yOverlap = int(y + height) >= otherCollider.GetPosition().y && int(otherCollider.GetPosition().y + otherCollider.height) >= y;

    return xOverlap && yOverlap && isActive;
}

sf::Vector2i BoxCollider::GetPosition() const
{
    return sf::Vector2i(x, y);
}

unsigned int BoxCollider::GetWidth() const
{
    return width;
}

unsigned int BoxCollider::GetHeight() const
{
    return height;
}

void BoxCollider::SetActive(bool active)
{
    isActive = active;
}

void BoxCollider::SetWidth(unsigned int Width)
{
    width = Width;
}

void BoxCollider::SetHeight(unsigned int Height)
{
    height = Height;
}
