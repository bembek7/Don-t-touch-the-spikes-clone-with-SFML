#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "BoxCollider.hpp"

class Player
{
public:
    Player(const sf::Texture& tex)
    {
        sprite.setTexture(tex);
        sprite.setScale(0.06f, 0.06f);
        sprite.setPosition(0.f,0.f);
        collider = BoxCollider(0, 0, sprite.getTextureRect().width * std::abs(sprite.getScale().x), sprite.getTextureRect().height * std::abs(sprite.getScale().y));
    }
    BoxCollider GetCollider()const;
    void Update(const float& deltaTime, const float& windowWidth, const float& windowHeight);
    void Draw(sf::RenderWindow& window) const;
    void Die();
private:
    BoxCollider collider;
    sf::Sprite sprite;
    float dir = 1.f;
    float speed = 250.f;
    float gravity = 450.f;
    float jump = 6.f;
    bool flipToLeft = true;
    bool flipToRight = false;
    bool canJump = true;
    bool realesedJumpButton = true;
    float jumpCooldown = 0.07f;
    float timeFromLastJump = 0.07f;
};

#endif // PLAYER_H