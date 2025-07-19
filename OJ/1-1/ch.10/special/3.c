#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char text[50], key[10];
    unsigned char cipherText[50], plainText[50];

    scanf("%[^\n]", text);  // 공백 포함해서 입력
    getchar();              // 개행 제거
    scanf("%s", key);       // 키 입력

    int keyLen = strlen(key); // key의 문자열 길이
    int textLen = strlen(text);

    // 암호화
    for (int i = 0; i < textLen; i++) {
        cipherText[i] = text[i] ^ key[i % keyLen];
    }

    // 암호문 출력 (16진수)
    printf("암호문(16진수) = ");
    for (int i = 0; i < textLen; i++) {
        printf("%02x", cipherText[i]);  // 2자리 16진수
    }
    printf("\n");

    // 복호화
    for (int i = 0; i < textLen; i++) {
        plainText[i] = cipherText[i] ^ key[i % keyLen];
    }
    plainText[textLen] = '\0';

    printf("복호문 = %s\n", plainText);

    return 0;
}
