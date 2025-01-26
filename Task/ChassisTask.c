#include "ChassisTask.h"

extern Car_Mode_t Car_Mode;

void ChassisTask(void const * argument)
{
    portTickType currentTime;
    while (1)   
    { 
        currentTime = xTaskGetTickCount();//��ǰϵͳʱ��
        Control_Mode_Choose();//ѡ��ģʽ
        switch (Car_Mode.State)
        {
        case Car_Remote:
			Chassis_Remote_Control();
            Chassis_Move();
            break;
        case Car_Keyboard:
            Chassis_Mode_Choose();
            break;
        case Car_Stop:
            Chassis_Stop();
            break;
                
        default:
            break;
        }
        vTaskDelayUntil(&currentTime,2);//������ʱ
    }

}

