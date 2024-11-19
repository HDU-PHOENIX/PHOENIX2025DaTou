#ifndef __M2006_H__
#define __M2006_H__

#include "main.h"
#include "can.h"
#include "stm32f4xx_hal_can.h"
#include "PID.h"
#include "stdint.h"

typedef struct
{
    uint16_t can_id;//���ID
    uint16_t rotor_angle;//����Ƕ�
    int16_t  rotor_speed;//����ٶ�
    int16_t  torque_current;//���Ť��
    int16_t Set_Speed;//�趨�ٶ�
    uint16_t Set_Angle;//�趨�Ƕ�
    PID_struct_t PID;//PID���ֲ���
}Moto_M2006_t;

void Get_M2006_Motor_Message(uint32_t StdId,uint8_t rx_data[8]);
void Set_M2006_Motor_Voltage(CAN_HandleTypeDef* hcan,Moto_M2006_t M2006_Rammer);

#endif
