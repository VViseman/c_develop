#include <stdio.h>

#define N 5

char a[N] = {0};

//プロトタイプ宣言
void swap(int, int);
void sort(void);

void sort(void) {
    int i, j;
    for (i = 0; i < N - 1; i++) {
        for (j = i + 1; j < N; j++) {
            if(a[i] > a[j]){
                swap(i, j);
            }
        }
    }
}

void swap(int i, int j){
    int t;
    t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int main(void){
    int i;

    a[0] = 1;
    a[1] = 9;
    a[2] = 8;
    a[3] = 11;
    a[4] = 10;

    sort();

    for (i = 0; i < N; i++) {
        printf("a[%d] = %d\n", i, a[i]);

        if(i == N){
            printf("\n");
        }
    }



    return 0;
}