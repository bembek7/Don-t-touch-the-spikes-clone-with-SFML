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
        int spriteWidth = width-5;
        scaleFactor = spriteWidth / sprite.getLocalBounds().width;
        sprite.setScale(scaleFactor, scaleFactor);
        height = sprite.getGlobalBounds().height;
        collider = BoxCollider(0, 0, sprite.getTextureRect().width * std::abs(sprite.getScale().x), sprite.getTextureRect().height * std::abs(sprite.getScale().y));
    }
    void RotateSprite180X();
    bool PlayerHit(const BoxCollider& playerCollider) const;
    void Draw(sf::RenderWindow& window) const;
    unsigned int GetWidth() const;
    float GetHeight() const;
    void SetPosition(const sf::Vector2f& pos);
    void SetVisibile(const bool& vis);
    bool GetVisibile() const;
    void RotateSprite90();
    void RotateSprite270();
    void Move(const sf::Vector2f& offset);

private:
    BoxCollider collider;
    sf::Sprite sprite;
    unsigned int width = 34;
    float scaleFactor;
    float height;
    bool isVisible = true;
};

#endif // SPIKE_H