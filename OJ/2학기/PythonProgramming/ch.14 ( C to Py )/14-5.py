'''사용자로부터 배열의 크기와 값을 순서대로 입력받아 값을 반전시킨 후 출력할 인덱스를 입력받아 해당 인덱스의 값을 출력하는 프로그램을 작성하시오.
(단 배열의 최대 크기는 20임)

# 입출력 예시1
Array size: 10
1
2
3
4
5
6
7
8
9
10
Index: 0
Value: 10

# 입출력 예시2
Array size: 9
8
7
6
10
3
4
17
38
5
Index: 3
Value: 4

# 입출력 예시3
Array size: 5
9
8
7
6
5
Index: 2
Value: 7'''
# i am vibe coder

size = int(input("Array size: "))

arr = [] # 빈 list(array)

for i in range(size):
    a = int(input())
    arr.append(a)

arr.reverse()

idx = int(input("Index: "))
print("Value:", arr[idx])