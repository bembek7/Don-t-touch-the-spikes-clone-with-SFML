#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 500), "SFML works!");
    float radius = 20.f;
    sf::CircleShape shape(radius);
    shape.setFillColor(sf::Color::Green);
    float dir = 1.f;
    float speed = 0.25f;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        shape.move(dir*speed,0);
        if(shape.getPosition().x + radius*2 >= window.getSize().x || shape.getPosition().x <= 0) dir *= -1;

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}