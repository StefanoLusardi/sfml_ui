#pragma once

#include <ui/color.hpp>
#include <SFML/Graphics/Color.hpp>


namespace ui
{
inline
sf::Color color_to_SFML(const ui::color c)
{
    switch (c)
    {
        case color::black:      return sf::Color::Black;
        case color::white:      return sf::Color::White;
        case color::red:        return sf::Color::Red;
        case color::green:      return sf::Color::Green;
        case color::blue:       return sf::Color::Blue;
        case color::yellow:     return sf::Color::Yellow;
        case color::magenta:    return sf::Color::Magenta;
        case color::cyan:       return sf::Color::Cyan;
    }

    return sf::Color::Transparent;
}

}
