#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// 나눗셈 반복했을때 어디서 멈추는지 테스트

int main(){
    unsigned int arr[3];
    long long int div = 10000;
    int idx = 0;
    char str[100];

    scanf("%u %u %u", arr, arr+1, arr+2);

    for(int i = 0; i < 3; i++){
        while(1){
            printf("%s\n", str);
            if(arr[i] / div != 0){ // 나누기에 성공하면 그 숫자 저장
                str[idx++] = (arr[i] / div) + '0';
                str[idx] = '\0'; // 저장하고 다음엔 EOF 저장
                
                div /= 10;
            } else{
                div /= 10;
            }
            if(arr[i] / div == 0){ // ? arr[i] % div == 0 && div == 1; ?
                break;
            }
        }
    }
    

    return 0;
}