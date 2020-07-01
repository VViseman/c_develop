#include<stdio.h>

/* 値を入れ替える関数 */
void swap (int *x, int *y) {
  int temp;    // 値を一時保存する変数

  temp = *x;
  *x = *y;
  *y = temp;
}

/* バブルソート */
void bubble_sort (int array[], int array_size) {
  int i, j;

  for (i = 0; i < array_size - 1; i++){
    for (j = array_size - 1; j >= i + 1; j--){   // 右から左に操作
      if (array[j] < array[j-1]) { swap(&array[j], &array[j-1]); }
    }
  }
}

int main (void) {
  //int array[10] = { 2, 1, 8, 5, 4, 7, 9, 0, 6, 3 };
  int array[10] = {0};
  int i;
  int j = 0;
  int val;

  for (j = 0; j < 10; j++) {
      printf("array[%d] = ",j + 1);
      scanf("%d", &array[j]);
  }

  printf("Before sort: ");    //ソート前を表示
  for (i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  bubble_sort(array, 10);   //配列と要素数を渡す

  printf("After  sort: ");  //ソート前を表示
  for (i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");

  return 0;
}
