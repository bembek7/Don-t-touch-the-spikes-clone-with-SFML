#ifndef SPIKE_H
#define SPIKE_H
#include <SFML/Graphics.hpp>
#include "BoxCollider.hpp"

class Spike
{
public:
    Spike(const sf::Texture& tex)
    {
        sprite.setTexture(tex);
        scaleFactor = width / sprite.getLocalBounds().width;
        sprite.setScale(scaleFactor, scaleFactor);
        height = sprite.getGlobalBounds().height;
    }
    bool PlayerHit(const BoxCollider& playerCollider) const;
    void Draw(sf::RenderWindow& window) const;
    static unsigned int GetWidth();
    float GetHeight();
    void SetPosition(const sf::Vector2f& pos);

private:
    BoxCollider collider;
    sf::Sprite sprite;
    static const unsigned int width = 25;
    float scaleFactor;
    float height;
};

#endif // SPIKE_H