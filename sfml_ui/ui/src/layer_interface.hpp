#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <mutex>


namespace ui
{
class layer_interface
{
public:
    virtual ~layer_interface() {}
    virtual void draw(const std::shared_ptr<sf::RenderWindow>& window) = 0;

protected:
    std::mutex _mutex;
    sf::Color _color;
};

}
