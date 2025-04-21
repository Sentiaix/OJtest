#include <stdio.h>

int main(){
    int month, year;
    long int money;

    scanf("%ld %d", &money, &month);
    year = month/12;
    money = money*month;
    month = month%12;
    printf("%d년 %d월 저축 총액 = %ld\n", year, month, money);

    return 0;
}