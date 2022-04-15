FreeRTOS에서 하나의 task는 하나의 스레드(thread)를 의미한다.

3.1. Task의 특징과 생김새
각 task에는 우선순위를 할당하며 숫자가 높을수록 큰 우선순위를 의미한다.

우선순위는 0부터 configMAX_PRIORITIES까지 할당이 가능하다.
우선순위가 높은 task는 낮은 task를 선점(preemption)할 수 있고, 이때 context switching이 발생한다.
동일한 우선순위 사이에서는 round robin을 사용한다.
Task는 return value가 없으며 (void*) 타입으로 여러 자료형을 매개변수로 받을 수 있다.

Task는 일회용 task와 주기적 task 2가지 종류가 있다.

일회용 task는 기능을 한 번 수행한 뒤 마지막에 스스로를 삭제한다. (꼭 해줘야 함.)
    void 태스크이름( void* pvParameters ) {
        /* 어쩌고 저쩌고 */
        vTaskDelete(NULL);	// 꼭 해줘야 함.
    }
주기적 task는 무한 loop가 들어있다. Delay 또는 suspend 함수 등으로 task의 state가 blocked(waiting)로 변하지 않는 이상 계속해서 기능을 빠르게 반복 실행한다.
    void 태스크이름( void* pvParameters ) {
        while(true) {
            /* 어쩌고 저쩌고 */
        }
    }
각 task마다 local stack 공간이 할당된다. 이 공간은 메모리의 .bss영역 또는 .heap 영역에 들어간다.

Stack 메모리는 정적 또는 동적으로 할당이 가능하다.
후술하겠지만, stack 메모리 할당은 5가지 방법으로 사용자가 환경설정 할 수 있으며, 메모리 단편화(fragmentation)를 최대한 막으며 메모리를 할당한다.
configSUPPORT_DYNAMIC_ALLOCATION과 configSUPPORT_STATIC_ALLOCATION 값을 어떻게 설정하느냐에 따라, 그리고 task 생성 함수를 xTaskCreate나 xTaskCreateStatic중 어느 것을 사용하느냐에 따라 할당 방법이 달라진다.
