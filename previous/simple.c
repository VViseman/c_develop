/*文字列探索プログラム*/
/*単純法による文字列探索*/

#define TLIMIT 10000 /*探索対象テキストの最大長*/
#define PLIMIT 256   /*パターンの最大長*/

#include <stdio.h>
#include <string.h>

/*関数のプロトタイプ宣言*/
int chkmatch(int, int, char *, char *); /*文字列一致の検査*/
void simple(char obj[], char pattern[]); /*文字列の探索*/

/*****************/
/*main()関数     */
/*****************/

int main(){
  char pattern[PLIMIT]; /*探索パターン*/
  char obj[TLIMIT];     /*探索対象テキスト*/

  /*パターンの入力*/
  printf("探索パターンを入力してください\n");
  fgets(pattern, PLIMIT, stdin);
  pattern[strlen(pattern) - 1] = '\0'; /*改行コードの削除*/
  /*テキストの入力*/
  printf("テキストを入力してください\n");
  fgets(obj, TLIMIT, stdin);


  /*探索*/
  simple(obj, pattern);

  return 0;
}


/**************/
/*文字列の探索 */
/**************/
void simple(char obj[], char pattern[]){
  int i;
  int objlen, patternlen;

  objlen = strlen(obj);
  patternlen = strlen(pattern);

  for(i = 0; i < objlen; ++i){ /*テキスト全体を探索*/
    if(chkmatch(i, patternlen, obj, pattern)){
      printf("発見 %d\n", i);
    }
  }
}


/*******************/
/*文字列一致の検査  */
/*******************/
int chkmatch(int pos, int patternlen, char obj[], char pattern[]){
  int i;
  int flag = 1; /*一致したら1,不一致なら0*/

  for(i = 0; i < patternlen; ++i){
    if(pattern[i] != obj[pos + i]){ /*不一致*/
      flag = 0;
      break;
    }
  }
  return flag;
}

