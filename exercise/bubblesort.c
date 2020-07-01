#include<stdio.h>

/* 値を入れ替える関数 */
void swap (int *x, int *y) {
  int temp;    // 値を一時保存する変数

  temp = *x;
  *x = *y;
  *y = temp;
}

//変更した配列の状態をmainでも適用されるように
//ポインタを使って入れ替えをする

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

  //配列の要素の入力
  for (j = 0; j < 10; j++) {
      printf("array[%d] = ",j + 1);
      scanf("%d", &array[j]);
  }

  //ソート前を表示
  printf("Before sort: ");
  for (i = 0; i < 10; i++) {
    printf("%d ", array[i]);
    if (i == 9) {
        printf("\n");
    }
  }

  //配列と要素数をbubble_sort()へ渡す
  bubble_sort(array, 10);

  //ソート後を表示
  printf("After  sort: ");
  for (i = 0; i < 10; i++) {
    printf("%d ", array[i]);
    if(i == 9){
        printf("\n");
    }
  }

  return 0;
}
