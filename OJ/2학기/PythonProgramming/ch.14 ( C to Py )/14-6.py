'''4명의 학생의 C, C++, JAVA, PYTHON 과목 시험 2회분 점수를 입력 받아, 평균(소수점 이하 버림)을 구하는 프로그램을 작성할 것이다. 
아래의 소스코드의 사용하여, 추가로 작성을 하라.
(단, 함수와 배열 둘 다 사용 해야 하며, main 함수의 점수 입력 외 다른 코드 작성 불가함.)

#include < stdio> // 공백 없이 사용

void get_average(int arr1[4][4], int arr2[4][4], int arr3[4][4], int size) {
    // 함수 구현

    // 배열 출력
}

int main() {

    int test1[4][4];
    int test2[4][4];
    int average[4][4];

    printf("First Test\n");
    // 1회차 점수 입력

    printf("Second Test\n");
    // 2회차 점수 입력

    get_average(test1, test2, average, 4);

    return 0;
}

# 입출력 예시
First Test
89 74 68 41
46 54 98 31
65 77 94 88
11 68 75 46
Second Test
87 48 85 96
31 65 87 44
25 98 77 63
15 32 87 35
Average
88 61 76 68 
38 59 92 37 
45 87 85 75 
13 50 81 40
# 이 문제는 C문제를 Python으로 변환하는 문제입니다.
# main() 함수를 선언 할 필요가 없습니다.
'''

# input format
# C, C++, JAVA, PYTHON

def get_average(test1, test2, size):
    # arr3은 C언어 구조상 필요했지만(avg) python에선 필요 없음
    avg = []
    for i in range(size):
        avg_line = []
        for j in range (size):
            avg_line.append((test1[i][j] + test2[i][j]) // 2)
        avg.append(avg_line)
    print("Average")
    for i in range(size):
        for j in range(size):
            print(avg[i][j], end=' ')
        print()

print("First Test")
test1 = []
for _ in range(4):
    scores = list(map(int, input().split()))
    test1.append(scores)

print("Second Test")
test2 = []
for _ in range(4):
    scores = list(map(int, input().split()))
    test2.append(scores)

get_average(test1, test2, 4)