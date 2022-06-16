#pragma once

#if defined(_WIN32) || defined(_WIN64)
	#define API __declspec(dllexport)
#else
	#define API __attribute__ ((visibility ("default")))
#endif

#include <ui/window_manager_interface.hpp>

#include <map>
#include <memory>
#include <thread>


namespace sf { class RenderWindow; }

namespace ui
{
class layer_rect;
class layer_text;

class API window_manager : public window_manager_interface
{
public:
    explicit window_manager();
    ~window_manager();

    window_manager(const window_manager&) = delete;
    window_manager& operator=(const window_manager&) = delete;

    bool start() override;
    bool stop() override;
    bool is_running() const override;

    std::tuple<unsigned int, unsigned int> get_size() const override;

	bool add_layer_text(const std::string& layer_name) override;
	bool add_layer_rect(const std::string& layer_name) override;

    bool update_layer_text(const std::string& layer_name, const std::vector<text_t<float>>& text_list) override;
    bool update_layer_rect(const std::string& layer_name, const std::vector<rect_t<float>>& rect_list) override;
    
    bool clear_layer(const std::string& layer_name) override;
    void clear_layers() override;

private:
    void run();
    bool _is_running;
    std::unique_ptr<std::thread> _thread;
    std::map<std::string, std::unique_ptr<layer_rect>> _rect_layers;
    std::map<std::string, std::unique_ptr<layer_text>> _text_layers;
};

}
