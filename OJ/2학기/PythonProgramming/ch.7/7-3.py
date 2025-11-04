'''PYTHON2025 2학기 컴공 7장 문제 3
#소스코드 한글지원 안됩니다.

#------------------------------------------------------------------------------------------------------------------------------------------------
다음과 같이 자동차의 연료 탱크 프로그램을 시뮬레이션하여 보자. 초기 연료의 양은 500으로 두자. 사용자가 주행을 하면 연료가 줄어들고 충전을 하면 연료가 증가한다. 이 때 연료의 사용과 충전은 -/+ 기호와 함께 입력하도록 한다. 반복문을 사용하여 사용자로부터 충전 또는 사용한 연료를 입력 받아서 현재 남아 있는 양을 계속 출력하고 연료 탱크에 남아있는 연료가 10% 미만이면 경고를 출력하고 프로그램 수행을 마친다.

#--------------------------------------------------------------------------------------------------------------------------------------------------

실행 결과:
Enter the amount of fuel charged or used (use + or - sign): +20
The tank level is 520 liters.
Enter the amount of fuel charged or used (use + or - sign): -400
The tank level is 120 liters.
Enter the amount of fuel charged or used (use + or - sign): -110
The tank level is 10 liters.
Warning: Fuel level is below 10%, please refill!
'''

fuel = 500

while True:
    change = int(input("Enter the amount of fuel charged or used (use + or - sign): "))
    fuel += change
    print(f"The tank level is {fuel} liters.")
    if fuel < 50: # 10% of 500 is 50
        print("Warning: Fuel level is below 10%, please refill!")
        break