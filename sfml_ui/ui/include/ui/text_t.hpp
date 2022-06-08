#pragma once


#if defined(_WIN32) || defined(_WIN64)
	#define API __declspec(dllexport)
#else
	#define API __attribute__ ((visibility ("default")))
#endif

#include <string>
#include <ui/color.hpp>

namespace ui
{
template <typename T>
struct API text_t
{
public:
    std::string str;
	T x;
    T y;
    ui::color color = ui::color::black;
};

}
