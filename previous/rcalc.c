#define STACKSIZE 256 /*スタック用配列の長さ*/
#define BUFSIZE   256 /*入力バッファ用配列の長さ*/

#include <stdio.h>
#include <stdlib.h>


int stack[STACKSIZE]; /*スタックデータ格納用配列*/
int stackpointer = 0; /*スタックポインタ*/

/*関数のプロトタイプ宣言*/
void push(int data); /*プッシュ*/
int pop(void);       /*ポップ*/
void add(void);      /*加算*/
void sub(void);      /*減算*/
void mult(void);     /*乗算*/
void divide(void);      /*除算*/

/************/
/*main()関数*/
/************/
int main(){
  int data; /*入力データを格納e*/
  char command; /*演算子を格納*/
  char linebuf[BUFSIZE]; /*1行入力用の文字配列*/

  printf("電卓プログラム\n");

  /*計算開始*/
  while(fgets(linebuf, BUFSIZE, stdin) != NULL){
    /*行の読み取りな可能なあいだ繰り返す*/
    if(sscanf(linebuf, "%d", &data) != 0){ /*変換できたら*/
      push(data); /*スタックにプッシュ*/
    } else if (sscanf(linebuf, "%c", &command) != 0){
      switch(command){
      case '+' : add(); break; /*加算*/
      case '-' : sub(); break; /*減算*/
      case '*' : mult(); break; /*乗算*/
      case '/' : divide(); break; /*除算*/        
      }
    }
  }
  return 0;
}



/*******************/
/*add()関数        */
/*******************/
void add(void){
  int result; /*加算結果*/

  push(result = pop() + pop()); /*スタックの先頭2つの要素を加算*/
  printf("%d\n", result);
}



/*******************/
/*sub()関数        */
/*******************/
void sub(void){
  int result; /*減算結果*/
  int temp;   /*スタックの上部要素の保存領域*/

  temp = pop();
  push(result = pop() - temp); /*スタックの先頭2つの要素を減算*/
  printf("%d\n", result);
}


/*******************/
/*mult()関数        */
/*******************/
void mult(void){
  int result; /*乗算結果*/

  push(result = pop() * pop()); /*スタックの先頭2つの要素を乗算*/
  printf("%d\n", result);
}


/*******************/
/*div()関数        */
/*******************/
void divide(void){
  int result; /*除算結果*/
  int temp;   /*スタックの上部要素の保存領域*/

  temp = pop();
  push(result = pop() / pop()); /*スタックの先頭2つの要素を乗算*/
  printf("%d\n", result);
}


/********************/
/*ouxh()関数        */
/********************/
void push(int data){
  if(stackpointer >= STACKSIZE - 1){
    fprintf(stderr, "エラー スタックがいっぱいです。\n");
    return;
  }
  stack[stackpointer++] = data;
}


/********************/
/*pop()関数        */
/********************/
int pop(void){
 if(stackpointer <= 0){
    fprintf(stderr, "エラー データがありません。\n");
    exit(1); /*以上終了*/
 }
 return (stack[--stackpointer]); 
}
