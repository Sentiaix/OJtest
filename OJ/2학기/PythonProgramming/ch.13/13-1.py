'''PYTHON2025 2학기 컴공 12장 문제 1
#소스코드 한글지원 안됩니다.

#------------------------------------------------------------------------------------------------------------------------------------------------
다음과 같은 기능을 가지는 Counter 클래스를 정의하고 c1, c2라는 이름의 인스턴스를 생성하여라.
- 이 클래스는 __number라는 속성 값을 가진다.
- number를 매개변수로 가지는 __init__(self, number) 메소드를 가진다. 
number의 디폴트 매개변수 값은 0이다. number가 100 이상이 되거나 -1 이하가 되면 0 값을 초기 값으로 가진다.
- __number를 0으로 초기화하는 reset() 메소드를 가진다.
- __number를 1 증가시키는 inc() 메소드를 가진다. __number가 100 이상이 되면 0으로 초기화된다.
- __number를 1 감소시키는 dec() 메소드를 가진다. __number가 -1 이하가 되면 0 값을 가진다.
- C(n)과 같이 n을 출력하는 __str__() 특수 메소드를 가진다.

이 인스턴스를 사용하여 다음 예제 1, 예제 2와 같은 코드를 작성하고 그 결과가 아래와 같이 나오도록 하시오.

#--------------------------------------------------------------------------------------------------------------------------------------------------
  
# 예제     
c1 = Counter(10)
c1.inc()
print('c1 =', c1)

c2 = Counter()
c2.inc()
c2.inc()
c2.dec()
print('c2 =', c2)
c2.reset()
print('c2 =', c2)

#실행결과
c1 = C(11)
c2 = C(1)
c2 = C(0)'''

class Counter:
    def __init__(self, number = 0):
        if number <= -1 or number >= 100:
            self.__number = 0
        else:
            self.__number = number
    def reset(self):
        self.__number = 0
    def inc(self):
        self.__number += 1
        if self.__number >= 100:
            self.__number = 0
    def dec(self):
        self.__number -= 1
        if self.__number <= -1:
            self.__number = 0
    def __str__(self):
        return f'C({self.__number})'

# 예제
c1 = Counter(10)
c1.inc()
print('c1 =', c1)

c2 = Counter()
c2.inc()
c2.inc()
c2.dec()
print('c2 =', c2)
c2.reset()
print('c2 =', c2)