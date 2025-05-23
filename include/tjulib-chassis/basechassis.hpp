#pragma once

#include "vex.h"
#include "basechassis.hpp"
#include "pidControl.hpp"
#include <cmath>
// extern GPS gps_;
namespace tjulib
{
    using namespace vex;
    class BaseChassis
    {
        public:
        // 构造函数
        BaseChassis(std::vector<std::vector<vex::motor*>*> &_chassisMotors,
                    pidControl *_fwdpidControl,pidControl *_turnpidControl)
        {}
    };
} // namespace tjulib
