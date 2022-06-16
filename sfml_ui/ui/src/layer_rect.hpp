#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <ui/rect_t.hpp>
#include "layer_interface.hpp"


namespace ui
{
class layer_rect : public layer_interface
{
public:
    explicit layer_rect();
    void update(const std::vector<rect_t<float>>& rect_list);
};

}
