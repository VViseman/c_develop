#include <stdio.h>

int main(int argc, char *argv[]){
    int x = 102;
    int y = 4;
    int *p = &x;

    printf("%d\n", x);
    printf("%d\n", x * y);
    printf("%d\n", x / y);
    printf("%d\n", x % y);
    printf("%d\n", *p);
    x++;
    printf("%d\n", *p);

    return 0;
}