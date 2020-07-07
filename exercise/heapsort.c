#include <stdio.h>

//下に行くほど値が大きくなるor小さくなる

/*
1.要素数Nのヒープを、「子よりも親が大きい」として構築：根が最大値となる
2.根を配列の最後尾と入れ替える。
3.N - 1個の要素のヒープを構築しなおす：根が2番目に大きい値となる
*/

/* 値を入れ替える関数 */
void swap(int *x, int *y) {
    int temp;  // 値を一時保存する変数

    temp = *x;
    *x = *y;
    *y = temp;
}

/*下に下げながらヒープを構築する位置までおろしていくpushdouwn操作*/
void pushdown(int array[], int first, int last) {
    int parent = first;      //親
    int child = 2 * parent;  //左の子
    while (child <= last) {
        if ((child < last) && (array[child] < array[child + 1])) {  //array[child] : 左側, array[child + 1] : 右側
            child++;  // 右の子の方が大きいとき、右の子を比較対象に設定 if文の(child + 1)を(child++)で表現している
        }
        if (array[child] <= array[parent]) {//ヒープソートの条件と一致 親が子より大きければヒープ済み
            break; // ヒープ済み
        }
        swap(&array[child], &array[parent]);//親と子の入れ替え
        parent = child;      //深くしていく
        child  = 2 * parent; //深くしていく
    }
}

/* ヒープソート */
void heap_sort(int array[], int array_size) {
    int i;

    for (i = array_size / 2; i >= 1; i--) {//最下層の要素になるまで
        pushdown(array, i, array_size);  // 全体をヒープ化
    }
    for (i = array_size; i >= 2; i--) {
        swap(&array[1], &array[i]);  // 最大のものを最後に 根(配列の先頭、N[0])に必ず最大値が来るため
        pushdown(array, 1, i - 1);   // ヒープ再構築
    }
}

int main(void) {
    int array[11] = {0, 2, 1, 8, 5, 4, 7, 9, 10, 6, 3};
    int i;

    printf("Before sort: ");
    for (i = 1; i < 11; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    heap_sort(array, 10);

    printf("After  sort: ");
    for (i = 1; i < 11; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
