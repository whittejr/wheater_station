message(STATUS "Configurando paths e flags para a familia STM32F1...")

set(THIRD_PARTY "${CMAKE_CURRENT_SOURCE_DIR}/lib/third_party/stm32cubef1/Drivers")
SET(MCU_LINKER STM32F101X6_FLASH.ld)
SET(MCU_STARTUP startup_stm32f101xe.s)
set(CMSIS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/third_party/stm32cubef1/Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/")
set(LINKER_SCRIPT "${CMSIS_DIR}/gcc/linker/${MCU_LINKER}")
set(STARTUP_FILE "${CMSIS_DIR}/gcc/${MCU_STARTUP}")

set(HAL_SOURCES
    ${STARTUP_FILE}
    "${THIRD_PARTY}/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal.c"
    "${THIRD_PARTY}/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_cortex.c"
    "${THIRD_PARTY}/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc.c"
    "${THIRD_PARTY}/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_rcc_ex.c"
    "${THIRD_PARTY}/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_gpio.c"
    "${THIRD_PARTY}/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_dma.c"
    "${THIRD_PARTY}/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_pwr.c"
    "${THIRD_PARTY}/STM32F1xx_HAL_Driver/Src/stm32f1xx_hal_uart.c"
    
    "${CMSIS_DIR}/system_stm32f1xx.c"
)

set(HAL_INCLUDES
    "${THIRD_PARTY}/STM32F1xx_HAL_Driver/Inc"
    "${THIRD_PARTY}/CMSIS/Device/ST/STM32F1xx/Include"
    "${THIRD_PARTY}/CMSIS/Core/Include"
)

add_compile_definitions(
    USE_HAL_DRIVER
    ${TARGET_MCU} # Deve ser algo como STM32F103xB no seu CMakePresets.json
)

# Cortex M3 flags
set(CPU_FLAGS -mthumb -mcpu=cortex-m3 -mfloat-abi=soft)

add_compile_options(${CPU_FLAGS})
add_link_options(${CPU_FLAGS})