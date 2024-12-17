#ifndef __CHASSIS_H__
#define __CHASSIS_H__

#include "main.h"
#include "GM6020.h"
#include "M3508.h"
#include "math.h"
#include "Remote.h"
#include "PID.h"
#include "Car_Mode.h"

#define Gimbal_Yaw_ZERO 7422 //��̨������͵����������غ�ʱ��ı���ֵ
#define Gimbal_length 25 //mm���̰뾶
#define CHASSIS_DECELE_RATIO 19 //���ٱ�
#define Speed_Set 2000//�ٶ�
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

#endif
