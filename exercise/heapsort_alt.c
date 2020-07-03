#include <stdio.h>

void h_down(int* ar, int size, int root);
void h_sort(int* ar, int size);
void swap(int* a, int* b);

void swap(int* a, int* b) {
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

void h_sort(int* ar, int size) {
    //ヒープ作成
    for (int i = (size / 2); i >= 0; i--) {
        h_down(ar, size, i);
    }
    //ヒープソート
    while (1) {
        swap(&ar[0], &ar[size--]);
        if (!size) break;
        h_down(ar, size, 0);
    }
    return;
}

void h_down(int* ar, int size, int root) {
    int max;
    while (1) {
        //値の大きい方の枝を調べる
        max = root * 2 + 1;
        if (root * 2 + 2 <= size) {  //２の枝が存在する
            if (ar[root * 2 + 1] < ar[root * 2 + 2]) {  //１の枝と比較して
                max = root * 2 + 2;
            }
        } else if (!(root * 2 + 1 <= size))
            break;  //１の枝が存在しないため終了

        //値の大きいほうの枝と根を比べて、値を交換する
        if (ar[root] < ar[max]) {
            swap(&ar[root], &ar[max]);
            root = max;  //交換できたため、枝←根にする
        } else
            break;  //根の方が大きいため終了
    }
    return;
}

int main() {
    int ar[] = {3, 0, 6, 8, 4, 9, 1, 5, 7, 2};
    int ar_size = sizeof(ar) / sizeof(int) - 1;

    h_sort(ar, ar_size);

    for (int i = 0; i <= ar_size; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");
    return 0;
}