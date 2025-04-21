#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int inputs[4];
    int prchk[999] = {0}; //정상 프린트 됐는지 확인용 printedcheck's shorten
    int prtxt = 0; //중복에 따른 결과를 위한 text를 출력하기 위함. print text's shorten

    printf("enter 4 values: ");
    scanf("%d %d %d %d", &inputs[0], &inputs[1], &inputs[2], &inputs[3]);

    for(int i = 0 ; i < 4; i++){ //i를 변수로 4번 반복
        for(int j = i + 1; j < 4; j++){ //j는 i+1이고 총 j-(i+1)회 반복.
                                        // 즉 i가 0이면 j는 1 2 3, 1이면 2 3, 2면 3까지 검증. 0이 1번째임!
                                        // 입력값으로 생각하면 a:b,c,d / b:c,d / c:d가 됨
            if(inputs[i] == inputs[j] && prchk[inputs[i]] == 0){ //i와 그 다음칸값을 비교하고 i번째 숫자가 프린트 됐는지 prchk로 확인함
                if(prtxt == 0){ //중복을 찾아냈으면 repeated value를, 못찾으면 all unique를 프린트하는데 두 text를 중복 출력하지 않기 위함.
                    printf("repeated value");
                }
                printf(" %d", inputs[i]);
                prchk[inputs[i]] = 1; //prchk의 행렬에서 inputs[i]번째 행렬의 값을 1로 설정함. (즉, prchk 행렬에서 중복된 숫자 번째 칸의 값을 1로 바꿈)
                prtxt = 1; //중복이 감지되면 prtxt를 1로 만들어서 prtxt를 참인 값으로 만듦. 그래서 두번째 if문이 한 번만 실행하게 함.
            }
        }
    }
    if(!prtxt){ //boole을 이용해 prtxt가 참이 아니면 실행.
        printf("all unique");
    }

    printf("\n");

    return 0;
}