#ifndef __CHASSIS_H__
#define __CHASSIS_H__

#include "main.h"
#include "GM6020.h"
#include "M3508.h"
#include "math.h"
#include "Remote.h"
#include "PID.h"
#include "Car_Mode.h"
#include "stdbool.h"
#include "judge.h"

#define Gimbal_Yaw_ZERO 5427 //��̨������͵����������غ�ʱ��ı���ֵ
#define Speed_Set 2388.535f//�ٶ�
#define WHEEL_PERIMETER 152 //mm�����ܳ�


typedef struct
{
    float vx;
    float vy;
    float vw;
}Chassis_Speed_t;


void Chassis_Move(void);
void Chassis_Remote_Control(void);
void Chassis_Remote_Mode(void);
void Chassis_PID_Init_All(void);
void Chassis_PID_Clean_All(void);
void Chassis_Stop(void);
void Chassis_PID_Calc(void);
float Find_Angle(void);
void Keyboard_mode_Choose(void);
void CHAS_Key_Ctrl(void);

#endif
