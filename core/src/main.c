/**
* @file    main.c
* @brief   none
* @version 0.1.0
* @a* @author  Your name here
* @date    2026-03-31
*/

#include <stdint.h>
#include <string.h>
#include "board_config.h"
#include "stm32f1xx_hal.h"
#include "gpio.h"
#include "delay.h"
#include "uart.h"

void dummy_init(void);
void dummy_read(void);
void testar_modulo(void);

extern UART_HandleTypeDef huart2; 
// Altere para a instância da UART que está fisicamente ligada ao pino GNSS_TX
extern UART_HandleTypeDef huart5; 

// Buffer para capturar uma sentença NMEA bruta (ex: $GPRMC, $GPGGA...)
uint8_t buffer_bruto_gnss[100]; 
uint8_t buffer_teste_at[50];

int main(void)
{
    HAL_Init();
    dummy_init();
    
    testar_modulo();

    while (1) {
        dummy_read();
        bsp_delay_ms(100);
    }
    return 0;
}

void dummy_init(void) {
    bsp_gpio_init();
    uart_init();
   
    bsp_gpio_write(GNSS_VCC_EN_PORT, GNSS_VCC_EN_PIN, 1);
    bsp_delay_ms(100);

    // 2. Pulso no PWRKEY: O datasheet do MC60 exige que o pino fique em 
    // nível ALTO por pelo menos 1.2 segundos (1200ms) para iniciar o boot.
    bsp_gpio_write(PWRKEY_PORT, PWRKEY_PIN, 1);
    bsp_delay_ms(1200); 
    bsp_gpio_write(PWRKEY_PORT, PWRKEY_PIN, 0);

    // 3. Aguarda o firmware interno do MC60 estabilizar após o boot
    bsp_delay_ms(3000);

    HAL_UART_Transmit(&huart2, (uint8_t*)"AT+QGNSSC=1\r\n", 13, 1000);
    bsp_delay_ms(1000);
}

void dummy_read(void) {
    memset(buffer_bruto_gnss, 0, sizeof(buffer_bruto_gnss));
    HAL_UART_Receive(&huart5, buffer_bruto_gnss, sizeof(buffer_bruto_gnss) - 1, 2000);
}

void testar_modulo(void) {
    // 1. Envia 'AT' algumas vezes para sincronizar a porta (Autobaud)
    for (int i = 0; i < 3; i++) {
        HAL_UART_Transmit(&huart2, (uint8_t*)"AT\r\n", 4, 500);
        bsp_delay_ms(200);
    }
    
    // 2. Limpa o buffer de teste
    memset(buffer_teste_at, 0, sizeof(buffer_teste_at));
    
    // 3. Envia o comando 'AT' final
    HAL_UART_Transmit(&huart2, (uint8_t*)"AT\r\n", 4, 500);
    
    // 4. Aguarda a resposta (o módulo deve responder com "OK")
    HAL_UART_Receive(&huart2, buffer_teste_at, sizeof(buffer_teste_at) - 1, 2000);
    
    // Coloque um breakpoint na linha abaixo e verifique o conteúdo de "buffer_teste_at"
    bsp_delay_ms(1); 
}
