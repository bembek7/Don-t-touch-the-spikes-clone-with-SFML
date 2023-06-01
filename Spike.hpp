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
        collider = BoxCollider(0, 0, sprite.getTextureRect().width * std::abs(sprite.getScale().x), sprite.getTextureRect().height * std::abs(sprite.getScale().y));
    }
    void RotateSprite180();
    bool PlayerHit(const BoxCollider& playerCollider) const;
    void Draw(sf::RenderWindow& window) const;
    unsigned int GetWidth() const;
    float GetHeight() const;
    void SetPosition(const sf::Vector2f& pos);

private:
    BoxCollider collider;
    sf::Sprite sprite;
    unsigned int width = 25;
    float scaleFactor;
    float height;
};

#endif // SPIKE_H