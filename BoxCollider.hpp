#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H
#include <SFML/Graphics.hpp>

class BoxCollider
{
public:
    BoxCollider() = default;
    BoxCollider(const int& X, const int& Y,const unsigned int& Width, const unsigned int& Height):
        x(X),
        y(Y),
        width(Width),
        height(Height)
    {
        ;
    }
    void SetPosition(const int& X, const int& Y);
    void SetPosition(const sf::Vector2f& pos);
    void Move(const sf::Vector2f& offset);
    bool CheckCollision(const BoxCollider& otherCollider) const;
    sf::Vector2i GetPosition() const;
    unsigned int GetWidth() const;
    unsigned int GetHeight() const;
    void SetActive(const bool& active);
    void SetWidth(const unsigned int& Width);
    void SetHeight(const unsigned int& Height);

    //void Update(const float& deltaTime, const float& windowWidth, const float& windowHeight);
private:
    int x = 0;
    int y = 0;
    unsigned int width = 0;
    unsigned int height = 0;
    bool isActive = true;
};

#endif // BOXCOLLIDER_H