#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    /*     int n = 0;
        int x = 0;
        int i;
        int temp;

        scanf("%d", &n);

        for (i = 0; n > 0; i++) {
            temp += n % 10;
        }

        if(temp % 9 == 0){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
     */

    char s[200010];
    scanf("%s", s);
    int len = strlen(s);
    int sum = 0;

    for (int i = 0; i < len; i++){
        sum += s[i] - '0'; //文字コードで数字の'0'を引いて文字コードのオフセットを除去して数字の差だけ得る
        //printf("%d\n", sum);
    }

    if (sum % 9 == 0) {
        puts("Yes");
    } else {
        puts("No");
    }

    return 0;
}
