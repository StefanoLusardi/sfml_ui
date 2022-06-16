#pragma once

#include <SFML/Graphics/Text.hpp>
#include <ui/text_t.hpp>
#include "layer_interface.hpp"


namespace ui
{
class layer_text : public layer_interface
{
public:
    bool setup();
    void update(const std::vector<text_t<float>>& text_list);

private:
    sf::Font _font;
};

}
