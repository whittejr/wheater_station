/**
 * @file uart.h
 * @brief  none
 * @version 0.1
 */

#ifndef UART_H
#define UART_H

#include "stm32f1xx_hal.h"
#include <stdint.h>

/*
* @brief       
* @param[in]   
* @return      
*            - 
*            - 
* @note       
*/
uint8_t uart_init(void);

/*
* @brief       
* @param[in]   
* @return      
*            - 
*            - 
* @note       
*/
uint8_t uart_deinit(void);

/*
* @brief       
* @param[in]   
* @return      
*            - 
*            - 
* @note       
*/
uint8_t uart_write(UART_HandleTypeDef *huart, uint8_t *data, uint16_t len);

#endif // UART_H
