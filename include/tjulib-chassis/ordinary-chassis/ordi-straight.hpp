#pragma once
#include "tjulib-chassis/ordinary-chassis/ordi-base.hpp"
#include "tjulib-position/Position.hpp"

extern double zero_drift_error;

namespace tjulib
{
    using namespace vex;

    class Ordi_StraChassis : virtual public Ordi_BaseChassis
    {
    protected:
        Position *position = NULL;
        pidControl *fwdControl = NULL;  // 直线移动pid控制器
        pidControl *turnControl = NULL; // 转向pid控制器
    private:
        const double PI = 3.14159265358979323846;

    protected:
    public:
        Ordi_StraChassis(std::vector<std::vector<vex::motor *> *> &_chassisMotors,pidControl *_fwdpid, pidControl *_turnpid)
            : Ordi_BaseChassis(_chassisMotors, _fwdpid, _turnpid),
              fwdControl(_fwdpid), turnControl(_turnpid) {}

        // 把角度转换到360度以内
        double getWrap360(double currentAngle)
        {
            while(currentAngle >= 360)
                currentAngle -= 360;
            while(currentAngle < 0)
                currentAngle += 360;
            return currentAngle;
        }
        // 底盘刹车
        void setStop(vex::brakeType brakeType)
        {
            for (vex::motor *motor : (_leftMotors))
            {
                motor->setBrake(brakeType);
            }
            for (vex::motor *motor : (_rightMotors))
            {
                motor->setBrake(brakeType);
            }
        }
        
        void turnToAngle(double angle, T maxSpeed, double maxtime_ms, int fwd = 1)
        {
            // 仿照moveInches函数的写法，自行实现该函数
            // 目标：输入指定的航向，让机器人能够转到指定的航向
        }

        // 直线移动函数,通过pid控制器让机器人向前走指定的距离
        void moveInches(T inches, T maxSpeed, double maxtime_ms = 5000, int fwd = 1)
        {
            // 定义计时器
            timer mytime;
            mytime.clear();
            // 定义变量和初始化参数
            T finalFwdSpeed = 0;
            T targetDistant = inches;
            T startError = (position->LeftBaseDistance + position->RightBaseDistance) / 2;
            fwdControl->resetpid();
            
            // 循环判断条件：是否到达指定容差内指定时间以上（这里用循环次数代表时间）
            // 自行填写（用pidControl类里面的函数）
            while (1) 
            {
                // 计算当前误差（还需要往前走多少）
                // 自行填写
                targetDistant = 0; 
                // 如果当前误差已在容差范围内，则增加cnt计数
                // 自行填写（用pidPara里面的参数进行判断）
                if (1)
                {
                    fwdControl->cnt++;
                }
                // 如果超过了给定的maxtime，则退出循环
                if (mytime.time(msec) >= maxtime_ms)
                {
                    break;
                }
                // 用pid控制器计算速度
                // 自行填写
                finalFwdSpeed = 0;

                // 控制最小速度，让车辆底盘的电压至少能够克服阻力
                if (fabs(finalFwdSpeed)<fwdControl->params->minSpeed) 
                    {
                        if(finalFwdSpeed >= 0)
                        {
                            finalFwdSpeed = fwdControl->params->minSpeed;
                        }
                        else
                        {
                            finalFwdSpeed = - fwdControl->params->minSpeed;
                        }
                    }
                
                // 如果是向后走，则速度取反
                if (!fwd)
                    finalFwdSpeed = -finalFwdSpeed;
                
                // 把计算得到的速度输出
                VRUN(finalFwdSpeed, finalFwdSpeed);
                task::sleep(25);
            }
            // 完成循环以后把车停下
            VRUN(0, 0);
            setStop(vex::brakeType::brake);
            fwdControl->resetpid();
        }

    };
}