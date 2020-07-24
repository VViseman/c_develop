#include <stdio.h>
#include <math.h>

int pow_kai(int a, int n);

int main(void) {
    int q = 11;  //10以上の素数。変えてはいけない
    int a = 3;   //qの原始根。変えてはいけない
    int d = 9;   //ランダムな秘密鍵。変えていい
    int g = 0;   //公開鍵の要素。変えてはいけない
    int r = 5;   //C_1, C_2の計算に使う乱数。変えていい
    int C_1 = 0; //メッセージのC_1。変えてはいけない
    int C_2 = 0; //メッセージのC_2。変えてはいけない
    int P = 7;   //平文。変えてはいけない
    int ans = 0; //得られる平文。変えてはいけない

    g = pow_kai(a, d);
    C_1 = pow_kai(a, r);

    printf("g   = %d\n", g);
    printf("g   = %d^%d (mod %d) = %d\n",a, d, q, (g % q));
    printf("C_1 = %d\n", C_1);
    printf("C_1 = %d^%d (mod %d) = %d\n", a, r, q, C_1 % q);
    C_2 = (7 * pow_kai(g, r));
    printf("C_2 = %d\n", C_2);
    printf("C_2 = %d * %d^%d (mod %d) = %d\n", P, (g % q), r, q, C_2 % q);

    printf("P   = %d\n", (C_2 / pow_kai(C_1, d)));

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