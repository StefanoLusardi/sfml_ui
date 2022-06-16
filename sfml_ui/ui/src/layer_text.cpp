#include "layer_text.hpp"
#include "color_adapter.hpp"


namespace ui
{
bool layer_text::setup()
{
    if (!_font.loadFromFile("../../../Roboto-Regular.ttf")) 
        return false;
    
    return true;
}

void layer_text::update(const std::vector<text_t<float>>& text_list)
{
    std::scoped_lock lock(_mutex);
    _items.clear();

    for (auto&& t : text_list)
    {
        auto text = std::make_shared<sf::Text>();
        text->setFont(_font);
        text->setCharacterSize(24);
        text->setFillColor(color_to_SFML(t.color));
        text->setString(t.str);
        text->setPosition(t.x, t.y);

        _items.emplace_back(std::move(text));
    }
}

}
