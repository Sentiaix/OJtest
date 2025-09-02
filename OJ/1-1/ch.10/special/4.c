#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char input[101];
    char encoded[301] = {0};
    char decoded[101] = {0};

    scanf("%[^\n]", input);  // 공백 포함 입력
    int len = strlen(input);

    // 압축 (Run-Length Encoding)
    int count = 1;
    int idx = 0;
    for (int i = 1; i <= len; i++){
        if (input[i] == input[i - 1]){
            count++;
        } else {
            // 개수 2자리로 저장
            encoded[idx++] = (count / 10) + '0';
            encoded[idx++] = (count % 10) + '0';
            encoded[idx++] = input[i - 1];
            count = 1;
        }
    }
    encoded[idx] = '\0';

    printf("%s\n", encoded);

    // 복원 (Decoding)
    // int j = 0;
    // for (int i = 0; encoded[i] != '\0'; i += 3){
    //     int repeat = (encoded[i] - '0') * 10 + (encoded[i + 1] - '0');
    //     char ch = encoded[i + 2];
    //     for (int k = 0; k < repeat; k++){
    //         decoded[j++] = ch;
    //     }
    // }
    // decoded[j] = '\0';

    // printf("%s\n", decoded);

    return 0;
}
