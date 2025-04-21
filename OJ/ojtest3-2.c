#include <stdio.h>

int main(){
    int interbank_rate; //interbank_rate : 직역하면 환율
    int money_dollar; //돈
    scanf(" %d", &interbank_rate);
    scanf(" %d", &money_dollar);
    printf("KRW = %d", interbank_rate*money_dollar); // 환율*돈 을 %d에 출력
    return 0;
}