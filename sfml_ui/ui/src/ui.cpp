#include <ui/ui.hpp>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <vector>

namespace ui
{
window::window() 
{
    _shape = std::make_unique<sf::CircleShape>(50.f);
    _shape->setPosition(0, 0);
}

window::~window()
{
}

void window::run()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Blue);

        window.draw(*_shape);

        window.display();
    }
}

void window::add_shape()
{
    static float x = 0;
    static float y = 0;

    _shape->setPosition(x, y);

    x+=5; y+=5;
}

}