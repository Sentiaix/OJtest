'''문자열, 인덱스, 문자를 입력 받아 문자열의 인덱스번째 값을 문자로 변경해주는 change함수를 구현하라. 
아래 활용 코드와 입출력 내용을 확인해서 함수를 구현하라.
string = input('Enter string: ')
i = int(input('Enter index: '))
c = input('Enter char: ')
string = change(string, i, c)
print(string)

입출력 예시 1:
Enter string: Hello world
Enter index: 5
Enter char: X
HelloXworld

입출력 예시 2:
Enter string: Really?
Enter index: 0
Enter char: K
Keally?'''

def change(string, i, c):
    return string[:i] + c + string[i+1:] # 슬라이싱을 이용하여 string i-1번째까지, c 한 글자(기존 i자리), string i+1번째로 새로운 문장 구성

string = input('Enter string: ')
i = int(input('Enter index: '))
c = input('Enter char: ')

string = change(string, i, c)

print(string)