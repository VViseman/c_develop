#include <stdio.h>

#define N 10

/* 値を入れ替える関数 */
void swap (int *x, int *y) {
  int temp;    // 値を一時保存する変数

  temp = *x;
  *x = *y;
  *y = temp;
}

/* pushdouwn操作 */
void pushdown (int array[], int first, int last) {
  int parent = first;   // 親
  int child = 2*parent;   // 左の子
  while (child <= last) {
    if ((child < last) && (array[child] < array[child+1])) {
       child++;   // 右の子の方が大きいとき、右の子を比較対象に設定
    }
    if (array[child] <= array[parent]) { break; }   // ヒープ済み
    swap(&array[child], &array[parent]);
    parent = child;
    child = 2* parent;
  }
}

/* ヒープソート */
void heap_sort (int array[], int array_size) {
  int i;

  for (i = array_size/2; i >= 1; i--) {
    pushdown(array, i, array_size);   // 全体をヒープ化
  }
  for (i = array_size; i >= 2; i--) {
    swap(&array[1], &array[i]);   // 最大のものを最後に
    pushdown(array, 1, i-1);   // ヒープ再構築
  }
}

int main (void) {
  int array[N] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int i;

  printf("Before sort: ");
  for (i = 0; i < N; i++) {
      printf("%d ", array[i]);
  }
  printf("\n");

  heap_sort(array, N);

  printf("After  sort: ");
  for (i = 0; i < N; i++) {
      printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}
