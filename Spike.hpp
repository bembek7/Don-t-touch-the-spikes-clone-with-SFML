#ifndef SPIKE_H
#define SPIKE_H
#include <SFML/Graphics.hpp>
#include "BoxCollider.hpp"

class Spike
{
public:
    Spike(const sf::Texture& tex, const sf::Vector2f& pos)
    {
        sprite.setTexture(tex);
        sprite.setScale(0.07f, 0.07f);
        sprite.setPosition(pos);
        collider = BoxCollider(pos.x, pos.y, sprite.getTextureRect().width * std::abs(sprite.getScale().x), sprite.getTextureRect().height * std::abs(sprite.getScale().y));
    }
    bool PlayerHit(const BoxCollider& playerCollider) const;
    //void Update(const float& deltaTime, const float& windowWidth, const float& windowHeight);
    void Draw(sf::RenderWindow& window) const;
private:
    BoxCollider collider;
    sf::Sprite sprite;
    unsigned int width;
};

#endif // SPIKE_H