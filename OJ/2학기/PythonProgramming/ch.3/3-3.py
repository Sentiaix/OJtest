'''
아래 input함수를 사용해서 문자열을 받고, 받은 문자열을 float으로 변경하라. 
float값에 float값을 int로 변환 값을 거듭제곱해서 예시와 같이 출력하라.
s = input('enter float: ') #s는 문자열로 입력된다'''

s = input('enter float: ')
sf = float(s)
si = int(sf)

print(f"{sf}**int({sf})={sf ** si}")