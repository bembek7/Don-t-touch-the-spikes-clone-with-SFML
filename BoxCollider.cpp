#include "BoxCollider.hpp"

void BoxCollider::SetPosition(const int &X, const int &Y)
{
    x = X;
    y = Y;
}

bool BoxCollider::CheckCollision(const BoxCollider &otherCollider) const
{   
    bool xOverlap = int(x + width) >= otherCollider.GetPosition().x && int(otherCollider.GetPosition().x + otherCollider.GetWidth()) >= x;
    bool yOverlap = int(y + height) >= otherCollider.GetPosition().y && int(otherCollider.GetPosition().y + otherCollider.height) >= y;

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
