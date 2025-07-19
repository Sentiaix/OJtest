#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// function declaration
void sort_array(int *v, int n, int m);

int main(){
    int n,m; // n: arr size, m: false(0) -> ASC order , true(1) -> DESC order
    int arr[10];

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    sort_array(arr, n, m);

    return 0;
}

// define function
void sort_array(int *v, int n, int m){

    // sorting
    if(m){ // decraseing order case
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(v[j] < v[j + 1]){
                    int temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
                }
            }
        }
    } else{ // ascending order case
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n - i - 1; j++){
                if(v[j] > v[j + 1]){
                    int temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
                }
            }
        }
    }

    // print result
    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}