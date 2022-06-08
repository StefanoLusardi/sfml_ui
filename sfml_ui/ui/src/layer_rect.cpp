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
    _rects.clear();

    for (auto&& r : rect_list)
    {
        auto rect = sf::RectangleShape();
        rect.setPosition({r.x, r.y});
        rect.setSize({r.w, r.h});
        rect.setFillColor(sf::Color::Transparent);
        rect.setOutlineThickness(2.f);
        rect.setOutlineColor(color_to_SFML(r.color));

        _rects.emplace_back(std::move(rect));
    }
}

void layer_rect::draw(const std::shared_ptr<sf::RenderWindow>& window)
{
    std::scoped_lock lock(_mutex);

    for (auto&& s : _rects)
        window->draw(s);
}

}
