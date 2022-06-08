#pragma once

#if defined(_WIN32) || defined(_WIN64)
	#define API __declspec(dllexport)
#else
	#define API __attribute__ ((visibility ("default")))
#endif

#include <ui/rect_t.hpp>
#include <ui/text_t.hpp>

#include <string>
#include <tuple>
#include <vector>


namespace ui
{
class API window_manager_interface
{
public:
    virtual ~window_manager_interface() { }

    virtual bool start() = 0;
    virtual bool stop() = 0;
    virtual bool is_running() const = 0;

    virtual std::tuple<unsigned int, unsigned int> get_size() const = 0;

	virtual bool add_layer_text(const std::string& layer_name) = 0;
	virtual bool add_layer_rect(const std::string& layer_name) = 0;

    virtual bool update_layer_text(const std::string& layer_name, const std::vector<text_t<float>>& text_list) = 0;
    virtual bool update_layer_rect(const std::string& layer_name, const std::vector<rect_t<float>>& rect_list) = 0;
    
    virtual bool clear_layer(const std::string& layer_name) = 0;
    virtual void clear_layers() = 0;
};

}
