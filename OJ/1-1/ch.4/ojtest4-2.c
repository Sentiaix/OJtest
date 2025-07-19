#include <stdio.h>

int main(){
    int price;
    int pay;
    int change;

    printf("price : ");
    scanf("%d", &price);
    printf("pay : ");
    scanf("%d", &pay);

    change = pay - price;

    printf("change : %d\n", change); 
    printf("5000won : %d\n", change/5000); change %= 5000; //change %= 5000; 은 5000으로 나누지 못한 값을 새로이 대입하는것.
    printf("1000won : %d\n", change/1000); change %= 1000;
    printf("500won : %d\n", change/500); change %= 500;
    printf("100won : %d\n", change/100); change %= 100;
    printf("50won : %d\n", change/50); change %= 50;
    printf("10won : %d\n", change/10); change %= 10;
    printf("1won : %d\n", change/1); 

    return 0;
}