/*
 * delay_timer.c
 *
 *  Created on: Feb 19, 2022
 *      Author: acer
 */
#include "delay_timer.h"

void	DELAY_TIM_Init(TIM_HandleTypeDef *htim)
{
	HAL_TIM_Base_Start(htim);
}

void 	DELAY_TIM_Us(TIM_HandleTypeDef *htim, uint16_t us)
{
    __HAL_TIM_SET_COUNTER(htim,0);  // set the counter value a 0
    while (__HAL_TIM_GET_COUNTER(htim) < us);  // wait for the counter to reach the us input in the parameter
}

void	DELAY_TIM_Ms(TIM_HandleTypeDef *htim, uint16_t ms)
{
	while(ms--)
	{
		DELAY_TIM_Us(htim, 1000);
	}
}
