//다음 스위치를 눌렀다 떼면 주어진 조건과같이 동작
//   - BTN1 : LED2 ON - BTN2 : LED3 ON - BTN3 : LED4 ON - BTN4 : LED2,3,4 ON	
//   - BTN5 : LED2,3,4 Blink 0.5초 간격	(다른 버튼을 누를 때까지 유지.)

int READ_PIN(int SW){
    if(HAL_GPIO_ReadPin(*GPIOC, GPIO_PIN_0) == 0) return 1;
    else if(HAL_GPIO_ReadPin(*GPIOC, GPIO_PIN_1) == 0) return 2;
    else if(HAL_GPIO_ReadPin(*GPIOC, GPIO_PIN_2) == 0) return 4;
    else if(HAL_GPIO_ReadPin(*GPIOC, GPIO_PIN_3) == 0) return 7;
    else if(HAL_GPIO_ReadPin(*GPIOC, GPIO_PIN_4) == 0) return 8;
    else return SW;
}

int main(void)
{
      HAL_Init();
      SystemClock_Config();
      MX_GPIO_Init();

      while (1)
      {
            if(((SW = READ_PIN(SW)) == 1) || (SW == 2) || (SW == 4)) {
    	                HAL_GPIO_WritePin(GPIOE, SW*4, GPIO_PIN_SET);
    	                HAL_GPIO_WritePin(GPIOE, (7-SW)*4, GPIO_PIN_RESET);
            }
            else if(SW == 7)
    	                HAL_GPIO_WritePin(GPIOE, SW*4, GPIO_PIN_SET);

            else if(SW == 8){
    	                HAL_GPIO_TogglePin(GPIOE, (SW-1)*4);
    	                HAL_Delay(500);
            }	
       }
}
