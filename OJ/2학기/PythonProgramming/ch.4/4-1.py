'''PYTHON2025 2학기 컴공 4장 문제 1
#소스코드 한글지원 안됩니다.
#------------------------------------------------------------------------------------------------------------------------------------------------
사용자로부터 2개의 정수 a, b를 입력받은 다음 a가 b의 배수인지 아닌지를 판단하여 출력하는 다음과 같은 프로그램을 작성하시오.

#------------------------------------------------------------------------------------------------------------------------------------------------

실행 결과 1:
Enter first integer: 15
Enter second integer: 5
"15" is a multiple of "5."

실행 결과 2:
Enter first integer: 131
Enter second integer: 52
"131" is not a multiple of "52."
'''

a = int(input("Enter first integer: "))
b = int(input("Enter second integer: "))

if a % b == 0 :
    print(f"\"{a}\" is a multiple of \"{b}.\"")
else:
    print(f"\"{a}\" is not a multiple of \"{b}.\"")