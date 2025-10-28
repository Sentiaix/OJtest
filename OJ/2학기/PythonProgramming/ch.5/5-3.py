'''PYTHON2025 2학기 컴공 5장 문제 3
#소스코드 한글지원 안됩니다.


#다음 제시된 순서대로 코드를 작성하고, 실행결과 처럼 완성한다.

# 세 개 이상의 단어로 구성된 문자열을 3개를 입력받고
두번째 단어를 화면에 출력하는 프로그램을 작성한다.

1. 세 개 이상의 단어 입력 
apple coffee melon


#2 사용자로 부터 입력받은 문자열에 저장하고, strip()명령을 이용해서 
news = s.____ # 앞 뒤에 있는 공백 문자 제거

#3 첫 번째 공백을 찾아서 find() 사용, 두 번째 단어부터의 문자열을 구성
idx = ____find()
news = ___strip()
# 단어 사이에 공백 문자가 두 개 이상일 수 있으므로 strip() 사용

4. 
idx = news._____  # 두 번째와 세 번째 단어 사이의 공백 위치 파악
print(____)  # 두 번째 단어 출력



#실행결과
Enter a string: apple coffee melon
coffee
'''


# 세 개 이상의 단어 받기
s = input("Enter a string: ").strip() # ,strip()으로 공백 벗기고 받음

idx = s.find(' ') # 첫 공백 발견
news = s[idx + 1:].strip() # [a:b] 슬라이싱으로 idx뒤부터 적용

idx = news.find(' ') # 2단어만 있는 문장속에 단어 찾기
print(news[:idx]) # [a:b]이면 b-1까지만 적용됨