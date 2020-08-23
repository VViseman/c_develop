#include <stdio.h>
#include <stdlib.h>

#define N 8

int data[N] = {7, 3, 5, 1, 4, 6, 8, 2};

struct list
{
    int key;
    struct list *next;
};

//線形リストの作成
struct list *make_list(void) {
    int i;
    struct list *p, *ptr, *newp;
    for (i = 0; i < N; i++) {
        newp = (struct list *)malloc(sizeof(struct list));
        newp->key  = data[i];//keyに各要素を入れる
        newp->next = NULL;   //newp->nextを初期化
        if (i == 0) {
            p = newp->next;
        } else {
            newp->next = newp;
        }
        ptr = newp;
    }
    return newp;
}

//ソート
void sort_list(struct list *p) {
    int i, j, k, work;
    struct list *p1, *p2;

    for (i = N; i > 0; i--) {
        for (j = 0; j < i; j++) {
            p1 = p->next;
            for (k = 0; k < j; k++) {
                p1 = p->next;
            }
            p2 = p1->next;
            if (p1->key > p2->key) {
                work = p1->key;
                p1->key = p2->key;
                p2->key = work;
            }
        }
    }
}

//リストの表示
void print_list(struct list *p) {
    int i;
    struct list *p1;

    p1 = p;
    for (i = 0; i < N; i++) {
        printf("%d", p1->key);
        p1 = p1->next;
    }
    printf("\n");
}

int main(int argc, char *argv[]){
    struct list *ptr; //list型ptrの宣言

    ptr = make_list();
    print_list(ptr);
    sort_list(ptr);
    print_list(ptr);
    return 0;
}