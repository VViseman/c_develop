#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp_R;
    FILE *fp_W;
    char buff[256];
    char **ptr = NULL;
    fopen_s(&fp_R, "reverse.txt", "r");
    fopen_s(&fp_W, "reverse.txt", "w");

    if (fp_R == NULL) {
        puts("ファイルのオープンに失敗しました。");
        exit(-1);
    }

    if (fp_W == NULL) {
        puts("ファイルのオープンに失敗しました。");
        exit(-1);
    }

    int i = 0;
    while (fgets(buff, 100, fp_R) != NULL) {
        char *p = (char *)malloc(strlen(buff) + 1);
        strcpy_s(p, strlen(buff) + 1, buff);
        ptr = (char **)realloc(ptr, sizeof(char *) * (i + 1));
        ptr[i] = p;
        ++i;
    }
    --i;
    while (i >= 0) {
        fprintf(fp_W, "%s\n", ptr[i]);
        --i;
    }

    free(ptr);

    fclose(fp_R);
    fclose(fp_W);
    return 0;
}