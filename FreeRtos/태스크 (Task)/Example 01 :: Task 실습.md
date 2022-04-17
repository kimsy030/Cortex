알파벳 ‘a’를 1초마다 한 번씩 출력하는 우선순위 10의 task1을 만든다.
알파벳 ‘b’를 1초마다 한 번씩 출력하는 우선순위 9의 task2를 만든다.
xTaskCreate((TaskFunction_t)Task1, "Task1", 128, NULL, 10, &xHandle1);
xTaskCreate((TaskFunction_t)Task2, "Task2", 128, (void*)Param, 9, &xHandle2 );
다양한 데이터를 담고있는 구조체를 만들고 task2의 parameter로 넘겨준다.
중간에 task1의 우선순위를 8로 낮춘다.
vTaskSuspend(xHandle1);
vTaskPrioritySet(xHandle1, 8);
vTaskResume(xHandle1);
task1과 task2의 vTaskDelay()를 주석처리 해보면서 두 task가 어떻게 작동하는지 확인한다.
.
Task1, 2 모두 vTaskDelay()를 주석처리 하지 않았을 때 결과다.
Task2의 우선순위가 task1보다 높기 때문에 먼저 b를 출력하고 1초간 blocked 된다.
이제 task1이 실행될 수 있으며 a를 출력하고 1초간 blocked 된다.
아무것도 실행되지 않으므로 idle task가 실행될 것이다.
Blocked state에서 벗어난 task2가 b를 출력하고 1초간 blocked 되는 과정이 반복된다.
.
Task 1의 vTaskDelay()를 주석했을 때 결과다.
먼저 task2가 시작되고, vTaskDelay()를 만난 뒤 blocked 되면 task1이 시작된다.
Task1은 빠른 속도로 a를 출력한다.
1초 이후 task2가 task1을 선점한 뒤 b를 1회 출력한 뒤 다시 blocked 된다.
(위 사진에는 안나와있지만, 한참 뒤에 b가 한 번 찍힌다.)
Task1은 다시 빠른 속도로 a를 출력하는 과정이 반복된다.
.
Task 2의 vTaskDelay()를 주석했을 때 결과다.
먼저 task2가 시작되며 blocked 될 일이 없기 때문에 task1은 영원히 실행되지 않는다.
.
Task 1, 2 모두 vTaskDelay()를 주석했을 때 결과다. (위 사진과 같은 결과)
먼저 task2가 시작되며 blocked 될 일이 없기 때문에 task1은 영원히 실행되지 않는다.
이번 실습을 통해 다음 세 가지를 배울 수 있었다.

FreeRTOS에서 멀티테스킹이 작동하는 방식 - Priority와 preemption.
Task를 생성하고 우선순위를 변경하며 관리하는 방법.
실행흐름을 올바르게 인식하지 못하면 task의 priority 설정을 잘못해 starvation을 유발할 수 있다.
