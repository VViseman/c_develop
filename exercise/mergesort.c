#include <stdio.h>

#define MAX 500000
#define INFTY 20000000

int n;
int L[MAX / 2], R[MAX / 2];//A[]とは別の左用、右用の配列

void merge(int A[], int left, int mid, int right) {
     int n1 = mid - left;   //左側の配列の要素数
     int n2 = right - mid;  //右側の配列の要素数

     for (int i = 0; i < n1; i++) { //左側の配列
         L[i] = A[left + i]; //左用の配列にA[]の要素を入れる
     }
     L[n1] = INFTY;//小さく分けた配列の最後の要素は一番大きくしておく

     for (int i = 0; i < n2; i++) {  //右用の配列にA[]の要素を入れる
         R[i] = A[mid + i];
     }
     R[n2] = INFTY;  //小さく分けた配列の最後の要素は一番大きくしておく

     int i = 0, j = 0;
     for (int k = left; k < right; k++) { //分けた配列でソート
        if(L[i] <= R[j]){
            A[k] = L[i++]; //小さい要素が左に行く
        } else {
            A[k] = R[j++]; //大きい要素が左に行く
        }
     }
}

void mergesort(int A[], int left, int right) { //Divide & Conquer
    if (left + 1 < right) {
        int mid = (left + right) / 2; //左側と右側を分ける真ん中のmid
        // Divide
        mergesort(A, left, mid);  //左側をDivide
        mergesort(A, mid, right); //右側をDivide
        // Conquer
        merge(A, left, mid, right);//ソートが終わったらmerge
    }
}

int main(int argc, char *argv[]) {
    int A[MAX];
    int cnt = 0;
    int i, n = 0;

    scanf("%d", &n);//要素数の入力
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    mergesort(A, 0, n); //マージソート

    for (i = 0; i < n; i++) {//出力
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}