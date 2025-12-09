'''2보다 큰 int을 크기로 입력 받아, ‘*’이 들어간 상자를 ‘M’으로 그려라.

입출력 예시 1: 3이 입력
3
MMM
M*M
MMM

입출력 예시 2: 7이 입력
7
MMMMMMM
M*****M
M*****M
M*****M
M*****M
M*****M
MMMMMMM

입출력 예시 3: 5가 입력
5
MMMMM
M***M
M***M
M***M
MMMMM'''

size = int(input())

if size <= 2: # size는 2보다 커야 함.
    exit()

print('M' * size)
for i in range(size - 2):
    print('M', end='')
    print('*' * (size - 2), end='')
    print('M')
print('M' * size)