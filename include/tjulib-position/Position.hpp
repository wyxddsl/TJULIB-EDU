#pragma once
#include "vex.h"

namespace tjulib{

    using namespace vex;
    typedef double T;

    // 实时左右轮里程计
    class Position 
    {
    public:
        T LeftBaseDistance =0, RightBaseDistance = 0;
        T LeftSideMotorPosition = 0, RightSideMotorPosition = 0;
        T LastLeftSideMotorPosition = 0, LastRightSideMotorPosition = 0;
    public:
        virtual ~Position() {}
    
    // 角度转弧度函数
    float getRadians(float deg)
    {
        return (deg * M_PI) / 180;
    }

    // 实时更新底盘电机编码器的里程计数
    int OdomRun()
    {
        while(true) 
        {         
            // 读取电机转角
            LeftSideMotorPosition = 0;
            RightSideMotorPosition = 0;
            for(motor* m : _leftMotors) LeftSideMotorPosition += getRadians(m->position(deg)) / _leftMotors.size()* r_motor;
            for(motor* m : _rightMotors) RightSideMotorPosition += getRadians(m->position(deg)) / _rightMotors.size()* r_motor;

            T LeftSideDistance=(LeftSideMotorPosition - LastLeftSideMotorPosition); 
            T RightSideDistance=(RightSideMotorPosition - LastRightSideMotorPosition);
            LeftBaseDistance = LeftSideMotorPosition ; 
            RightBaseDistance = RightSideMotorPosition ;
            printf("LeftBaseDistance: %f, RightBaseDistance: %f\n", LeftBaseDistance, RightBaseDistance);

            LastLeftSideMotorPosition = LeftSideMotorPosition;
            LastRightSideMotorPosition = RightSideMotorPosition;

            this_thread::sleep_for(10);
        }
        return 0;
    }

    };
}