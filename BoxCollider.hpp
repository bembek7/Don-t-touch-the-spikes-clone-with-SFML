#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H
#include <SFML/Graphics.hpp>

class BoxCollider
{
public:
    BoxCollider(const int& x, const int& y,const unsigned int& Width, const unsigned int& Height):
        width(Width),
        height(Height)
    {
        ;
    }
    void SetPosition(const int& x, const int& y);
    bool CheckCollision(const BoxCollider& otherCollider) const;
    sf::Vector2i GetPosition() const;
    unsigned int GetWidth() const;
    unsigned int GetHeight() const;

    //void Update(const float& deltaTime, const float& windowWidth, const float& windowHeight);
private:
    int x;
    int y;
    unsigned int width;
    unsigned int height;
};

#endif // BOXCOLLIDER_H