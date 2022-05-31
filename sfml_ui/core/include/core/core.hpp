#pragma once

#include <thread>

#if defined(_WIN32) || defined(_WIN64)
	#define API __declspec(dllexport)
#else
	#define API __attribute__ ((visibility ("default")))
#endif


class API core
{
public:
	explicit core();
	~core();
	
	int run();

private:
	std::thread _thread;
	std::thread _window_thread;
};