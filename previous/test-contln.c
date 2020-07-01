/*
test-contln.c --- 左側に等高線、右側にグラフの bird view を描く
cglsc test-contln.c
*/

#include <stdio.h>

/* 動的に確保できる行列 matrix */
#include <stdlib.h>
typedef double **matrix;
matrix new_matrix(int, int);
void delete_matrix(matrix);

#include <math.h>
#ifndef G_DOUBLE
#define G_DOUBLE
#endif
#include "glsc.h"

#define W0 80.0
#define H0 80.0
#define W1 80.0
#define H1 80.0
#define W_MARGIN 10.0
#define H_MARGIN 10.0

double pi;

void compute(double (*)(double, double), matrix,
	     double, double, double, double,
	     int, int);
double f(double, double);

double max(double x, double y) { return (x > y) ? x : y; }

int main()
{
    int m, n, k;
    double xmin, xmax, ymin, ymax;
    matrix u;

    pi = 4 * atan(1.0);

    /* 分割数 */
    m = 100; n = 100;
    /* 定義域は [-π,π]×[-π,π] */
    xmin = - pi; xmax = pi; ymin = - pi; ymax = pi;

    /* 格子点における数値を納める変数 */
    if ((u = new_matrix(m+1,n+1)) == NULL) {
        fprintf(stderr, " 行列のためのメモリーが確保できませんでした。\n");
        return 1;
    }
    /* GLSC */
    g_init("Meta", W0 + W1 + 3 * W_MARGIN, max(H0, H1) + 2 * H_MARGIN);
    g_device(G_BOTH);
    /* ウィンドウ0 */
    g_def_scale(0,
                xmin, xmax, ymin, ymax,
                W_MARGIN, H_MARGIN, W0, H0);
    g_def_scale(1,
                xmin, xmax, ymin, ymax,
                W_MARGIN + W0 + W_MARGIN, H_MARGIN, W1, H1);
    /* */
    g_def_line(0, G_BLACK, 0, G_LINE_SOLID);
    g_def_text(0, G_BLACK, 2);
    /* 定義したものを呼び出す */
    g_sel_scale(0);
    g_sel_line(0);
    g_sel_text(0);
    /* title */
    g_text(W_MARGIN + W0 * 0.6, H_MARGIN / 2, "contour and bird view");
    /* 格子点上での関数値を計算する */
    compute(f, u, xmin, xmax, ymin, ymax, m, n);
    /* 等高線 */
    for (k = -10; k <= 10; k++)
        g_contln(xmin, xmax, ymin, ymax, &u[0][0], m+1, n+1, 0.1 * k);
    /* 鳥瞰図 */
    g_hidden(1.0, 1.0, 0.4,
	     -1.0, 1.0,
	     /* 視点 (距離, 方角を表わす (θ,φ) ) */
	     5.0, 30.0, 30.0,
	     W_MARGIN + W0 + W_MARGIN, H_MARGIN,
	     W1, H1,
	     &u[0][0], m + 1, n + 1, 1,
	     G_SIDE_NONE, 2, 1);

    printf("終了したらウィンドウをクリックして終了してください。\n");
    g_sleep(-1.0);
    g_term();

    return 0;
}

/*
 * [xmin,xmax]×[ymin,ymax] を x 軸方向に m 等分、y 軸方向に n 等分して
 * 各格子点上の f の値を u に格納する。
 */
void compute(double (*f)(), matrix u,
        double xmin, double xmax, double ymin, double ymax,
        int m, int n)
{
    int i, j;
    double dx, dy, x, y;

    dx = (xmax - xmin) / m;
    dy = (ymax - ymin) / n;
    for (i = 0; i <= m; i++) {
        x = xmin + i * dx;
        for (j = 0; j <= n; j++) {
            y = ymin + j * dy;
            u[i][j] = f(x, y);
        }
    }
}

double f(double x, double y)
{
    return sin(3 * x) * sin(y);
}

matrix new_matrix(int m, int n)
{
  int i;
  double *dp;
  matrix p;
  if ((p = malloc(sizeof(double *) * m)) == NULL) {
    fprintf(stderr, "new_matrix(): cannot allocate memory\n");
    return NULL;
  }
  if ((dp = malloc(sizeof(double *) * m * n)) == NULL) {
    fprintf(stderr, "new_matrix(): cannot allocate memory\n");
    free(p);
    return NULL;
  }
  for (i = 0; i < m; i++)
    p[i] = dp + i * n;
  return p;
}

void delete_matrix(matrix a)
{
  free(a[0]);
  free(a);
}