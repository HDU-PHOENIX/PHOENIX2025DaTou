#include "Remote.h"


extern RC_t RC;
extern uint8_t RC_Data[18];
extern Car_Mode_t Car_Mode;

/* ��ȡң����ҡ��ƫ����
	����ң�����ĵ���

��ҡ�ˣ�    ��ҡ�ˣ�
����Ϊch2   ����Ϊch0
����Ϊch3   ����Ϊch1

                        ��   660
��    ��       ��
-660   0      660       ��   0

                        ��  -660  */

/**
 * @file Remote.c
 * @brief ����ң��������
 * @author HWX
 * @date 2024/10/20
 */
void RC_Processing_Data(void)
{

	//ҡ��
	RC.ch0 = (((int16_t)RC_Data[0] | ((int16_t)RC_Data[1] << 8)) & 0x07FF)-1024;
	RC.ch1 = ((((int16_t)RC_Data[1] >> 3) | ((int16_t)RC_Data[2] << 5)) & 0x07FF)-1024;
	RC.ch2 = ((((int16_t)RC_Data[2] >> 6) | ((int16_t)RC_Data[3] << 2) |((int16_t)RC_Data[4] << 10)) & 0x07FF)-1024;
	RC.ch3 = ((((int16_t)RC_Data[4] >> 1) | ((int16_t)RC_Data[5]<<7)) & 0x07FF)-1024;
	//��λ����
	RC.s1 = ((RC_Data[5] >> 4) & 0x000C) >> 2;
	RC.s2 = ((RC_Data[5] >> 4) & 0x0003);
	//���
	RC.x = ((int16_t)RC_Data[6]) | ((int16_t)RC_Data[7] << 8);
	RC.y = ((int16_t)RC_Data[8]) | ((int16_t)RC_Data[9] << 8);
	RC.z = ((int16_t)RC_Data[10]) | ((int16_t)RC_Data[11] << 8); 
	RC.press_l = RC_Data[12];
	RC.press_r = RC_Data[13];
	//����
	RC.key = ((int16_t)RC_Data[14]) | ((int16_t)RC_Data[15] << 8);
	//wheel
	RC.wheel = ((int16_t)RC_Data[16] | (int16_t)RC_Data[17] << 8) - 1024;
}

void Car_Init(void)
{
	Car_Mode.State = Car_Stop;
	Car_Mode.Action = NORMAL;
	Car_Mode.Shoot = Shoot_Normal;
}


/**
 * @file Remote.c
 * @brief ѡ��ң��ģʽ
 * @author HWX
 * @date 2024/10/20
 */
void Control_Mode_Choose(void)
{
	if(RC.s1==1)
	{
		switch (RC.s2)
		{
		case 1:
			if(Car_Mode.State != Car_Stop)
			{
				Chassis_PID_Clean_All();
				Gimbal_PID_Clean_All();
				Shoot_PID_Clean_ALL();
			}
			Car_Mode.State = Car_Stop;
			break;
		case 3:
			if(Car_Mode.State == Car_Stop)
			{
				Chassis_PID_Init_All();
				Gimbal_PID_Init_All();
				Shoot_PID_Init_ALL();
			}
			Car_Mode.State = Car_Remote;
			break;
		case 2:
			if(Car_Mode.State == Car_Stop)
			{
				Chassis_PID_Init_All();
				Gimbal_PID_Init_All();
				Shoot_PID_Init_ALL();
			}
			Car_Mode.State = Car_Keyboard;
			break;
		default:
			break;
		}
	}else if(RC.s1==3)
	{
		switch (RC.s2)
		{
		case 1:
			Car_Mode.Action = FOLLOW;
			break;
		case 3:
			Car_Mode.Action = NORMAL;
			break;
		case 2:
			Car_Mode.Action = GYROSCOPE;
			break;
		default:
			break;
		}
	}else if(RC.s1==2)
	{
		switch(RC.s2)
		{
		case 1:
			Car_Mode.Shoot = Shoot_Plugins;
			break;
		case 3:
		case 2:
			Car_Mode.Shoot = Shoot_Normal;
			break;
		}
	}
}
