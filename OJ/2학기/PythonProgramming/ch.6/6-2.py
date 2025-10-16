'''Int 4개를 string으로 입력 받아서 int 4개로 변환해주는 함수와, int 4개를 받아서 정렬해주는 함수를 작성하라. 
String에서 숫자는 space로 나누어진다. 
아래 활용 코드와 입출력 예시를 확인해서 str2num, mysort 함수를 구현하라.
string = input('Enter 4 int: ')
a, b, c, d = str2num(string)
print(a, b, c, d)
a, b, c, d = mysort(a,b,c,d)
print(a, b, c, d)

입출력 예시 1:
Enter 4 int: 1543 854 36 7
1543 854 36 7
7 36 854 1543

입출력 예시 2:
Enter 4 int: 41 563 789 231
41 563 789 231
41 231 563 789'''

# int to string
def str2num(string):
    tmp_list = string.split() # space 기준으로 나누기
    return int(tmp_list[0]), int(tmp_list[1]), int(tmp_list[2]), int(tmp_list[3]) # 각 요소 int로 변환하여 반환

# sorting
def mysort(a, b, c, d):
    num_list = [a, b, c, d] # 입력받은 4개의 int를 리스트로 구성
    num_list.sort() # 리스트 정렬
    return num_list[0], num_list[1], num_list[2], num_list[3] # 정렬된 리스트의 요소 반환

string = input('Enter 4 int: ')
a, b, c, d = str2num(string)
print(a, b, c, d)
a, b, c, d = mysort(a,b,c,d)
print(a, b, c, d)
    