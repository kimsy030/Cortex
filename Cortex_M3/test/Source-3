//LED 커튼 닫고/열기

int main(void)
{
      HAL_Init();
      SystemClock_Config();
      MX_GPIO_Init();

      while (1)
      {
            u8 a;
            for (a = 1; a < 8; a*=2){
                HAL GPIO WritePin(GPIOE, a*4, GPIO_PIN_SET);
                HAL_Delay(500);
            }
            for (a = 4; a > 0; a/=2){
                HAL GPIO WritePin(GPIOE, a*4, GPIO_PIN_RESET);
                HAL_Delay(500);
            }
       }
}
