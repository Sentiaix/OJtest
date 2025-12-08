/*[문제]
문자열이 주어지면, 그 문자열에서 **모든 숫자 문자('0'~'9')**를 제거한 새로운 문자열을 출력하시오.

[입력]
1행: 문자열 s

[출력]
숫자 문자를 모두 제거한 문자열을 출력한다.
예) "a1b2c3" → "abc"

--
[입력 예시]
a1b2c3d4

[출력 예시]
abcd
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(){
    char str[100];

    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++) {
        if('0' <= str[i] && str[i] <= '9'){
            
        }
        else {
            printf("%c", str[i]);
        }        
    }
    printf("\n");

    return 0;
}