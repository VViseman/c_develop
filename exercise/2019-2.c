#include <stdio.h>

int main(int argc, char *argv[]){
    char s[] = "ritsumei";
    char *p = s;

    printf("%s\n", s);  //a
    printf("%s\n", p);  //b
    printf("%c\n", *p); //c

    p += 2;

    printf("%s\n", s);  //d
    printf("%s\n", p);  //e
    printf("%c\n", *p); //f

//    printf("%d\n", s[3] - 1); //f

    s[3] = s[3] - 1;
    printf("%s\n", s);  //g

    while(*p != s[0]){
        p++;
    }

    printf("%s\n", p);  //h

    return 0;
}