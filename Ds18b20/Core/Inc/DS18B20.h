/*
 * DS18B20.h
 *
 *  Created on: Feb 5, 2022
 *      Author: CUONG
 */

#ifndef INC_DS18B20_H_
#define INC_DS18B20_H_



#endif /* INC_DS18B20_H_ */

#include "main.h"

#define DS18B20_PORT 	GPIOB
#define DS18B20_PIN 	GPIO_PIN_9

void Set_Pin_Output(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void Set_Pin_Input(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
uint8_t DS18B20_Start(void);
void DS18B20_Write(uint8_t data);
uint8_t DS18B20_Read(void);
