#include "M2006.h"

extern Moto_M2006_t M2006_Rammer;

/**
 * @file M3508.c
 * @brief M3508���ܷ������ĺ���
 * @param StdId ���ID
 * @param rx_data CANͨ���յ�������
 * @author HWX
 * @date 2024/10/20
 */
void Get_M2006_Motor_Message(uint32_t StdId,uint8_t rx_data[8])
{
    switch(StdId)//����ָ�������������Ϣ
    {
        case 0x201://�������ı�ʶ��
        {
            M2006_Rammer.rotor_angle    = ((rx_data[0] << 8) | rx_data[1]);//���ջ�е�Ƕȣ�16bit��
            M2006_Rammer.rotor_speed    = ((rx_data[2] << 8) | rx_data[3]);//����ת�٣�16bit��
            M2006_Rammer.torque_current = ((rx_data[4] << 8) | rx_data[5]);//����ʵ��ת��
            break;
        }
        default:
            break;
    }
}

/**
 * @file M3508.c
 * @brief M3508���͵������Ŀ��ƺ���
 * @param hcan CANͨ��
 * @param M3508_Chassis ���̵��
 * @author HWX
 * @date 2024/10/20
 */
void Set_M2006_Motor_Voltage(CAN_HandleTypeDef* hcan,Moto_M2006_t M2006_Rammer)
{
    CAN_TxHeaderTypeDef tx_header;
    uint8_t             tx_data[8] = {0};
    
    tx_header.StdId = 0x200;//��ʶ�������ֲ�P6��
    tx_header.IDE   = CAN_ID_STD;//��׼ID
    tx_header.RTR   = CAN_RTR_DATA;//����֡
    tx_header.DLC   = 8;//�ֽڳ���

    tx_data[0] = ((int16_t)M2006_Rammer.PID.output>>8)&0xff;
    tx_data[1] = ((int16_t)M2006_Rammer.PID.output)&0xff;

    HAL_CAN_AddTxMessage(&hcan2, &tx_header, tx_data,(uint32_t*)CAN_TX_MAILBOX0);
}
