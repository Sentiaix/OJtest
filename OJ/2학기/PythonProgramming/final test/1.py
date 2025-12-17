'''PYTHON2025 2학기 컴공 
#소스코드 한글지원 안됩니다.

#----------------------------------------------------------------------------------------------------------------------------------------------------------
##다이아몬드 출력 프로그램

사용자로부터 양의 정수를 반복적으로 입력받아, 입력된 값에 따라 터미널에 다이아몬드 모양을 출력하는 프로그램을 작성하시오.

요구사항
1.	프로그램은 무한 반복으로 입력을 받되, 사용자가 "exit"을 입력하면 프로그램을 종료한다.
2.	사용자가 정수가 아닌 값을 입력한 경우 다음과 같이 오류 메시지를 출력하고 다시 입력받는다.
	<입력값>: input an integer
3.	사용자가 0 이하의 정수를 입력한 경우 다음 오류 메시지를 출력하고 다시 입력받는다.
	<입력값>: input POSITIVE integer
4.	양의 정수 n을 입력받으면, 프로그램은 높이가 2n - 1인 다이아몬드를 출력해야 한다.
5.	다이아몬드를 출력한 후에도 다시 입력을 받아 위 과정을 반복한다.

#----------------------------------------------------------------------------------------------------------------------------------------------------------

#실행 결과 예시:

input count: abc
abc: input an integer
input count: 2.2
2.2: input an integer
input count: 0
0: input POSITIVE integer
input count: 1
*
input count: 2
 *
***
 *
input count: 3
  *
 ***
*****
 ***
  *
input count: 4
   *
  ***
 *****
*******
 *****
  ***
   *
input count: exit'''


while(True):
    n = input("input count: ")
    if n == 'exit' :
        break
    else :
        try:
            n = int(n)
        except ValueError:
            print(f"{n}: input an integer")
            continue
    if n <= 0 :
        print(f"{n}: input POSITIVE integer")
        continue

    for i in range(n):
        for j in range(n - i - 1):
            print(" ", end='')
        for k in range(i * 2 + 1):
            print("*", end='')
        print()
    for i in range(n - 1):
        for j in range(i + 1):
            print(" ", end='')
        for k in range(n*2 - i*2 - 3):
            print("*", end='')
        print()
    # 역출력 해야함