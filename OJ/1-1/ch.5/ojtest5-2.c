#include <stdio.h>

int main(){
    int iv;
    float fv;
    double dv;
    char cv, rt;

    printf("enter data type i, f, d, c: ");
    scanf("%c", &rt);

    if(rt=='i'){
        printf("enter value: ");
        scanf("%d", &iv);
        printf("value is %d", iv);
    } else if(rt=='f') {
        printf("enter value: ");
        scanf("%f", &fv);
        printf("value is %f", fv);
    } else if(rt=='d'){
        printf("enter value: ");
        scanf("%lf", &dv);
        printf("value is %.20lf", dv);
    } else if(rt=='c'){
        printf("enter value: ");
        scanf(" %c", &cv); //char형 자료를 받을때 입력버퍼가 넘어옴을 방지하기 위해 앞 한칸은 공백을 둔다
        printf("value is %c", cv);
    } else {
        printf("please follow instructions");
    }
    
}