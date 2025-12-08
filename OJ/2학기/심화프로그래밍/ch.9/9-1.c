/*[문제]
문자열이 주어지면, 그 문자열에서 특정 문자 c가 등장하는 횟수를 세어 출력하시오.

[입력]
1행: 문자열 s
2행: 문자 c (한 글자)

[출력]
문자 c가 문자열 s에서 몇 번 등장하는지 정수로 출력한다.

---
[입력예시]
programming
g

[출력예시]
2
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int count = 0;
    char str[100];
    char ch;

    scanf("%s", str);
    getchar();
    scanf("%c", &ch);

    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == ch){
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}