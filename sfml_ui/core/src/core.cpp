#include <core/core.hpp>
#include <ui/ui.hpp>

using namespace std::chrono_literals;

core::core()
{ 
}

core::~core()
{
}

int core::run()
{
    ui::window window;
    
    _window_thread = std::thread([this, &window]
    {
        window.run();
    });

    _thread = std::thread([this, &window]
    {
        while(true)
        {
            window.add_shape();
            std::this_thread::sleep_for(1s);
        }
    });

    _thread.join();
    _window_thread.join();

    return EXIT_SUCCESS;
}