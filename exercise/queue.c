#include <stdio.h>

#define N 1000

struct queue {
    char data[N];
    int head;
    int tail;
};

void initialize(struct queue *q) {  //キューは配列のなのでポインタを渡している
    int i;

    q->head = 0;
    q->tail = 0;
    for (i = 0; i < N; ++i) {
        q->data[i] = ' ';
    }
}

void enqueue(struct queue *q, int item) {  //キューは配列のなのでポインタを渡している
                                           //入力で受け取るitemを格納する
    if (q->tail >= N) {  //キューが満杯な時
        printf("This queue is full! \n");
    } else {
        q->data[q->tail] = item;  //キューのtailの位置にitemを格納する
        q->tail++;                // itemをインクリメントする
    }
}

int dequeue(struct queue *q) {
    int tmp;

    if (q->head == q->tail) {
        return -1;
    } else {
        tmp = q->data[q->head];  // FIFOなのでhead(最先頭)にある要素を取り出す
        q->head++;  //取り出し終わったので、最先頭を後ろにずらす
        return tmp;  //取り出した要素を返り値にする
    }
}

int main() {
    char symbol;
    int i, item;
    struct queue Q;

    initialize(&Q);  //配列の初期化

    item = dequeue(&Q);
    printf("dequeue %d \n", item);
    scanf("%d", &item);
    enqueue(&Q, item);
    printf("enqueue %d \n", item);

    printf("\n--------------- Now queue data:\n");
    for (i = Q.head; i < Q.tail; i++) {
        printf("  data[%d]=%d\n", i, Q.data[i]);
    }
    printf("---------------\n\n");
}