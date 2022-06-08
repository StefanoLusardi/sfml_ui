#include <core/engine.hpp>
#include "base_module.hpp"

#include <Poco/Logger.h>
#include <ui/window_manager.hpp>

namespace core
{

base_module::base_module()
: _logger{ Poco::Logger::get(core::logger_name) }
, _is_running{ false }
{
}

base_module::~base_module()
{
}

bool base_module::start()
{
    if (_is_running)
        return false;

    _is_running = true;
    _thread = std::make_unique<std::thread>([this]{ run(); });
    return true;
}

bool base_module::stop()
{
    if (!_is_running)
        return false;

    _is_running = false;
    if (_thread->joinable())
    {
        _thread->join();
        return true;
    }

    return false;
}

void base_module::set_window_manager(const std::shared_ptr<ui::window_manager_interface>& window_manager)
{
    _window_manager = window_manager;
}

}