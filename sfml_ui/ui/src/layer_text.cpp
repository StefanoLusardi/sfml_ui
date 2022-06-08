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
    _texts.clear();

    for (auto&& t : text_list)
    {
        auto text = sf::Text();
        text.setFont(_font);
        text.setCharacterSize(24);
        text.setFillColor(color_to_SFML(t.color));
        text.setString(t.str);
        text.setPosition(t.x, t.y);

        _texts.emplace_back(std::move(text));
    }
}

void layer_text::draw(const std::shared_ptr<sf::RenderWindow>& window)
{
    std::scoped_lock lock(_mutex);

    for (auto&& t : _texts)
        window->draw(t);
}

}
