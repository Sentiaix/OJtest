'''
영문 소문자, 대문자, 스페이스만 string을 입력 받아, 단어를 뒤에서부터 출력하는 reverse_words함수를 구현하라.
아래 활용 코드와 입출력 예시를 참고하여 재귀함수로 구현하라.
s = input('Enter alphabets and space only: ')
reverse_words(s)

입출력 예시 1:
Enter alphabets and space only: how do you do sir
sir do you do how

입출력 예시 2:
Enter alphabets and space only: foot foot wondering the world wondering
wondering world the wondering foot foot
'''

# 텍스트에서 숫자, 영문, 스페이스만 걸러내는 함수
outstr = ''
def text_num(s):
    global outstr
    if s == '':
        return
    if s[0].isalpha() or s[0].isdigit() or s[0].isspace(): # 알파벳, 스페이스바, 숫자 중 하나 인 경우
        outstr += s[0] # outstr에 저장
    text_num(s[1:]) # 다음 글자부터 확인하도록 슬라이싱

def reverse_words(s):
    r_str = s.split() # 공백 기준으로 단어 나누기
    r_str.reverse() # 단어 뒤집기
    return ' '.join(r_str) # 단어 합치기

s = input('Enter alphabets and space only: ')
text_num(s) # 숫자, 영문, 스페이스만 걸러내기
print(reverse_words(outstr)) # 단어 뒤집어서 출력