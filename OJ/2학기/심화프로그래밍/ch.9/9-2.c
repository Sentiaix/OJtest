/*[문제]
문자열 s가 주어지면, 이 문자열을 뒤집어서(reverse) 출력하시오.

[입력]
1행: 문자열 s
(공백 없는 문자열, 최대 200자)

[출력]
문자열 s를 뒤에서부터 거꾸로 출력한다.
apple → elppa

---
[입력 예시]
apple

[출력 예시]
elppa
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(){
    char str[201];
    
    scanf("%s", str);

    int len = strlen(str);
    for(int i = 0; str[i] != '\0'; i++) {
        printf("%c", str[len - 1 - i]);
    }
    printf("\n");

    return 0;
}