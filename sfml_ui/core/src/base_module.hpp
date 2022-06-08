#pragma once

#include <thread>
#include <atomic>
#include <memory>

namespace Poco { class Logger; }
namespace ui { class window_manager_interface; }

namespace core
{
class base_module
{
public:
    explicit base_module();
	virtual ~base_module();
    
    bool start();
    bool stop();
    void set_window_manager(const std::shared_ptr<ui::window_manager_interface>& window_manager);

protected:
    virtual void run() = 0;
    std::unique_ptr<std::thread> _thread;
    bool _is_running;
    Poco::Logger& _logger;
    std::shared_ptr<ui::window_manager_interface> _window_manager;
};
}