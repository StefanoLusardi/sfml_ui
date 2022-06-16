#include "module_b.hpp"
#include "ui/color.hpp"
#include <Poco/Format.h>
#include <Poco/Random.h>
#include <Poco/Logger.h>
#include <Poco/NumberFormatter.h>

#include <chrono>
#include <ui/window_manager.hpp>

namespace core
{
module_b::module_b()
{
    _logger.information("module_b create");
    _rect = ui::rect_t<float>{ 0, 0, 50, 50 };
}

module_b::~module_b()
{
    _logger.information("module_b delete");
}

void module_b::run()
{
    using namespace std::chrono_literals;
    
    Poco::Random rand;
    rand.seed(2);
    auto next = [&rand]{ return 10.f * (rand.nextFloat() - 0.5f); };

    _window_manager->add_layer_rect("b");
    _window_manager->add_layer_text("b");

    auto[window_w, window_h] = _window_manager->get_size();

    auto window_center_w = window_w * .5f;
    auto window_center_h = window_h * .5f;

    _rect.x = window_center_w;
    _rect.y = window_center_h;

    while(_is_running)
    {
        std::this_thread::sleep_for(50ms);

        _rect.x += next();
        _rect.y += next();
        _rect.w += next();
        _rect.h += next();

        _logger.information("[b] x: %hf - y: %hf - w: %hf - h: %hf", _rect.x, _rect.y, _rect.w, _rect.h);

        if (_rect.x < window_center_w && _rect.y < window_center_h)
        {
            _rect.color = ui::color::red;
            _window_manager->update_layer_rect("b", {_rect});
            _window_manager->update_layer_text("b", { ui::text_t<float>{"Module B - 1", _rect.x, _rect.y, ui::color::red } });
        }
        else
        {
            _rect.color = ui::color::green;
            auto r2 = ui::rect_t<float>{_rect.x * .3f, _rect.y * .4f, _rect.w, _rect.h, ui::color::green};

            _window_manager->update_layer_rect("b", {_rect, r2 });

            _window_manager->update_layer_text("b", { 
                ui::text_t<float>{"Module B - 1", _rect.x, _rect.y, ui::color::green }, 
                ui::text_t<float>{"Module B - 2", r2.x, r2.y, ui::color::green } 
            });
        }
    }
}

}