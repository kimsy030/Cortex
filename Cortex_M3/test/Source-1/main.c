int main(void)
{
      HAL_Init();
      SystemClock_Config();
      MX_GPIO_Init();

      while (1)
      {
           HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_SET); // 2, 3, 4번 LED 점등
           HAL_Delay(500); // 500만큼 Delay
           HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4, GPIO_PIN_RESET); // 2, 3, 4번 LED 소등
           HAL_Delay(500);
      }
      ======================================================================================================================
      while (1)
      {
           HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4);
           HAL_Delay(500); // ON일 때 500, OFF일 때 500 Delay
      }
      
      // GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4 = (4  + 2 + 1) * 4
}
