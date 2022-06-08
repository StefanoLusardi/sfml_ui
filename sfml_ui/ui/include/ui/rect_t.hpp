#pragma once

#if defined(_WIN32) || defined(_WIN64)
	#define API __declspec(dllexport)
#else
	#define API __attribute__ ((visibility ("default")))
#endif

#include <ui/color.hpp>


namespace ui
{
template <typename T>
struct API rect_t
{
public:
	T x;
    T y;
    T w;
    T h;
    ui::color color = ui::color::black;
};

}
