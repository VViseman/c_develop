#include <stdio.h>

#define N 3

int main(void) {
    int i, j;
    double A[N][N] = {{3.0, 2.0, 5.0},
                      {1.0, 4.0, 3.0},
                      {0.0, 1.0, 6.0}};
    double x[N]= {-3.0, 2.0, -1.0};
    double y[N];  /*計算結果を代入するための行列を用意*/

    printf("A = \n"); /*行列Aの表示*/

    for (i = 0; i < N; i++) { /* i行*/
        for (j = 0; j < N; j++) { /* j列*/
        printf("%6.1f\t", A[i][j]); /*各列はタブ区切りで表示*/
        }
        printf("\n"); /*次の行を表示するための改行*/
    }

    printf("\n"); /*区切りのための改行*/
    printf("x=\n");

    for (i = 0; i < N; j++){
     printf("%6.1f\n", x[i]); /*各列はタブ区切りで表示*/
    }
    printf("\n");/* y = Axの計算*/
    for (i = 0; i < N; i++) {
        y[i] = 0; /*初期化*/
        for (j = 0; j < N; j++) {
            y[i] += A[i][j] * x[j];
        }
    }

    printf("\n");
    printf("y = \n"); /*ベクトルy(=Ax)の表示*/
    for (i = 0; i < N; i++){
     printf("%6.1f\n", y[i]); /*各列はタブ区切りで表示*/
    }
    printf("\n"); /*区切りのための改行*/
    return 0;
}

