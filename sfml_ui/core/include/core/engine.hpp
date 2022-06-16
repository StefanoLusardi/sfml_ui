#pragma once

#if defined(_WIN32) || defined(_WIN64)
	#define API __declspec(dllexport)
#else
	#define API __attribute__ ((visibility ("default")))
#endif

#include <map>
#include <thread>
#include <memory>
#include <string>

namespace Poco { class Logger; }
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
	
	int run(int argc, char** argv);

private:
    std::shared_ptr<ui::window_manager_interface> _ui;
	std::map<std::string, std::shared_ptr<base_module>> _modules;
};

}
