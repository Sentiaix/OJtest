/*
#include 

void my_strncat(char *dst, const char *src, int n) {
    while (*dst) dst++;  // dst 끝으로 이동

    while (n-- > 0 && *src) {
        *dst++ = *src++;
    }
    *dst = '\0';  // 문자열 종료
}

int main() {
    char s1[300], s2[300];
    int n;
    scanf("%s", s1);
    scanf("%s", s2);
    scanf("%d", &n);

    my_strncat(s1, s2, n);
    printf("result = %s\n", s1);
    return 0;
}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void my_strncat(char *dst, const char *src, int n) {
    while (*dst) dst++;  // dst 끝으로 이동

    while (n-- > 0 && *src) {
        *dst++ = *src++;
    }
    *dst = '\0';  // 문자열 종료
}

int main() {
    char s1[300], s2[300];
    int n;
    scanf("%s", s1);
    scanf("%s", s2);
    scanf("%d", &n);

    my_strncat(s1, s2, n);
    printf("result = %s\n", s1);
    return 0;
}