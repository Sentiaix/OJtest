'''PYTHON2025 2학기 컴공 
#소스코드 한글지원 안됩니다.

#----------------------------------------------------------------------------------------------------------------------------------------------------------
사용하여 다양한 기하학 도형을 관리하는 프로그램을 구현하시오. 도형의 종류를 관리하는 부모 클래스와, 구체적인 수학적 계산을 처리하는 자식 클래스를 각각 작성해야 한다.

1. 부모 클래스: Shape
다음 기능을 가진 Shape 클래스를 정의하시오.
	•__init__(self, shape): 도형의 종류를 나타내는 문자열(예: "Rectangle")을 입력받아 인스턴스 변수에 저장한다.
	•print_shape(self): 도형의 종류를 다음 형식으로 출력한다. (출력 후 줄 바꿈이 없어야 함)
		-형식: Type: [도형이름] --> 
2. 자식 클래스 
Shape 클래스를 상속받는 두 개의 클래스 Rectangle과 Circle을 작성하시오.
	• Rectangle 클래스:
		-속성: x1, y1 (좌측 상단 좌표), x2, y2 (우측 하단 좌표).
		- __init__: 4개의 정수를 입력받는다. 부모 클래스의 생성자를 호출하며 "Rectangle" 문자열을 전달해야 한다.
		- calcArea(): 면적을 계산하여 반환한다. 
	• Circle 클래스:
		- 속성: x, y (중심 좌표), r (반지름).
		-__init__: 3개의 정수를 입력받는다. 부모 클래스의 생성자를 호출하며 "Circle" 문자열을 전달해야 한다.
		- calcArea(): 면적을 계산하여 반환한다. 
3. 실행 및 입력 처리
다음 기능을 수행하는 메인 코드를 작성하시오.
	1.사용자로부터 도형의 종류를 입력받는다.
		- 도형 종류 입력은 대소문자를 구분하지 않아야 한다(Case-insensitive). 
		  즉, Rectangle, reCtAngLe, CIRCLE, circle 등의 입력이 모두 유효하게 처리되어야 한다.
	2. 입력된 종류에 따라 치수(Dimension)를 입력받는다.
		-직사각형(Rectangle): "x1,y1,x2,y2" 형식 (쉼표로 구분)
		-원(Circle): "x,y,r" 형식 (쉼표로 구분)
	3. 입력받은 정보를 이용해 객체를 생성하고 shapeList 리스트에 저장한다.
	4.반복문을 통해 리스트에 저장된 모든 객체에 대해 print_shape()(부모 메소드)와 calcArea()(자식 메소드)를 호출하여 결과를 출력한다.

#----------------------------------------------------------------------------------------------------------------------------------------------------------

#실행 결과 예시:
Enter 3 shapes (rectangle/circle).

Enter shape type: rectangle
Enter x1,y1,x2,y2: 1,8,7,1

Enter shape type: CIRCLE
Enter x,y,r: 2,2,3

Enter shape type: circLE
Enter x,y,r: 3,3,4

--- Final Report ---
Type: Rectangle --> Area: 42.00
Type: Circle --> Area: 28.27
Type: Circle --> Area: 50.27
'''

class Shape:
    def __init__(self, shape):
        self.shape = shape
    def print_shape(self):
        print(f"Type: {self.shape}", end='')

class Rectangle(Shape):
    def __init__(self, n):
        pass