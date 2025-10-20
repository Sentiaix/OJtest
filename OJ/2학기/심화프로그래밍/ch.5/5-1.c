/*##문제 설명
3x3 크기의 정수형 배열 mx와 my를 선언한다. 
배열 mx와 my에 사용자로부터 정수를 입력 받은 후, 각 위치 요소의 mx 값에서 my 값을
뺀다. 뺄셈 결과 값을 다시 mx에 저장하고, 저장된 값을 읽어 출력하는 프로그램을 만든다.

--

##입력 예시1
0 0 0 0 0 0 0 0 0
1 2 3 4 5 6 7 8 9

#출력 예시1
-1-2-3
-4-5-6
-7-8-9

--

##입력 예시2
5 5 5 5 5 5 5 5 5
5 5 5 5 5 5 5 5 5

#출력 예시2
000
000
000
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int mx[3][3], my[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &mx[i][j]);
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &my[i][j]);
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            mx[i][j] = mx[i][j] - my[i][j];
        }
    }
    
    for(int i = 0; i < 3; i++){
        printf("%d%d%d\n", mx[i][0], mx[i][1], mx[i][2]);
    }

    return 0;
}