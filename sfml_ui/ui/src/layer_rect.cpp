#include "layer_rect.hpp"
#include "color_adapter.hpp"


namespace ui
{
layer_rect::layer_rect()
{
}

void layer_rect::update(const std::vector<rect_t<float>>& rect_list)
{
    std::scoped_lock lock(_mutex);
    _items.clear();

    for (auto&& r : rect_list)
    {
        auto rect = std::make_shared<sf::RectangleShape>();
        rect->setPosition({r.x, r.y});
        rect->setSize({r.w, r.h});
        rect->setFillColor(sf::Color::Transparent);
        rect->setOutlineThickness(2.f);
        rect->setOutlineColor(color_to_SFML(r.color));

        _items.emplace_back(std::move(rect));
    }
}

}
