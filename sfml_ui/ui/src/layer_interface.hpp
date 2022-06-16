#pragma once

#include "SFML/Graphics/Drawable.hpp"
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
    
    std::vector<std::shared_ptr<sf::Drawable>> get_items()
    {
        std::scoped_lock lock(_mutex);
        return _items;
    }

protected:
    std::mutex _mutex;
    sf::Color _color;
    std::vector<std::shared_ptr<sf::Drawable>> _items;
};

}
