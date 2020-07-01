#include <stdio.h>
#include <math.h>

int main(void){

    double c = 100;
    double in_t = 10;
    double x1 = 0;
    double x2 = 0;

    x1 = log(exp(c)*in_t);
    x2 = log(in_t) + c;

    printf("%lf\n",x1);
    printf("%lf\n",x2);

    return 0;
}