'''정수 n을 입력받아, n의 끝자리수를 출력하는 프로그램을 작성하시오.
(단, n이 음수 또는 0일 경우 Error!를 출력한다.)

# 입출력 예시1
Input number: 4326
The last number is 6.

# 입출력 예시2
Input number: -4652
Error!

# 입출력 예시3
Input number: 0
Error!
'''

n = int(input("Input number: "))

if n <= 0:
    print("Error!")
else:
    last_digit = n % 10
    print(f"The last number is {last_digit}.")