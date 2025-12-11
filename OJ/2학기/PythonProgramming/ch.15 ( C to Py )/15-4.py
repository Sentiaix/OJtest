'''
두 개의 문자열 s1, s2를 입력 받고, s1과 s2에 같은 index에 있는 문자들을 비교해서 같으면 O 다르면 X를 출력하는 프로그램을 작성하시오.
(단, 문자열의 길이는 모두 30을 넘지 않는다.)

[입력 예시1]
struct1 starcity

[출력 예시1]
OOXXOXXX

[입력 예시2]
hello test

[출력 예시2]
XOXXX
'''

s1, s2 = input().split()
length = 0
diff_len = 0

if len(s1) > len(s2):
    length = len(s1)
    diff_len = len(s1) - len(s2)
elif len(s1) == len(s2):
    length = len(s2)
else:
    length = len(s2)
    diff_len = len(s2) - len(s1)

for i in range(length - diff_len):
    if s1[i] == s2[i]:
        print("O", end='')
    else:
        print("X", end='')

for i in range(diff_len):
    print("X", end='')