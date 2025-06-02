//提示：robot-config.h文件用来对你在robot-config.cpp文件中定义的机器人相关参数进行声明

#pragma once
using namespace vex;
/*************************************

        physical configurations

*************************************/
// 车轮半径
extern const double r_wheel;
// 底盘电机-轮的齿轮传动比
extern const double gear_ratio;
// 电机转角-电机转周的换算比
extern const double r_motor; 
// 一个地垫长度(inches)
extern const double cell;

/*************************************

            VEX devices

*************************************/
extern brain Brain;
extern motor L1;
extern motor L2;
extern motor R1;
extern motor R2;

extern inertial imu;

// 遥控器
extern controller Controller1;

// 四角底盘电机组声明
extern std::vector<vex::motor*> _leftMotors;
extern std::vector<vex::motor*> _rightMotors;

// 保留这个函数不要动
void  vexcodeInit( void );