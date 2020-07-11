//pivot=基準点
//pivotを元にしてpivotより小さい物を右に大きい物を左に分けていく
//divide and conquerを使って同じように分けたものについて
//pivotを設けて操作を続ける

/*
・pivot（軸となる要素）を1つ選び、pivotより小さい部分列と大きい部分列に分ける
・小さい側でpivot（軸となる要素）を1つ選び、pivotより小さい部分列と大きい部分列に分ける
・大きい側でpivot（軸となる要素）を1つ選び、pivotより小さい部分列と大きい部分列に分ける
*/

#include <stdio.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/*
pivotを決め、全データをpivotを境目に振り分け、pivotの添え字を返す
*/
int partition (int array[], int left, int right) {
    int pivot = array[right]; //pivotの設置
    printf("%d\n", pivot);
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[right]);
    return (i + 1);
}

void quickSort(int array[], int l, int r) {
    if (l < r) {
        int pivot = partition(array, l, r);
        quickSort(array, l, pivot - 1);
        quickSort(array, pivot + 1, r);
    }
}

int main (void) {

    int i;
    int array[10] = {3, 6, 1, 7, 2, 0, 4, 5, 9, 8};

    printf("       array: ");
    for (i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    quickSort(array, 0, sizeof(array) / sizeof(array[0]) - 1);

    printf("sorted array: ");
    for (i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}