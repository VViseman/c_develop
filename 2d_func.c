#include <stdio.h>
#include <math.h>

int main(void){

  double a, b, c = 1.0;
  double D, x1, x2;

  scanf("%lf %lf",&a, &b);

  D = b * b - 4.0 * a * c;

  if((a == 0) && (b == 0)) {
    printf("解なし\n");
  } else if (a == 0){
    x1 = -c /b;
    printf("%f\n",x1);
  } else if (D >= 0) {
    x1 = (-b + sqrt(D) ) / (2.0 * a);
    x2 = (-b - sqrt(D) ) / (2.0 * a);
    printf("%f, %f\n",x1,x2);
  } else {
    printf("%f + j %f, %f + j %f\n", -b / (2.0 * a), sqrt(-D) / (2.0 * a), -b / (2.0 * a), -sqrt(-D) / (2.0 * a));

  }

  return 0;  
}
