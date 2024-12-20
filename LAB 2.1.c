#include "stm32f1xx.h" 

#define LED1_PIN  GPIO_PIN_9
#define LED2_PIN  GPIO_PIN_8
#define LED3_PIN  GPIO_PIN_7
#define LED4_PIN  GPIO_PIN_6

#define LED_PORT GPIOB

void delay_ms(uint32_t ms) {
  for (uint32_t i = 0; i < ms * 1000; i++) {
      __NOP();
    }
}

int main(void) {
  RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin = LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);

  while (1) {
      HAL_GPIO_TogglePin(LED_PORT, LED1_PIN);
      delay_ms(500);
      HAL_GPIO_TogglePin(LED_PORT, LED2_PIN);
      delay_ms(500);
      HAL_GPIO_TogglePin(LED_PORT, LED3_PIN);
      delay_ms(500);
      HAL_GPIO_TogglePin(LED_PORT, LED4_PIN);
      delay_ms(500);

  }
}