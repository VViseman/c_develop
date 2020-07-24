#include <stdio.h>
#include <math.h>

int pow_kai(int a, int n);

int main(void) {
    int a = 3;
    int g;
    int C_1;
    int C_2;
    int P;

    //    scanf("%d", &num);

    g = pow_kai(a, 11);
    C_1 = pow_kai(a, 13);
    C_2 = pow_kai(a, 13);

    printf("g   = %d\n", g);
    printf("g   (mod q) = %d\n", g % 7);
    printf("C_1 = %d\n", C_1);
    printf("C_1 (mod q) = %d\n", C_1 % 7);

    printf("P = %d\n", (6 / 5) % 7);

    return 0;
}

int pow_kai(int a, int n) {  // aのn乗を計算します。
    int x = 1;
    while (n > 0) {   //全てのbitが捨てられるまで。
        if (n & 1) {  // 1番右のbitが1のとき。
            x = x * a;
        }
        a = a * a;
        n >>= 1;  // bit全体を右に1つシフトして一番右を捨てる。
    }
    return x;
}