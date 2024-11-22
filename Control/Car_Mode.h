#ifndef __CARMODE_H__
#define __CARMODE_H__

typedef enum
{
	Car_Stop     = 0x00,//����ֹͣ
	Car_Remote   = 0x01,//ң��������
	Car_Keyboard = 0x02//���̿���
}Car_State;

typedef enum
{
    FOLLOW 	   = 0x00,	//�л�����������ٶ�λ�ã����£����ܵȣ�
    GYROSCOPE  = 0x01,  //С����ģʽ
    NORMAL     = 0x02,  //���̲�������̨����
}Car_Action;

typedef enum
{
	Shoot_Single = 0x00, //�������
	Shoot_Sustain = 0x01, //�������
	Shoot_Plugins = 0x02 //����ģʽ
}Car_Shoot;

typedef struct
{
	Car_State State;
	Car_Action Action;
	Car_Shoot Shoot;
}Car_Mode_t;

#endif


