FreeRTOS에서 변수명을 결정할 때 접두어는 아래와 같이 결정함.

c: char 타입을 의미.
s: int16_t 타입 (short)을 의미.
i: int32_t타입 (int)을 의미.
x: BaseType_t 타입을 의미. 상당히 자주 사용되는데, 구조체나 인스턴스 핸들 등 일반적인 타입을 제외하면 대부분 x.
u: unsigned를 의미.
p: 포인터 변수를 의미.
FreeRTOS에서 함수명을 결정할 때 접두어는 아래와 같이 결정.

v: void 반환값이 없는 함수를 의미.
x: 변수명의 접두어인 x와 같은 의미. BaseType_t를 반환하는 함수.
pv: void* 타입을 반환하는 함수.
prv: private 함수를 의미. 대표적으로 아무런 task도 실행되지 않을 때 실행되는 idle task가 호출하는 callback 함수 (hook)가 이 접두어를 사용.

FreeRTOS에서 매크로명은 그 매크로가 선언된 소스파일의 이름을 따라 결정.
예를 들어 무한정 기다림을 의미하는 portMAX_DELAY는 portable.h라는 커널 소스에 선언됨.
문서에 따르면 semaphore 관련 API는 거의 매크로로 구성돼있지만, 함수명 네이밍 규칙을 따라간다고 명시됨.
