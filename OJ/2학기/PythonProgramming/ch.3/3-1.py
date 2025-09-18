'''
아래 input함수를 사용해서 문자열을 받고, 받은 문자열을 3으로 곱해서 출력, 
문자열을 float으로 변경해서 float값, float값 곱하기 2, float값 나누기 3을 출력,
float값을 int로 변경해서 int값, int값 곱하기 2, int값 나누기 3을 출력하라.
s = input('enter float: ') #s는 문자열로 입력된다.
'''

s = input('enter float: ')
print(s * 3) # 받은 문자 3번 곱해서 출력

s = float(s) # 받은 문자 float변환하고 그대로, 곱2, 나누기3 해서 출력
print(f"{s} {s * 2} {s / 3}")
s = int(s) # 받은 문자 int변환하고 그대로, 곱2, 나누기3 해서 출력
print(f"{s} {s * 2} {s / 3}")