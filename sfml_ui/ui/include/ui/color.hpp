#pragma once

#if defined(_WIN32) || defined(_WIN64)
	#define API __declspec(dllexport)
#else
	#define API __attribute__ ((visibility ("default")))
#endif

namespace ui
{
enum class color
{
    black, white, red, green, blue, yellow, magenta, cyan
};

}
