/* vim: set fenc=utf-8: */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 25

void heap_sort(int* numbers, int array_size);
void max_heap(int* numbers, int root, int bottom);
void max_heap_recursive(int* numbers, int root, int bottom);
void print_data(int* numbers, int array_size);

int main()
{

    // 乱数の配列を生成
    int numbers[MAX_SIZE];
    int i;

    srand((unsigned)time(NULL));

    for(i = 0; i < MAX_SIZE; ++i) {
        numbers[i] = rand() % 1000;
    }

    // ソート前のデータを表示
    print_data(numbers, MAX_SIZE);

    // ソートを実行
    heap_sort(numbers, MAX_SIZE);

    // ソート後のデータを表示
    printf("\n\n");
    print_data(numbers, MAX_SIZE);

    return EXIT_SUCCESS;
}

void heap_sort(int* numbers, int array_size)
{
    int i, temp;

    // ヒープ構築
    // 二分木なので親ノードのインデックスは
    // (n - 1) / 2 となる
    for (i = (array_size - 1) / 2; i >= 0; i--)
    {
        max_heap(numbers, i, array_size - 1);
    }

    // ヒープソート実行
    // 値を昇順に並べる。
    //
    // 先頭要素(最大値)を配列の最後に移動させて
    // 最後の要素を無視してヒープを構築すると
    // 配列内で最も小さな値から順に並ぶ
    for (i = array_size - 1; i > 0; i--)
    {
        temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        max_heap(numbers, 0, i - 1);
    }

}

/*
 * Max-heap を構築する。
 *
 * 親ノードは子ノードより大きいか等しくなる。
 *
 * @param numbers ソートしたい配列
 * @param root 親ノードとなる要素のインデックス
 * @param bottom 最後の要素のインデックス
 */
void max_heap(int* numbers, int root, int bottom)
{
    // 子ノードのインデックス
    int child = (2 * root) + 1;

    // 親ノードの値を保持しておく
    int temp = numbers[root];

    while (child <= bottom) {
        if (child < bottom && numbers[child + 1] > numbers[child]) {
            // 二分木のふたつの子ノードから値が大きいほうの子ノードを選択する。
            child = child + 1;
        }
        if (temp > numbers[child]) {
            // 親ノードの値が子ノードの値より大きい場合は何もしない。
            break;
        } else if (temp <= numbers[child]) {
            // 親が子より小さいか等しいと
            // 親と子を入れ替える
            numbers[(child - 1) / 2] = numbers[child];
            // 子ノードのインデックスを進める。
            child = (2 * child) + 1;
        }
    }
    // 親ノードとなる要素に値を入れる
    numbers[(child - 1) / 2] = temp;
    return;
}

/*
 * Max-heap を構築する。再帰を利用。
 *
 */
void max_heap_recursive(int* numbers, int root, int bottom)
{
    // 子ノードのインデックス
    // 配列の先頭要素のインデックスが 0 なので
    // 子ノードは 2n + 1 と 2n + 2 で計算する
    int l_idx = (root * 2) + 1;
    int r_idx = (root * 2) + 2; 

    // 最大値を持つ要素のインデックス
    int maxChild;

    if (l_idx <= bottom && numbers[l_idx] > numbers[root]) {
        maxChild = l_idx;
    } else {
        maxChild = root;
    }

    if (r_idx <= bottom && numbers[r_idx] > numbers[maxChild]) {
        maxChild = r_idx;
    }

    if (maxChild != root) {
        int temp = numbers[root];
        numbers[root] = numbers[maxChild];
        numbers[maxChild] = temp;
        // 配列の先頭要素には最大値を持つ要素のインデックスを指定する
        max_heap_recursive(numbers, maxChild, bottom);
    }

}

void print_data(int* numbers, int array_size)
{
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d\n", numbers[i]);
    }
}
