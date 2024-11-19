#ifndef __COMPUTER_H__
#define __COMPUTER_H__

#include "main.h"
#include "usb_device.h"
#include "GM6020.h"
#include "usbd_cdc_if.h"
#include "cmsis_os.h"
#include "Gimbal.h"

#pragma pack(1)

typedef struct
{
char start;               //0 ֡ͷ 's��
char type;                //1 ��Ϣ���� 0xA0
float yaw;                //2-5 ƫ����
float pitch;              //6-9 ������
char find_bool;           //10 �Ƿ��ҵ� '0' or '1'
char shoot_bool;          //11 �Ƿ񿪻� '0' or '1'
                          //......  12-30 Ԥ����λ
char end;                 //31 ֡β 'e��
}Computer_Rx_Message_t;

typedef struct
{
char start;               //0 ֡ͷ 's��
char type;                //1 ��Ϣ���� 0xB0
char enemy_team_color;    //2 �з���ɫ ��'b' ��'r'
char mode;                //3 ����ģʽ װ�װ�'a' ��'r'
char rune_flag;           //4 ��ģʽ ���ɼ���'0' С��'1' ���'2'
float yaw;                //5-8 ƫ����
float pitch;              //9-12 ������
                          //......  13-30 Ԥ����λ
char end;                 //31 ֡β 'e��
}Computer_Tx_Message_t;

#pragma pack()

void Computer_Init(void);
void Computer_Rx(void);
void Computer_Tx(void);

#endif
