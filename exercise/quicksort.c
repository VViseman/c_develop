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

//pivotを決め、全データをpivotを境目に振り分け、pivotの添え字を返す
int partition(int array[], int left, int right) {  //最初はl = 0, r = 10
    int pivot = array[right]; //基準となる値のpivotの設置 最初は10番目
    printf("%d\n", pivot); //pivotの値の変化の確認
    int i = left - 1; //jで指す要素より一つ前の要素を指す。最初は0 - 1 = -1. -1でも動く

    for (int j = left; j <= right - 1; j++) { //最初はleft = 0, right = 10
        if (array[j] <= pivot) { //基準より数値が小さいとき
            i++;
            swap(&array[i], &array[j]); //分けた中でのソート
        }
    }
    swap(&array[i + 1], &array[right]); //ソートが終わったらiは左側の箸の要素を指すはずなので、それと基準に見立てたrightと入れ替える
    return (i + 1);
}

void quickSort(int array[], int l, int r) { //最初はl = 0, r = 10
    if (l < r) {
        int pivot = partition(array, l, r); //最初はl = 0, r = 10
        quickSort(array, l, pivot - 1); //左側のソート 0,
        quickSort(array, pivot + 1, r); //右側のソート
        //左側のソートをしてから右側のソートをする。
    }
}

int main (void) {

    int i;
    int array[10] = {3, 6, 1, 7, 2, 0, 4, 5, 9, 8};

    printf("before array: ");
    for (i = 0; i < sizeof(array) / sizeof(array[0]); i++) { //要素の表示
        printf("%d ", array[i]);
    }
    printf("\n");

    quickSort(array, 0, sizeof(array) / sizeof(array[0]) - 1);

    printf("sorted array: ");
    for (i = 0; i < sizeof(array) / sizeof(array[0]); i++) { //要素の表示
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}