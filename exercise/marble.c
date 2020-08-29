#include <stdio.h>

#define N 3

int main() {
    int i;
    int count = 0;
    char s[N];

    scanf("%s", s);

    printf("%s\n", s);

    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);

    for (i = 0; i < N - 1; i++) {
        if (s[i] == "1") {
            count += 1;
        }
    }

    printf("%d\n", count);

    return 0;
}