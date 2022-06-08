#pragma once

#include <ui/rect_t.hpp>
#include "base_module.hpp"

namespace core
{
class module_b : public base_module
{
public:
    explicit module_b();
    ~module_b();

    void run() override;
    
private:
    ui::rect_t<float> _rect;
};

}