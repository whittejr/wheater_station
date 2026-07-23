/**
 * @file gpio.h
 * @brief  none
 * @version 0.1
 * @author 
 * @date 
 */

#ifndef GPIO_H
#define GPIO_H

#include "stm32f1xx_hal.h"
#include <stdint.h>

uint8_t bsp_gpio_init(void);
uint8_t bsp_gpio_read(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void bsp_gpio_write(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t value);
void bsp_gpio_toggle(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);


#endif // GPIO_H
