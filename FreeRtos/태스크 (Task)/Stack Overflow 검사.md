우리는 앞서 각 task마다 지정된 크기의 local stack을 갖고있다고 배웠다. 만일 task 내에서 해당 stack size를 넘는 데이터를 선언하고 연산을 수행한다면 stack overflow가 발생할 것이다. 이 치명적인 fault를 어떻게 발견할 수 있을까? FreeRTOS는 stack overflow를 발견하기 위한 기초적인 두 가지 알고리즘을 제공한다.

FreeRTOSConfig.h 헤더파일 안에는 configCHECK_FOR_STACK_OVERFLOW라는 상수가 정의돼있다. 이 상수는 0, 1, 2 세 가지 값을 가질 수 있다. 0일 경우 stack overflow를 컨트롤러가 따로 검사하지는 않는다.



1번 방법
Stack 하위 빈 영역을 ‘0’으로 모두 초기화 한 뒤 context switching이 발생할 때 ‘0’ 패턴이 얼마나 남았는지를 통해 stack overflow를 검사하는 방법이다.
간단한 방법이지만, context switching 때만 검사하기 때문에 stack overflow를 발견했을 때 이게 언제 어디서 발생했는지는 알 수 없다.
2번 방법
Stack 하위 20Byte를 인식하기 편리한 정해진 패턴으로 초기화 한 뒤 이 패턴이 조금이라도 변경될 경우 stack overflow가 발생했다고 판단하는 방법이다.
1번 방법에 비해 속도는 느리지만 stack overflow가 발생하는 시점과 위치를 정확하게 알 수 있다. 하지만, 2번 방법도 모든 stack overflow를 찾지는 못한다.
