/*문자열 개수 N과 N개의 문자열이 주어질 때, 포인터 배열을 사용하여 가장 긴 문자열을 찾아 출력하시오.
[입력]
N
문자열1
문자열2
...
문자열N
[출력]
longest = <가장 긴 문자열>

[입력예시]
3
Pineapple
Pear
Mango
[출력예시]
longest = Pineapple
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n; // 받을 문자열 크기
    int idx = 0; // 가장 긴 문자열의 index
    int maxLongness = 0; // 문자열의 길이

    // 입력받을 문장 수 n개 입력
    scanf("%d", &n);

    // 2차원 동적 배열 할당 (한 문장에 255글자 입력가능)
    char **str = (char**)malloc( n * sizeof(char*));
    for(int i = 0; i < n; i++) {
        *(str + i) = (char*)malloc( 256 * sizeof(char));
    }

    // 문장 n회 입력
    for(int i = 0; i < n; i++) {
        scanf("%s", *(str + i));
    }

    for(int i = 0; i < n; i++) {
        int j = 0; // n번째 str의 글자상태를 확인하기 위한 임시 index
        while(*(*(str + i) + j) != '\0'){
            j++;
        }
        if (maxLongness <= j){
            maxLongness = j;
            idx = i;
        }
    }

    printf("longest = %s\n", *(str + idx));

    // 동적 배열 해제
    for(int i = 0; i < n; i++) {
        free(str[i]);
    }
    free(str);

    return 0;
}