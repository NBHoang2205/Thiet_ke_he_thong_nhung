/*
 * Motor.c
 *
 *  Created on: Feb 19, 2022
 *      Author: Nguyen_Ba_Hoang_20181486
 */

#include "Motor.h"

extern Motor_Name 	Motor;			//This name must = variable name in main.c
static int 			idx 		= 0;
static uint16_t 	pre_counter = 0;
static uint16_t 	old_counter = 0;
static uint16_t 	speed 		= 0;
/*************************************************************************************************/

/**
  * @brief Init motor
  * @param	Timer,channel for PWM_PIN;
  * 		duty: Duty cycle of PWM
  * 		frequency: frequency of PWM
  * @retval None
  */

void Motor_Init_PWM(Motor_Name* Motor, TIM_HandleTypeDef* Timer, uint32_t Channel, 	uint32_t frequency, uint8_t duty)
{
	Motor->Timer_PWM = Timer;
	Motor->Channel_PWM = Channel;
	//Start Timer
	HAL_TIM_PWM_Start(Timer, Channel);
	Motor_Set_Duty(Motor, duty);
	Motor_Set_Frequency(Motor, frequency);
}

/**
  * @brief Init Encoder for measure motor speed
  * @param	Timer,channel for Encoder
  *
  * @retval None
  */
void Motor_Init_Encoder(Motor_Name* Motor, TIM_HandleTypeDef* Timer, uint32_t Channel)
{
	Motor->Timer_Encoder = Timer;
	Motor->Channel_Encoder = Channel;
	HAL_TIM_Encoder_Start(Timer, Channel);
}
/**
  * @brief Set duty cycle for PWM
  * @param Duty(%) 0 -> 100. % High voltage
  * @retval None
  */
void Motor_Set_Duty(Motor_Name* Motor,uint8_t duty)
{
	if(duty > DUTY_MAX)
		duty = DUTY_MAX;
	if(duty <= DUTY_MIN)
		duty = 0;

	Motor->duty = duty;
	uint16_t compare = (Motor->Timer_PWM->Init.Period + 1) * duty / 100;
	__HAL_TIM_SET_COMPARE(Motor->Timer_PWM, Motor->Channel_PWM, compare);
}

/**
  * @brief Set frequency for PWM
  * @param frequency(Hz); should  2 < f < 10000
  * @retval None
  */
void Motor_Set_Frequency(Motor_Name* Motor, uint32_t frequency)
{
	// frequency = f_timer / [(Period + 1) * (Psc + 1)]
	// -> Psc = f_timer / ((period + 1)*frequency) - 1;
	Motor->frequency = frequency;
	uint32_t period = Motor->Timer_PWM->Init.Period;
	uint32_t f_timer = HAL_RCC_GetHCLKFreq();
	TIM2->PSC = f_timer / ((period + 1) * frequency) - 1;
}

/**
  * @brief read speed
  * @param
  * @retval None
  */
uint16_t Motor_Get_Speed(Motor_Name* Motor)
{
	Motor->speed = speed;
	return speed;
}

/**
  * @brief update speed for motor through encoder
  * @param
  * @retval None
  */
void HAL_SYSTICK_Callback(void)
{
  /* NOTE : This function Should not be modified, when the callback is needed,
            the HAL_SYSTICK_Callback could be implemented in the user file
   */
	if(idx == SAMPLING_TIME)	//update speed after every sampling time
	{
		pre_counter = __HAL_TIM_GET_COUNTER(Motor.Timer_Encoder);
		speed = caculate_speed(pre_counter, old_counter);
		old_counter = pre_counter;
		idx = 0;
	}
	idx++;
}

uint16_t caculate_speed(uint16_t pre_counter, uint16_t old_counter)
		{
			if(pre_counter < old_counter)
				pre_counter += Motor.Timer_Encoder->Init.Period;
			return (pre_counter - old_counter) * (1000 / SAMPLING_TIME) * 60 / 334; 	//number of pulses in one  minutes / 334 = rpm
		}
