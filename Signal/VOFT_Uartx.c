#include "VOFT_Uartx.h"

extern uint8_t VOFT_Data[20];
extern float Set_Yaw,Set_Pitch;
extern float IMU_angle[3];
extern Moto_GM6020_t GM6020_Yaw,GM6020_Pitch;
extern Chassis_Speed_t Temp1_Chassis_Speed,Temp2_Chassis_Speed;
extern Moto_M3508_t M3508_Chassis[4];
extern Moto_M2006_t M2006_Rammer;

uint8_t T_pData[20] = {0};
uint8_t R_pData[20] = {0};

int fputc(int ch, FILE *f)

{
    HAL_UART_Transmit(&huart1,(uint8_t *)&ch,1,0xffff);
    return ch;
}


void VOFT_Tx(void)
{
	printf("%d,%d,%d,%d,%d,%f,%f\n",M3508_Chassis[0].rotor_speed,M3508_Chassis[0].rotor_speed,M3508_Chassis[1].rotor_speed,M3508_Chassis[2].rotor_speed,M3508_Chassis[3].rotor_speed,Temp2_Chassis_Speed.vx,IMU_angle[0]);
}

//float Get_Data(void)
//{
//	float data_Integer = 0;//��������
//	float data_Decimals = 0;//С������
//    uint8_t data_Start_Num = 0; // ��¼����λ��ʼ�ĵط�
//    uint8_t data_End_Num = 0; // ��¼����λ�����ĵط�
//	uint8_t data_Point_Num = 0;//��¼������С�����λ��
//    uint8_t data_Integer_Num = 0; // ��¼����λ��
//    uint8_t data_Decimals_Num = 0; // ��¼С��λ��
//    uint8_t minus_Flag = 0; // �ж��ǲ��Ǹ���
//    float data_return = 0; // �����õ�������
//    for(uint8_t i=0;i<20;i++) // ���ҵȺź͸�̾�ŵ�λ��
//    {
//        if(VOFT_Data[i] == '=')
//			data_Start_Num = i + 1; // +1��ֱ�Ӷ�λ��������ʼλ
//        if(VOFT_Data[i] == '!')
//        {
//            data_End_Num = i - 1;
//            break;
//        }
//		if(VOFT_Data[i] == '.')
//			data_Point_Num = i;
//    }
//    if(VOFT_Data[data_Start_Num] == '-') // ����Ǹ���
//    {
//        data_Start_Num += 1; // ����һλ������λ
//        minus_Flag = 1; // ����flag
//    }
//	
//	data_Integer_Num = data_Point_Num - data_Start_Num;
//	data_Decimals_Num = data_End_Num - data_Point_Num;

//    if(minus_Flag == 1)  data_return = -data_return;
//    return data_return;
//}
