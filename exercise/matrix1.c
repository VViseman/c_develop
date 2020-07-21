#include <stdio.h>

#define N 4

int main(void){
    int A[N][N];
    int B[N][N];
    int C[N][N];
    int i, j, k;
    int term;

    printf("A\n");
    for (i = 0; i < N; i++) {
        printf("input  : ");
        scanf("%d %d %d %d", &A[i][0], &A[i][1], &A[i][2], &A[i][3]);
    }

    printf("B\n");
    for (i = 0; i < N; i++) {
        printf("input  : ");
        scanf("%d %d %d %d", &B[i][0], &B[i][1], &B[i][2], &B[i][3]);
    }

    /* 行列の積（掛け算） */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            C[i][j] = A[i][j] * B[i][j];

            // 行列の項を計算
            for (i = 0; i < N; i++) {
                for (j = 0; j < N; j++) {
                    term = 0;
                    for (k = 0; k < N; k++) term = term + A[i][k] * B[k][j];
                    C[i][j] = term;
                }
            }
        }
    }

    printf("A\n");
    for (i = 0; i < N; i++) {
            printf("output : ");
            printf("%d %d %d %d", A[i][0], A[i][1], A[i][2], A[i][3]);
            printf("\n");
    }

    printf("B\n");
    for (i = 0; i < N; i++) {
        printf("output : ");
        printf("%d %d %d %d", B[i][0], B[i][1], B[i][2], B[i][3]);
        printf("\n");
    }

    printf("C\n");
    for (i = 0; i < N; i++) {
        printf("output : ");
        printf("%d %d %d %d", C[i][0], C[i][1], C[i][2], C[i][3]);
        printf("\n");
    }

    return 0;
}