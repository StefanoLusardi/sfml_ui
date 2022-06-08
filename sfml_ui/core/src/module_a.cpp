#include "module_a.hpp"
#include "ui/color.hpp"
#include <Poco/Format.h>
#include <Poco/Random.h>
#include <Poco/Logger.h>

#include <chrono>
#include <ui/window_manager.hpp>

namespace core
{
module_a::module_a()
{
    _logger.information("module_a create");
    _rect = ui::rect_t<float>{ 0, 0, 50, 50 };
}

module_a::~module_a()
{
    _logger.information("module_a delete");
}

void module_a::run()
{
    using namespace std::chrono_literals;

    Poco::Random rand;
    rand.seed(1);
    auto next = [&rand]{ return 10.f * (rand.nextFloat() - 0.5f); };

    _window_manager->add_layer_rect("a");
    _window_manager->add_layer_text("a");

    auto[window_w, window_h] = _window_manager->get_size();

    auto window_center_w = window_w * .5f;
    auto window_center_h = window_h * .5f;

    _rect.x = window_center_w;
    _rect.y = window_center_h;

    while(_is_running)
    {
        std::this_thread::sleep_for(250ms);

        _rect.x += next();
        _rect.y += next();
        _rect.w += next();
        _rect.h += next();

        _logger.information("[a] x: %hf - y: %hf - w: %hf - h: %hf", _rect.x, _rect.y, _rect.w, _rect.h);
  
        _window_manager->update_layer_rect("a", {_rect});

        if (_rect.x < window_center_w && _rect.y < window_center_h)
        {
            _rect.color = ui::color::magenta;
            _window_manager->update_layer_rect("a", {_rect});
            _window_manager->update_layer_text("a", { ui::text_t<float>{"Module A - 1", _rect.x, _rect.y, ui::color::magenta } });
        }
        else
        {
            _rect.color = ui::color::yellow;
            auto r2 = ui::rect_t<float>{_rect.x * .6f, _rect.y * .7f, _rect.w, _rect.h, ui::color::yellow };

            _window_manager->update_layer_rect("a", {_rect, r2 });

            _window_manager->update_layer_text("a", { 
                ui::text_t<float>{"Module A - 1", _rect.x, _rect.y, ui::color::yellow }, 
                ui::text_t<float>{"Module A - 2", r2.x, r2.y, ui::color::yellow } 
            });
        }
    }
}

}