'''PYTHON2025 2학기 컴공 12장 문제 3
#소스코드 한글지원 안됩니다.

#------------------------------------------------------------------------------------------------------------------------------------------------
다음 요구사항을 만족하는 프로그램을 작성하시오.
요구사항
1.	Vehicle이라는 부모 클래스를 정의하시오.
  o	속성: brand (문자열)
  o	메소드:
		__init__(self, brand) → brand 초기화
		describe(self) → "Brand: 브랜드명" 문자열 반환
2.	Car라는 자식 클래스를 정의하시오.
  o	Vehicle 클래스를 상속받는다.
  o	추가 속성: model (문자열)
  o	추가 메소드:
		__init__(self, brand, model) → 부모 생성자 호출 후 model 초기화
		__str__(self) → "Brand: 브랜드명, Model: 모델명" 문자열 반환
3.	Car 클래스의 인스턴스를 1개 생성하고 출력하시오.


#--------------------------------------------------------------------------------------------------------------------------------------------------
# 예제    
my_car = Car("Hyundai", "Avante")
print(my_car)

실행 결과:
Brand: Hyundai, Model: Avante'''

class Vehicle:
    def __init__(self, brand = ''):
        self.brand = brand
    def describe(self):
        return f"Brand: {self.brand}"

class Car(Vehicle):
    def __init__(self, brand = '', model = ''):
        super().__init__(brand)
        self.model = model
    def __str__(self):
        return f"{super().describe()}, Model: {self.model}"

# 예제
my_car = Car("Hyundai", "Avante")
print(my_car)