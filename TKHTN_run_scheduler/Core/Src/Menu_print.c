/*
 * Menu_print.c
 *
 *  Created on: Feb 20, 2022
 *      Author: acer
 */
#include "Menu_print.h"

/***********printf********/
void Menu_Print(UART_HandleTypeDef *huart, uint16_t* period_array, Motor_Name* Motor)
{
	printf("*******MOTOR_CONTROL_WITH_TEMPERATURE*********\n");

//	printf("SETTING SCHEDULER TIME\n");
//	printf("Task_read_temp period (ms) = \n");
//	period_array[0] = get_int_from_uart(huart);
//	printf("\nTask_read_speed period (ms) = \n");
//	period_array[1] = get_int_from_uart(huart);
//	printf("\nTask_set_speed period (ms) = \n");
//	period_array[2] = get_int_from_uart(huart);

	do {
		printf("\nSETTING MODE MOTOR\n");
		printf("MOTOR SPEED MANUAL:.........1\n");
		printf("MOTOR SPEED TEMP:...........2\n");
		Motor->mode = get_int_from_uart(huart);
	} while ((Motor->mode != MODE_MOTOR_MUNUAL) && (Motor->mode != MODE_MOTOR_TEMP));

	if(Motor->mode == MODE_MOTOR_MUNUAL)
	{
		printf("\nEnter duty speed for Motor (0 < duty < 100):\n");
		Motor->duty = get_int_from_uart(huart);
	}

}

void Menu_Print_Motor(void)
{
	printf("**********************************");
	printf("\nSelect speed level for motor: \n");
	printf("Zero level:........0\n");
	printf("Medium level:......1\n");
	printf("Max level:.........2\n");
}

int get_int_from_uart(UART_HandleTypeDef *huart)
{
	uint8_t rxBuff[10] = "";		//Buffer for receiver Uart
	int result = 0;
	while(rxBuff[0] == '\0')
	{
		HAL_UART_Receive(huart, rxBuff, 10, 200);
	}
	result = atoi((char*)rxBuff);

	for(int i = 0; i < 10; i++)
	{
		rxBuff[i] = '\0';
	}
	return result;
}
