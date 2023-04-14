#include "Player.hpp"

void Player::Update(const float& deltaTime, const float& windowWidth, const float& windowHeight)
{
    sf::Vector2f velocity(1.0f, 0.0f);
    velocity.x *= dir;
    velocity.x *= speed;
    if(sprite.getPosition().x + sprite.getTextureRect().width * std::abs(sprite.getScale().x) >= windowWidth && flipToLeft)
    {
        flipToLeft = false;
        dir = -1;
        sprite.setScale(sprite.getScale().x*-1, sprite.getScale().y);
        sprite.move(sprite.getTextureRect().width * std::abs(sprite.getScale().x), 0.f);
        flipToRight = true;
    }
    if(sprite.getPosition().x + sprite.getTextureRect().width * sprite.getScale().x < 0 && flipToRight)
    {
        flipToRight = false;
        dir = 1;
        sprite.setScale(sprite.getScale().x*-1, sprite.getScale().y);
        sprite.move(sprite.getTextureRect().width * sprite.getScale().x * -1, 0.f);
        flipToLeft = true;
    }

    // has to be last, probably won't be needed after adding spikes on the bottom
    if(sprite.getPosition().y + sprite.getTextureRect().height * sprite.getScale().y + gravity * deltaTime < windowHeight)
        velocity.y += gravity;
    sprite.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow& window) const
{
    window.draw(sprite);
}