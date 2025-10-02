'''PYTHON2025 2학기 컴공 5장 문제 4
#소스코드 한글지원 안됩니다.


#다음 제시된 순서대로 코드를 작성하고, 실행결과 처럼 완성한다.

# "Hello Chosun" 문자열에는 문자 'o'가 2개 있다. 
두 번째 단어부터 검색해서 'o'의 인덱스를 출력하는 프로그램을 작성한다. 


#1. 
s = "Hello Chosun"

#2
news = ___strip()

#3 find() 를 사용하여 문자열을 추출하고 

idx = news.find(' ')

#4 Hello 첫번째 글자에서 o 에 해당되는 것을 찾아서 두번째 단어부터 검색해서출력
print___find('o'))

#5 Chosun 두번째 글자에서 o 에 해당되는 것을 찾아서 두번째 단어부터 검색해서출력
print(_____find('o'))

#실행결과
3
2
'''

s = "Hello Chosun"
news = s.strip()
idx = news.find('o') # 첫 번째 o 위치
print(news[idx+1:].find('o'))
idx = news.find(' ') # 공백 위치
print(news[idx+1:].find('o')) # 두번째 글자부터 검색

 