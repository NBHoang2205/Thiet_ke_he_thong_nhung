/*
 * Menu_print.h
 *
 *  Created on: Feb 20, 2022
 *      Author: acer
 */

#ifndef INC_MENU_PRINT_H_
#define INC_MENU_PRINT_H_

#include "stm32f1xx_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include "Motor.h"

int get_int_from_uart(UART_HandleTypeDef *huart);
void Menu_Print(UART_HandleTypeDef *huart, uint16_t* period_array, Motor_Name* Motor);
void Menu_Print_Motor(void);



#endif /* INC_MENU_PRINT_H_ */
