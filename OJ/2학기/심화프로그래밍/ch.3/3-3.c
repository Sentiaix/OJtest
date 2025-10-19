/*Switch를 사용하여 계절을 출력하는 프로그램을 작성해보자.
봄(spring): 3 ~ 5월
여름(summer): 6 ~ 8월
가을(autumn): 9 ~ 11월
겨울(winter): 12 ~ 2월
(단, switch를 사용해야한다.)

# 입출력 예시
Month: 7
7 is summer.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int month;

    printf("Month: ");
    scanf("%d", &month);

    switch(month){
        case 3:
        case 4:
        case 5:
            printf("%d is spring.\n", month);
            break;
        case 6:
        case 7:
        case 8:
            printf("%d is summer.\n", month);
            break;
        case 9:
        case 10:
        case 11:
            printf("%d is autumn.\n", month);
            break;
        case 12:
        case 1:
        case 2:
            printf("%d is winter.\n", month);
            break;
        default:
            printf("Invalid month.\n");
    }

    return 0;
}