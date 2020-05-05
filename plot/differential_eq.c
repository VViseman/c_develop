#include <stdio.h>
#include <math.h>

int main(void) {
    double f_1, f_2, f1, f2, f3, f4, dx, x;

    f1 = 1;
    f3 = 2;

    dx = 0.01;

    for (int i=0; i<=100; ++i) {
        x = i*dx;
        f2 = f1 + dx*x*f1;  //式1
        f4 = f3 - 3*x*dx*pow(f3, 2); //式2

        f_1 = exp(x*x/2);
        f_2 = 2./(3*pow(x, 2)+1);

//        printf("x = %f 数値解 -> f1 = %f 正確な値 -> f = %f \n", x, f1, f);
        printf("x = %f 数値解 -> f1 = %f 正確な値 -> f = %f || x = %f 数値解 -> f3 = %f 正確な値 -> f = %f\n",x, f1, f_1, x, f3, f_2);

        f1 = f2;
        f3 = f4;
    }
}
