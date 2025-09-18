'''아래 input함수를 사용하여 문자열을 2개받고, int로 변환하라.
int값들의 float 나누기, int값들의 int 나누기 값을 입출력 예시를 따라 출력하라.
작은 따옴표, 큰 따옴표안에도 출력해보자.
sa = input('enter int a: ') #sa는 문자열로 입력된다.
sb = input('enter int b: ') #sb는 문자열로 입력된다.'''

sa = input('enter int a: ')
sb = input('enter int b: ')
sa = int(sa) #int변환
sb = int(sb)
print(f"{sa}/{sb}={sa/sb}")
print(f"{sa}//{sb}={sa//sb}")
print(f"\'{sa}/{sb}={sa/sb}\'")
print(f"\"{sa}//{sb}={sa//sb}\"")