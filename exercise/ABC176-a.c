#include <stdio.h>

int main(int argc, char *argv[]) {
    int n = 0;
    int x = 0;
    int t = 0;
    int times = 0;
    int ans = 0;

    scanf("%d %d %d", &n, &x, &t);
    times = (n + x - 1) / x;
    ans = t * times;
    printf("%d\n", ans);

    return 0;
}