#pragma once

#include <thread>
#include <vector>
#include <memory>

#if defined(_WIN32) || defined(_WIN64)
	#define API __declspec(dllexport)
#else
	#define API __attribute__ ((visibility ("default")))
#endif

namespace sf { class CircleShape; }

namespace ui
{
class API window
{
public:
	explicit window();
	~window();

	window(const window&) = delete;
    window& operator=(const window&) = delete;
	
	void run();
	void add_shape();

private:
	std::thread _thread;
	std::unique_ptr<sf::CircleShape> _shape;
};

}