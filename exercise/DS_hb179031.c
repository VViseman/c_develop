#include <omp.h>
#include <stdio.h>

#define N 2048
#define P 16

double A[N][N];
double B[N][N];
double C[N][N];

int main(){

    int i,j,k;
    double sum;

    omp_set_num_threads(P);

    #pragma omp parallel for private(j)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = 1.0;
            B[i][j] = 2.0;
            C[i][j] = 0.0;
        }
    }

    #pragma omp parallel for private(j,k)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    //#pragma omp parallel for private(j)
    #pragma omp parallel for private(j) reduction(+:sum)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
	  sum += C[i][j];
        }
    }

    printf("sum = %lf\n", sum);

    return 0;
}
