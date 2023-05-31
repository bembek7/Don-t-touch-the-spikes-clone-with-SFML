#include "BoxCollider.hpp"

void BoxCollider::SetPosition(const int &X, const int &Y)
{
    x = X;
    y = Y;
}

bool BoxCollider::CheckCollision(const BoxCollider &otherCollider) const
{   
    bool xOverlap = x + width >= otherCollider.GetPosition().x && otherCollider.GetPosition().x + otherCollider.GetWidth() >= x;
    bool yOverlap = y + height >= otherCollider.GetPosition().y && otherCollider.GetPosition().y + otherCollider.height >= y;

    return xOverlap && yOverlap;
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
