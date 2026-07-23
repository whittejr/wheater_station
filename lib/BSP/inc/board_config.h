/**
 * @file board_config.h
 * @brief  none
 * @version 0.1
 * @author Your name here
 * @date 2026-07-23
 */

#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

/* PRIMARY MCU USART */
#define USART1_TX_PIN  GPIO_PIN_9
#define USART1_TX_PORT GPIOA
#define USART1_RX_PIN  GPIO_PIN_10
#define USART1_RX_PORT GPIOA

/* MC60 GSM */
#define USART2_TX_PIN           GPIO_PIN_2
#define USART2_TX_PORT          GPIOA
#define USART2_RX_PIN           GPIO_PIN_3
#define USART2_RX_PORT          GPIOA

/* MC60 GNSS */
#define GNSS_UART5_TX_PIN       GPIO_PIN_12
#define GNSS_UART5_TX_PORT      GPIOC
#define GNSS_UART5_RX_PIN       GPIO_PIN_2
#define GNSS_UART5_RX_PORT      GPIOD

#define GNSS_VCC_EN_PIN         GPIO_PIN_4
#define GNSS_VCC_EN_PORT        GPIOC

#define PWRKEY_PIN              GPIO_PIN_12
#define PWRKEY_PORT             GPIOA


#endif // BOARD_CONFIG_H
