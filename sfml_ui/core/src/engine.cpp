#include <core/engine.hpp>
#include <ui/window_manager.hpp>
#include <ui/window_manager_fake.hpp>

#include "module_a.hpp"
#include "module_b.hpp"

#include <Poco/Logger.h>
#include <Poco/PatternFormatter.h>
#include <Poco/FormattingChannel.h>
#include <Poco/ConsoleChannel.h>

using namespace std::chrono_literals;

namespace core
{
engine::engine()
{
    Poco::FormattingChannel* pFCConsole = new Poco::FormattingChannel(new Poco::PatternFormatter("%Y-%m-%d %H:%M:%S.%i [%p] %t"));
    pFCConsole->setChannel(new Poco::ConsoleChannel);
    pFCConsole->open();

    Poco::Logger::create(core::logger_name, pFCConsole);
}

engine::~engine()
{
}

int engine::exec(int argc, char** argv)
{
    engine e;
    return e.run();
}

int engine::run()
{
    auto& logger = Poco::Logger::get(core::logger_name);
    logger.information("core::engine");

    _modules.emplace("module_a", std::make_unique<core::module_a>());
    _modules.emplace("module_b", std::make_unique<core::module_b>());

    bool ui_enabled = true;
    if (ui_enabled)
    {
        _ui = std::make_shared<ui::window_manager>();
    }
    else
    {
        _ui = std::make_shared<ui::window_manager_fake>();
    }

    _ui->start();

    for (auto&&[_, m] : _modules)
    {
        m->set_window_manager(_ui);
        m->start();
    }    

    while(_ui->is_running())
    {
        std::this_thread::sleep_for(1s);
    }

    for (auto&&[_, m] : _modules)
    {
        m->stop();
        // m->set_window_manager(nullptr);
    }

    _ui->stop();

    return 0;
    // return EXIT_SUCCESS;
}

}
