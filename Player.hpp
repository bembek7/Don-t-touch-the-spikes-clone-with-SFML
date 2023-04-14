#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

class Player
{
public:
    Player(const sf::Texture& tex)
    {
        sprite.setTexture(tex);
        sprite.setScale(0.05f, 0.05f);
        sprite.setPosition(0.f,0.f);
    }

    void Update(const float& deltaTime, const float& windowWidth, const float& windowHeight);
    void Draw(sf::RenderWindow& window) const;
private:
    sf::Sprite sprite;
    float dir = 1.f;
    float speed = 200.f;
    float gravity = 150.f;
    float jump = 200.f;
    bool flipToLeft = true;
    bool flipToRight = false;
};

#endif // PLAYER_H