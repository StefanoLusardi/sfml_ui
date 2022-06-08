#pragma once

#include <map>
#include <thread>
#include <memory>
#include <string>

#if defined(_WIN32) || defined(_WIN64)
	#define API __declspec(dllexport)
#else
	#define API __attribute__ ((visibility ("default")))
#endif

namespace ui { class window_manager_interface; }

namespace core
{
class base_module;

constexpr const char* logger_name = "core_logger";

class API engine
{
public:
	explicit engine();
	~engine();
	
	static int exec(int argc, char** argv);
	int run();

private:
	std::map<std::string, std::unique_ptr<base_module>> _modules;
    std::shared_ptr<ui::window_manager_interface> _ui;
};

}
