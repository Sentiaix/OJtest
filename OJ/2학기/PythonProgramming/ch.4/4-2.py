'''
PYTHON2025 2학기 컴공 4장 문제 2
#소스코드 한글지원 안됩니다.

#-----------------------------------------------------------------------------------------------------------------------------------------------
미세먼지 농도 예보 기준이 다음과 같을 때 미세먼지 농도를 정수 값으로 입력 받아 'Good ;)',  'Normal :)',  'Bad :(',  'Very bad :(('을 출력하는 코드를 작성하여라(단위 ㎍/m3).

Good: 0~15
Normal: 16 ~ 35
Bad: 36~ 75
Very bad:  76 이상 

#사용자를 위한 메시지: "Enter the fine dust concentration (unit: microgram/m^3) : "
#-----------------------------------------------------------------------------------------------------------------------------------------------

a) 실행 결과 예시:
Enter the fine dust concentration (unit: microgram/m^3) : 5
Good ;)

b) 실행 결과 예시:
Enter the fine dust concentration (unit: microgram/m^3) : 76
Very bad :((

'''

x = int(input("Enter the fine dust concentration (unit: microgram/m^3) : "))
if 0 <= x < 16 :
    print("Good ;)")
elif 16 <= x < 36 :
    print("Normal :)")
elif 36 <= x < 76 :
    print("Bad :(")
elif x >= 76 :
    print("Very bad :((")