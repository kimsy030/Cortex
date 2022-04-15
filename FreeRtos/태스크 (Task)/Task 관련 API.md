3.2. Task 관련 API
6가지 API가 주로 사용되며 앞 3개가 중요하고, 뒤 3개는 잘 안 쓴다.

xTaskCreate()

.

pvTaskCode는 task의 기능이 선언된 함수의 함수포인터를 말한다.
pcName은 디버깅 용도로 사용하는 문자열이며 task의 이름을 말한다.
usStackDepth는 task마다 할당되는 stack 메모리를 말한다. 단위는 WORD이며 우리가 사용하는 ARM Cortex-M보드에서는 1WORD == 4Byte라는 점을 기억하자.
pvParameters는 task 함수로 전달할 매개변수를 말한다. 없다면 NULL 쓰면 된다. 전달할 매개변수를 (void*) 타입으로 캐스팅한 뒤 여기다가 넣어주면 task 함수에서 사용할 수 있다.
pxCreatedTask는 task를 제어하기 위한 TaskHandle_t 타입 핸들을 말한다. Task의 우선순위를 바꾸거나, task를 멈추거나 등 task에 대한 설정은 모두 이 핸들을 통해서 이뤄진다.
`xTaskCreate((TaskFunction_t)foo, “task”, 64, NULL, 10, handle);``
vTaskDelay()

.

Task의 상태를 running에서 blocked(waiting)으로 변경하는 함수다. 설정된 시간 xTicksToDelay동안 해당 task는 blocked task가 되며, 다음 우선순위를 가진 task가 실행된다.
확장성 및 이식성 좋은 코드를 만들기 위해서 tick단위 시간을 사용하는 것 보다 pdMS_TO_TICKS() 매크로를 사용해서 우리에게 편한 ms(밀리초) 단위를 tick으로 변환해서 사용하는 것이 좋다.
왜냐하면, 사용하는 보드와 사용자 환경설정 값에 따라 1 Tick이 의미하는 시간이 다르기 때문이다.
문서에서도 그렇게 권장하고 있다.

vTaskDelayUntil()

.

vTaskDelay()와 똑같은 기능을 수행하지만, 작동 방식이 조금 다르다.

vTaskDelay()는 호출 시점부터 지정된 시간만큼 blocked 되는 반면,
vTaskDelayUntil()은 호출 시점과 관계 없이 목표 절대 시간 주기에 맞춰 blocked 된다.

vTaskSuspend() 와 vTaskResume()

Delay 함수는 task를 일정 시간동안 blocked state로 만들지만, suspend 함수는 task를 기약없이 blocked state로 만든다.
Suspend 된 task는 resume 함수를 사용할 때 까지 계속 blocked state가 된다.
Task의 우선순위를 바꿀 때 task를 일단 blocked state로 만들 필요가 있다. 이때 사용한다.
괄호 안에는 task의 handle이 들어간다는 점을 잊지말자.
vTaskPrioritySet()

Task의 우선순위를 바꾼다.
