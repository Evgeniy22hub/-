/* STM32 Blue Pill: Blink an LED on PB9 */

#include "stm32f1xx_hal.h"

#define LED1_PIN                               GPIO_PIN_9
#define LED2_PIN                               GPIO_PIN_8
#define LED3_PIN                               GPIO_PIN_7
#define LED4_PIN                               GPIO_PIN_6
#define LED5_PIN                               GPIO_PIN_5
#define LED_GPIO_PORT                          GPIOB
#define LED_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOB_CLK_ENABLE()

int main(void)
{
  HAL_Init();

  LED_GPIO_CLK_ENABLE();

  GPIO_InitTypeDef GPIO_InitStruct;

  GPIO_InitStruct.Pin = LED1_PIN | LED2_PIN | LED3_PIN | LED4_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.Pin = LED5_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  while (1)
  {
      if(HAL_GPIO_ReadPin(LED_GPIO_PORT,LED5_PIN) == GPIO_PIN_SET){
        HAL_GPIO_TogglePin(LED_GPIO_PORT, LED1_PIN);
        HAL_Delay(500);
        HAL_GPIO_TogglePin(LED_GPIO_PORT, LED1_PIN);
        HAL_GPIO_TogglePin(LED_GPIO_PORT, LED2_PIN);
        HAL_Delay(500);
        HAL_GPIO_TogglePin(LED_GPIO_PORT, LED2_PIN);
        HAL_GPIO_TogglePin(LED_GPIO_PORT, LED3_PIN);
        HAL_Delay(500);
        HAL_GPIO_TogglePin(LED_GPIO_PORT, LED3_PIN);
        HAL_GPIO_TogglePin(LED_GPIO_PORT, LED4_PIN);
        HAL_Delay(500);
        HAL_GPIO_TogglePin(LED_GPIO_PORT, LED4_PIN);
      }
  }
}

void SysTick_Handler(void)
{
  HAL_IncTick();
}

void NMI_Handler(void)
{
}

void HardFault_Handler(void)
{
  while (1) {}
}


void MemManage_Handler(void)
{
  while (1) {}
}

void BusFault_Handler(void)
{
  while (1) {}
}

void UsageFault_Handler(void)
{
  while (1) {}
}

void SVC_Handler(void)
{
}


void DebugMon_Handler(void)
{
}

void PendSV_Handler(void)
{
}