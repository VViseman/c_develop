/*パスワード照合プログラム*/
/*文字列比較の例題です*/
/*文字列の照合を一文字ずつ行います*/

#define BUFSIZE 256 /*入力バッファ用配列の長さ*/
#define PASSWORD "password" /*文字列照合の対象(パスワード)*/
#define LIMIT 3 /*照合失敗回数の上限*/

#include <stdio.h>

/*関数のプロトタイプ宣言*/
int compare(char linebuf[], char *); /*文字列の比較*/

int main(void){
  int i = 1; /*入力回数のカウンタ*/
  char linebuf[BUFSIZE];  /*1行入力用の文字配列*/

  /*照合開始*/
  printf("パスワードを入力してください\n");

  while(fgets(linebuf, BUFSIZE, stdin) != NULL){ /*行の読み取りが可能な間繰り返す*/
    if(compare(linebuf, PASSWORD) == 0){  /*一致*/
      printf("パスワードを確認しました\n");      
      break;  /*終了*/
    }else {
      ++i;
      if(i > LIMIT) break; /*繰り替えしの上限を超えた*/
      printf("もう一度入力してください\n");
    }
  }
  if(i > LIMIT) printf("照合失敗\n");
  return 0;
}



/**************/
/*文字列の比較*/
/**************/


int compare(char linebuf[], char pwd[]){
  int i = 0;
  int res = 0; /*照合結果. 0で一致、-1で不一致*/

  while (pwd[i] != '\0'){
    if(linebuf[i] != pwd[i]){   /*不一致*/
      res = -1;
      break;
    }
    ++i;
  }
  return res;
}
