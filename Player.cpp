#include "Player.hpp"
#include <math.h>

void Player::Update(const float& deltaTime, const float& windowWidth, const float& windowHeight)
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

    // flipping after hitting right wall
    if(sprite.getPosition().x + sprite.getTextureRect().width * std::abs(sprite.getScale().x) >= windowWidth && flipToLeft)
    {
        flipToLeft = false;
        dir = -1;
        sprite.setScale(sprite.getScale().x*-1, sprite.getScale().y);
        sprite.move(sprite.getTextureRect().width * std::abs(sprite.getScale().x), 0.f);
        flipToRight = true;
    }
    // flipping after hitting left wall
    else if(sprite.getPosition().x + sprite.getTextureRect().width * sprite.getScale().x < 0 && flipToRight)
    {
        flipToRight = false;
        dir = 1;
        sprite.setScale(sprite.getScale().x*-1, sprite.getScale().y);
        sprite.move(sprite.getTextureRect().width * sprite.getScale().x * -1, 0.f);
        flipToLeft = true;
    }

    // has to be last, probably won't be needed after adding spikes on the bottom
    // applying gravity if player is not on the floor
    if(sprite.getPosition().y + sprite.getTextureRect().height * sprite.getScale().y + gravity * deltaTime < windowHeight)
        velocity.y += gravity;
    sprite.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow& window) const
{
    window.draw(sprite);
}