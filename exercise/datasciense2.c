#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

double A[N][N]、B[N][N];

int main(int argc, char *argv[]){
    int i, j, k;
    double sum = 0.0;

    omp_set_num_threads(P);

#pragma omp parallel for private(j)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = 0;
            A[i][j] = 0;
            A[i][j] = 0;
        }
    }

    return 0;
}