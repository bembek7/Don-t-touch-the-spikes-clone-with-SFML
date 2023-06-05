#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "BoxCollider.hpp"

class Player
{
public:
    Player () = default;
    Player(const sf::Texture& tex)
    {
        sprite.setTexture(tex);
        sprite.setScale(0.046f, 0.046f);
        sprite.setPosition(200.f,300.f);
        collider = BoxCollider(sprite.getPosition().x, sprite.getPosition().y, sprite.getTextureRect().width * std::abs(sprite.getScale().x), sprite.getTextureRect().height * std::abs(sprite.getScale().y));
    }

    ~Player() {} // Destructor
     
    BoxCollider GetCollider()const;
    void Update(const float& deltaTime);
    void Draw(sf::RenderWindow& window) const;
    void Die();
    void TurnLeft();
    void TurnRight();
    void RotateSprite180Y();
    float GetHeight() const;
    bool getAlive() const;
    void setAlive(const bool& newAlive);
    
private:
    BoxCollider collider;
    sf::Sprite sprite;
    float dir = 1.f;
    float speed = 250.f;
    float gravity = 400.f;
    float jump = 6.f;
    bool canJump = true;
    bool realesedJumpButton = true;
    float jumpCooldown = 0.07f;
    float timeFromLastJump = 0.07f;
    bool isAlive = true;
};

#endif // PLAYER_H