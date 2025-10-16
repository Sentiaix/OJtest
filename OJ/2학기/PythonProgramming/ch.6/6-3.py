'''String을 입력 받아 영문 소문자, 대문자, 스페이스만 출력하는 alpha_space함수를 작성하라. 
아래 사용 코드와 입출력 예시를 참조하고, 문제가 너무 쉬우면 재귀 함수로 구현해보자.
s = input('Enter string: ')
alpha_space(s)

입출력 예시 1:
Enter string: without, any punctuation?
without any punctuation

입출력 예시 2:
Enter string: no 745136numbers #$%$%%$allowed
no numbers allowed
'''

result =''

def alpha_space(s):
    global result
    if len(s) == 0:
        return result
    if s[0].isalpha() or s[0].isspace() :
        result += s[0]
    return alpha_space(s[1:])



s = input('Enter string: ')
print(alpha_space(s))