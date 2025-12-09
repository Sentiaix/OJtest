'''
사용자로부터 삼각형의 밑변과 높이를 정수로 입력 받아 넓이를 계산한 후 전체 자릿수는 10자리, 소숫점 이하 2자리의 실수로 맞춰서 출력하는 프로그램을 작성하시오.
(단, 삼각형의 넓이는 밑변*높이/2로 계산함)

# 입출력 예시1
Width and height: 30 20
Area:     300.00

# 입출력 예시2
Width and height: 15 23
Area:     172.50

# 입출력 예시3
Width and height: 9 31
Area:     139.50
'''

w, h = map(int, input("Width and height: ").split())

area = w * h / 2
print("Area: %10.2f" % area)