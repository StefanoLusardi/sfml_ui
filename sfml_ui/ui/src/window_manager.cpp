#include <ui/window_manager.hpp>
#include <future>
#include "layer_rect.hpp"
#include "layer_text.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace ui
{
window_manager::window_manager()
: _is_running{ false }
{

}

window_manager::~window_manager()
{
    // _window->close();
}

bool window_manager::start()
{
    if (_is_running)
        return false;

    _is_running = true;

    std::promise<void> is_window_created;
    std::future<void> wait_for_window_created = is_window_created.get_future();

    _thread = std::make_unique<std::thread>([this, &is_window_created]
    {
        _window = std::make_shared<sf::RenderWindow>(sf::VideoMode(800, 600), "SFML UI");
        _window->setVerticalSyncEnabled(true);
        is_window_created.set_value();

        run();

        _window->close();
        _window.reset();
    });
    
    wait_for_window_created.wait();
    return true;
}

bool window_manager::stop()
{
    if (_thread && _thread->joinable())
    {
        _thread->join();        
        return true;
    }

    return false;
}

bool window_manager::is_running() const
{
    return _is_running;
}

void window_manager::run()
{
    while (_is_running)
    {
        sf::Event event;
        while (_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _is_running = false;
        }

        _window->clear(sf::Color::Blue);

        for (auto&&[layer_name, layer] : _rect_layers)
            layer->draw(_window);

        for (auto&&[layer_name, layer] : _text_layers)
            layer->draw(_window);

        _window->display();
    }
}

std::tuple<unsigned int, unsigned int> window_manager::get_size() const
{
    auto&& [w, h] = _window->getSize();
    return {w, h};
}

bool window_manager::add_layer_text(const std::string& layer_name)
{
    auto l = std::make_unique<layer_text>();
    if (!l->setup())
        return false;

    auto [_, is_inserted] = _text_layers.emplace(layer_name, std::move(l));
    return is_inserted;
}

bool window_manager::add_layer_rect(const std::string& layer_name)
{
    auto [_, is_inserted] = _rect_layers.emplace(layer_name, std::make_unique<layer_rect>());
    return is_inserted;
}

bool window_manager::update_layer_text(const std::string& layer_name, const std::vector<text_t<float>>& text_list)
{
    auto layer = _text_layers.find(layer_name);
    if (layer == _text_layers.end())
        return false;
    
    layer->second->update(text_list);

    return true;
}

bool window_manager::update_layer_rect(const std::string& layer_name, const std::vector<rect_t<float>>& rect_list)
{
    auto layer = _rect_layers.find(layer_name);
    if (layer == _rect_layers.end())
        return false;
    
    layer->second->update(rect_list);

    return true;
}

bool window_manager::clear_layer(const std::string& layer_name)
{
    if (_rect_layers.find(layer_name) != _rect_layers.end())
    {
        _rect_layers.erase(layer_name);
        return true;
    }

    if (_text_layers.find(layer_name) != _text_layers.end())
    {
        _text_layers.erase(layer_name);
        return true;
    }

    return false;
}

void window_manager::clear_layers()
{
    _rect_layers.clear();
    _text_layers.clear();
}

}