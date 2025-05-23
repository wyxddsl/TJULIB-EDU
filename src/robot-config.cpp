#include "vex.h"

using namespace vex;

/*************************************

        physical configurations

*************************************/
const double r_wheel = 2.75/ 2;                      // 车轮半径(英寸)
const double gear_ratio = 1;                         // 底盘电机-轮的齿轮传动比（加速配比就大于1，减速配比就小于1）
const double r_motor = r_wheel * gear_ratio;         // 电机转角-电机转周的换算比
const double cell = 24;                              // 一个地垫长度(inches)

/*************************************

            VEX devices

*************************************/
// V5智能主控定义
brain  Brain;

// 底盘电机部分
// motor L1 = motor(PORT22, ratio6_1, true);
// motor L2 = motor(PORT22, ratio6_1, false);
// motor R1 = motor(PORT22, ratio6_1, false);
// motor R2 = motor(PORT22, ratio6_1, true);

// std::vector<vex::motor*> _leftMotors = {&L1, &L2};
// std::vector<vex::motor*> _rightMotors = {&R1, &R2};

motor L1 = motor(PORT5, ratio6_1, true);
motor L2 = motor(PORT2, ratio6_1, false);
motor L3 = motor(PORT1, ratio6_1, true);
motor L4 = motor(PORT4, ratio6_1, false);
motor L5 = motor(PORT7, ratio6_1, true);

motor R1 = motor(PORT12, ratio6_1, false);
motor R2 = motor(PORT13, ratio6_1, true);
motor R3 = motor(PORT11, ratio6_1, false);
motor R4 = motor(PORT15, ratio6_1, true); 
motor R5 = motor(PORT14, ratio6_1, false); 

std::vector<vex::motor*> _leftMotors = {&L1, &L2, &L3,  &L4, &L5};
std::vector<vex::motor*> _rightMotors = {&R1, &R2, &R3, &R4, &R5};

// 遥控器
controller Controller1 = controller(primary);
// imu惯性传感器
inertial imu = inertial(PORT10); 

// 其他电机

// 这个函数不要删也不要动
void vexcodeInit( void ) {
  // nothing to initialize
}