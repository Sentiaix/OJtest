'''
PYTHON2025 2학기 컴공 5장 문제 1
#소스코드 한글지원 안됩니다.


#다음 제시된 순서대로 코드를 작성하고, 실행결과 처럼 완성한다.

#1."apple leng***" 문자열의 길이를 출력하는 코드 작성
#2."apple leng***" 문자열에서 '*'의 길이를 출력하는 코드 작성

#3. 사용자로 부터 파일 이름을 "profile.jpg" 입력 받고,
변수 s에 서장하고, 
입력받은 것의 길이를 출력하고, 
확장자가 "jpg"이면 yes, 아니면 no 출력하는 프로그램 작성한다 (if,else)
출력문에서 f문자열을 이용해서 출력한다.
print(f"{s} yes")
print(f"{s} no")

Tip.
input(), 문자열,f문자열,endswith()

#실행결과------------------------------------
13
3
file name:profile.jpg 
11
profile.jpg yes
'''

str = "apple leng***"
print(len(str)) # 1."apple leng***" 문자열의 길이를 출력하는 코드 작성
print(str.count('*')) # 2."apple leng***" 문자열에서 '*'의 길이를 출력하는 코드 작성

s = input("file name:") # 3. 사용자로 부터 파일 이름을 "profile.jpg" 입력 받고,
print(len(s)) # 입력받은 것의 길이를 출력하고,
if s.endswith("jpg"): # 확장자가 "jpg"이면 yes, 아니면 no 출력하는 프로그램 작성한다 (if,else)
    print(f"{s} yes") # 출력문에서 f문자열을 이용해서 출력한다.
else:
    print(f"{s} no") # 아니면 no 출력