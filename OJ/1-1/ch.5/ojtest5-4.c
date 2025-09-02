    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>

    int main(){
        double arr[5];
        double big1st, big2nd; //big1st : 가장 큰 숫자 / big2nd : 두번째로 큰 숫자

        printf("enter 5 values: ");
        scanf("%lf %lf %lf %lf %lf", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);

        printf("two big numbers");

        if(arr[0] > arr[1]){ //초기값 설정, 운 좋으면 여기서 최댓값 2개 나올 수 있음
            big1st = arr[0];
            big2nd = arr[1];
        } else {
            big1st = arr[1];
            big2nd = arr[0];
        }

        for(int i = 2; i < 5; i++){ //2,3,4 번째 행렬에서 큰 숫자만 뽑아내기
            if(arr[i] > big2nd){
                if(arr[i] > big1st){
                    big2nd = big1st;
                    big1st = arr[i];
                } else
                big2nd = arr[i];
            }
        }

        for(int i = 0; i < 5; i++){
            //arr행렬에서 big1st값 또는(or) big2nd값일때 총 2회 다 실행하기 위한 if문
            if (arr[i] == big1st || arr[i] == big2nd){
                printf(" %.6lf", arr[i]); // .6lf는 lf자료형으로 소수점 6번째까지만 표기
            }
        }

        printf("\n");

        return 0;
    }