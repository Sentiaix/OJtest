    #include <stdio.h>
    int main(){
        //sizeof 연산자는 변수나 상수가 차지하는 메모리 크기를 구하는 명령어 입니다.
        char cho;
        int sun;
        double chosun; //위 변수들은 마지막 변수명에 sizeof를 사용하기 위한 변수이다.
        //long long 자료형은 windows에서 4byte, Linux에서 8byte이다.
        printf("char형의 바이트 크기: %d\n", sizeof(char));
        printf("short형의 바이트 크기: %d\n", sizeof(short));
        printf("int형의 바이트 크기: %d\n", sizeof(int));
        printf("long형의 바이트 크기: %d\n", sizeof(long));
        printf("long long형의 바이트 크기: %d\n", sizeof(long long));
        printf("float형의 바이트 크기: %d\n", sizeof(float));
        printf("double형의 바이트 크기: %d\n", sizeof(double));
        printf("long double형의 바이트 크기: %d\n", sizeof(long double));
        printf("cho 변수의 바이트 크기: %d\n", sizeof(cho));
        printf("sun 변수의 바이트 크기: %d\n", sizeof(sun));
        printf("chosun 변수의 바이트 크기: %d\n", sizeof(chosun));
        return 0;
    }