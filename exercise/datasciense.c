//#include <omp.h>
#include <stdio.h>

#define N 1024
#define P 4

double A[N][N];
double B[N][N];
double C[N][N];

int main(int argc, char *argv[]){

    int i,j,k;


    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = 1.0;
            B[i][j] = 2.0;
            C[i][j] = 0.0;
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("A[%d][%d] = %lf \n", i, j, A[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("B[%d][%d] = %lf \n", i, j, B[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("C[%d][%d] = %lf \n", i, j, C[i][j]);
        }
        printf("\n");
    }

    return 0;
}