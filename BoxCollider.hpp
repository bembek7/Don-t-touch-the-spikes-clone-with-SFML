#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H
#include <SFML/Graphics.hpp>

class BoxCollider
{
public:
    BoxCollider() = default;
    BoxCollider(int X, int Y, unsigned int Width, unsigned int Height):
        x(X),
        y(Y),
        width(Width),
        height(Height)
    {
        ;
    }
    void SetPosition(int X, int Y);
    void SetPosition(sf::Vector2f pos);
    void Move(sf::Vector2f offset);
    bool CheckCollision(const BoxCollider& otherCollider) const;
    sf::Vector2i GetPosition() const;
    unsigned int GetWidth() const;
    unsigned int GetHeight() const;
    void SetActive(bool active);
    void SetWidth(unsigned int Width);
    void SetHeight(unsigned int Height);

private:
    int x = 0;
    int y = 0;
    unsigned int width = 0;
    unsigned int height = 0;
    bool isActive = true;
};

#endif // BOXCOLLIDER_H