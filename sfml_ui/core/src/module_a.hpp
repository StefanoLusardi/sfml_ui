#pragma once

#include <ui/rect_t.hpp>
#include "base_module.hpp"

namespace core
{
class module_a : public base_module
{
public:
    explicit module_a();
    ~module_a();

    void run() override;
    
private:
    ui::rect_t<float> _rect;
};

}