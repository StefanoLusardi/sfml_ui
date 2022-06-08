#pragma once

#if defined(_WIN32) || defined(_WIN64)
	#define API __declspec(dllexport)
#else
	#define API __attribute__ ((visibility ("default")))
#endif

#include <ui/window_manager_interface.hpp>


namespace ui
{
class API window_manager_fake : public window_manager_interface
{
public:
    explicit window_manager_fake() { }
    ~window_manager_fake() { }

    window_manager_fake(const window_manager_fake&) = delete;
    window_manager_fake& operator=(const window_manager_fake&) = delete;

    bool start() override { return true; }
    bool stop() override { return true; }
    bool is_running() const override { return true; }

    std::tuple<unsigned int, unsigned int> get_size() const override { return std::make_tuple(0, 0); }

	bool add_layer_text(const std::string& layer_name) override { return true; }
	bool add_layer_rect(const std::string& layer_name) override { return true; }

    bool update_layer_text(const std::string& layer_name, const std::vector<text_t<float>>& text_list) override { return true; }
    bool update_layer_rect(const std::string& layer_name, const std::vector<rect_t<float>>& rect_list) override { return true; }
    
    bool clear_layer(const std::string& layer_name) override { return true; }
    void clear_layers() override  { }
};

}
