#include <stdio.h>
#include <stdlib.h>

struct lnode {
  int data; /*リストに格納するデータ*/
  struct lnode *ptr; /*リストの次のデータへのポインタ*/
} ; /*リストの一つのノード*/

struct lnode *start = NULL, *end = NULL; /*リストの先頭と後尾*/

/*関数のプロトタイプ宣言*/
void enqueue(int data); /*エンキュー*/
int dequeue(void);      /*デキュー*/
struct lnode *lalloc(void); /*ノードのメモリ確保*/
struct lnode *add(void);    /*リストへのノードの追加*/

/****************/
/*main()関数    */
/****************/
int main(){
  printf("enqueue(5) \n");
  enqueue(5);
  printf("enqueue(10) \n");
  enqueue(10);
  printf("dequeue %d\n", dequeue());
  printf("enqueue(15) \n");
  enqueue(15);
  printf("enqueue(20) \n");
  enqueue(20);
  printf("dequeue %d \n", dequeue());
  printf("dequeue %d \n", dequeue());
  printf("dequeue %d \n", dequeue());
  printf("dequeue %d \n", dequeue());

  return 0;
}

/***************/
/*enqueue()関数*/
/***************/
void enqueue(int data){
  struct lnode *temp;

  if(start == NULL){ /*リストが存在しない*/
    end = start = add();
    start -> data = data;
  } else { /*既存リストへの追加*/
    temp = end;
    end = end -> ptr = add(); /*ノードの追加*/
    end -> data = data; /*データの追加*/
  }
}


/***************/
/*dequeue()関数*/
/***************/
int dequeue(void){
  struct lnode *temp;
  int top;

  if(start == NULL){ /*リストが存在しない*/
    fprintf(stderr, "エラー データがありません\n");
    exit(1); /*エラーで終了*/
  }

  temp = start; /*削除対象のポインタを保存*/
  top = temp -> data; /*戻り地*/
  start = start -> ptr; /*開始位置を2番目の要素に変更*/
  free(temp); /*メモリ領域を開放*/
  return top;
}


/***********************/
/*リストへのノードの追加*/
/***********************/
struct lnode *add(void){
  struct lnode *ptr;

  ptr = lalloc(); /*ノードを作る*/
  ptr -> ptr = NULL; /*リストの終わり*/
  return ptr;
}



/***********************/
/*ノードのメモリの確保  */
/***********************/
struct lnode *lalloc(void){
  return (struct lnode *) malloc(sizeof(struct lnode));
}
