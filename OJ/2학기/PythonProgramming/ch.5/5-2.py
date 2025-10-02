'''
#소스코드 한글지원 안됩니다.


#다음 제시된 순서대로 코드를 작성하고, 실행결과 처럼 완성한다.


#1 문자열의 양끝에서 문자가 제거되어 출력되도록 한다 

t="   hello   \t\n" #hello 앞에 3칸,뒤에 3칸 공백
print(t._______) 

#2."iced coffee" 문자열에서 "iced"를 "hot"으로
단어를 교체하는 프로그램을 출력하고, 대문자로 출력한다.

s = "iced coffee"
news = replace() 이용
print() 
print(),upper()

Tip. 
strip(), replace(), upper()

#실행결과
hello
hot coffee
HOT COFFEE
'''

t="   hello   \t\n" 
print(t.strip())

s = "iced coffee"
news = s.replace("iced", "hot")
print(news)
print(news.upper())