#include <stdio.h>

#define N 4

int main(void){
    int A[N][N];
    int i, j;

    for (i = 0; i < N; i++) {
        printf("input  : ");
        scanf("%d %d %d %d", &A[i][0], &A[i][1], &A[i][2], &A[i][3]);
    }

    for (i = 0; i < N; i++) {
            printf("output : ");
            printf("%d %d %d %d", A[i][0], A[i][1], A[i][2], A[i][3]);
            printf("\n");
    }

    return 0;
}