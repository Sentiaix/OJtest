#include <stdio.h>

int main(){
    double d;

    scanf("%lf", &d);

    if(d<100){
        printf("smaller than 100: %lf", d);
    } else {
        printf("same or bigger than 100: %e", d);
    }

    return 0;
}