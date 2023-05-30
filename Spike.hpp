#ifndef SPIKE_H
#define SPIKE_H
#include <SFML/Graphics.hpp>

class Spike
{
public:
    Spike(const sf::Texture& tex)
    {
        sprite.setTexture(tex);
        sprite.setScale(0.07f, 0.07f);
        sprite.setPosition(0.f,0.f);
    }

    //void Update(const float& deltaTime, const float& windowWidth, const float& windowHeight);
    void Draw(sf::RenderWindow& window) const;
private:
    sf::Sprite sprite;
};

#endif // SPIKE_H