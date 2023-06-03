#include "Player.hpp"
#include <math.h>
#include <iostream>

BoxCollider Player::GetCollider() const
{
    return collider;
}
void Player::Update(const float &deltaTime)
{
    timeFromLastJump += deltaTime;
    sf::Vector2f velocity(1.0f, 0.0f);
    velocity.x *= dir;
    velocity.x *= speed;


    // jump impulse
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && canJump && realesedJumpButton)
    {
        canJump = false;
        realesedJumpButton = false;
        timeFromLastJump = 0;
        velocity.y -=  sqrt(2 * jump * gravity) / deltaTime;
    }

    if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        realesedJumpButton = true;
    }

    // jump force after impulse for some time
    if(timeFromLastJump > jumpCooldown) canJump = true;
    else if(!canJump)
    {
        float v = std::sqrt(2 * jump * gravity);
        float a = jumpCooldown * jumpCooldown;
        float b = 2 * v * jumpCooldown - gravity * a;
        float c = -2 * gravity * jump;
        velocity.y -=  (- b + std::sqrt(b * b - 4 * a * c)) / (2 * a);
    }
    velocity.y += gravity;
    sprite.move(velocity * deltaTime);
    if(dir < 0) collider.SetPosition(sprite.getPosition().x + sprite.getTextureRect().width * sprite.getScale().x, sprite.getPosition().y);
    else collider.SetPosition(sprite.getPosition());
}

void Player::Draw(sf::RenderWindow& window) const
{
    window.draw(sprite);
}

void Player::Die()
{   
    isAlive = false;
}

void Player::TurnLeft()
{
    dir = -1;
    RotateSprite180Y();
}

void Player::TurnRight()
{
    dir = 1;
    RotateSprite180Y();
}

void Player::RotateSprite180Y()
{
    sprite.setScale(sprite.getScale().x*-1, sprite.getScale().y);
}

float Player::GetHeight() const
{
    return sprite.getTextureRect().height * std::abs(sprite.getScale().y);
}

bool Player::getAlive() const
{
    return isAlive;
}

void Player::setAlive(const bool& newAlive)
{
    isAlive = newAlive;
}