//LED 3개가 0.5초 간격으로 하나씩 켜지고 꺼짐
int main(void)
{
      HAL_Init();
      SystemClock_Config();
      MX_GPIO_Init();

      while (1)
      {
            u8 a;
            for (a = 1; a < 8; a*=2){
              HAL GPIO TogglePin(GPIOE, a*4);
              HAL_Delay(500);
            }
       }
}
