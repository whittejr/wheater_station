/**
 * @file    gpio.c
 * @brief   none
 * @version 0.1.0
 * @author  
 * @date    
 */

#include "gpio.h"
#include "board_config.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_gpio.h"
#include "stm32f1xx_hal_rcc.h"

uint8_t bsp_gpio_init(void) {
    __HAL_RCC_AFIO_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();

    /* GNSS_VCC_EN */
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Pin = GNSS_VCC_EN_PIN;
    HAL_GPIO_Init(GNSS_VCC_EN_PORT, &GPIO_InitStruct);

    /* PWRKEY */
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Pin = PWRKEY_PIN;
    HAL_GPIO_Init(PWRKEY_PORT, &GPIO_InitStruct);

    /* USART1 */
    // TX
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pin = USART1_TX_PIN;
    HAL_GPIO_Init(USART1_TX_PORT, &GPIO_InitStruct);
    // RX
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pin = USART1_RX_PIN;
    HAL_GPIO_Init(USART1_RX_PORT, &GPIO_InitStruct);

    /* USART2 */
    // TX
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pin = USART2_TX_PIN;
    HAL_GPIO_Init(USART2_TX_PORT, &GPIO_InitStruct);
    // RX
    GPIO_InitStruct.Mode = GPIO_MODE_AF_INPUT;
    GPIO_InitStruct.Pin = USART2_RX_PIN;
    HAL_GPIO_Init(USART2_RX_PORT, &GPIO_InitStruct);

    /* UART5 */
    // TX
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pin = GNSS_UART5_TX_PIN;
    HAL_GPIO_Init(GNSS_UART5_TX_PORT, &GPIO_InitStruct);
    // RX
    GPIO_InitStruct.Mode = GPIO_MODE_AF_INPUT;
    GPIO_InitStruct.Pin = GNSS_UART5_RX_PIN;
    HAL_GPIO_Init(GNSS_UART5_RX_PORT, &GPIO_InitStruct);


    return 0;
}

void bsp_gpio_write(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint8_t value) {
    HAL_GPIO_WritePin(GPIOx, GPIO_Pin, (GPIO_PinState)value);
}

uint8_t bsp_gpio_read(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
    return (uint8_t) HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
}

void bsp_gpio_toggle(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin) {
    HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
}
