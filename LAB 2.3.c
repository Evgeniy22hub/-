#include "stm32f1xx_hal.h"

#define LED1_PIN  GPIO_PIN_9
#define LED2_PIN  GPIO_PIN_8
#define LED3_PIN  GPIO_PIN_7
#define LED4_PIN  GPIO_PIN_6

#define LED_PORT GPIOB

#define BUTTON_PIN GPIO_PIN_5
#define BUTTON_PORT GPIOA

#define TIMER_PRESCALER 72
#define TIMER_PERIOD 1000

volatile uint32_t timer_tick = 0;

void SysTick_Handler(void) {
    timer_tick++;
}

void delay_ms(uint32_t ms) {
    for (uint32_t i = 0; i < ms * 1000; i++) {
        __NOP();
    }
}

int main(void) {
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin = LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = BUTTON_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(BUTTON_PORT, &GPIO_InitStruct);

    SysTick_Config(SystemCoreClock / TIMER_PRESCALER);
    NVIC_SetPriority(SysTick_IRQn, 1);

    while (1) {
         if (HAL_GPIO_ReadPin(BUTTON_PORT,BUTTON_PIN) == GPIO_PIN_SET) {
             HAL_GPIO_TogglePin(LED_PORT, LED1_PIN);
             delay_ms(100);
             HAL_GPIO_TogglePin(LED_PORT, LED2_PIN);
             delay_ms(100);
             HAL_GPIO_TogglePin(LED_PORT, LED3_PIN);
             delay_ms(100);
             HAL_GPIO_TogglePin(LED_PORT, LED4_PIN);
             delay_ms(100);
        }
    }
}