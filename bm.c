/*文字列探索プログラム*/
/*BM法による文字列探索*/


#define TLIMIT 10000 /*探索対象テキストの最大長*/
#define PLIMIT 256   /*パターンの最大長*/
#define NOK 256      /*文字の種類*/

#include <stdio.h>
#include <string.h>

/*関数のプロトタイプ宣言*/
int max(int, int);   /*大きい値を返す*/
void bm(char obj[], char pattern[]);  /*文字列配列の探索(BM法)*/
void setaddpos(int addpos[], char pattern[], int patternlen); /*移動量のセット*/

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
  bm(obj, pattern);
 
  return 0;
}

/***********************/
/*文字列の探索(BM法)    */
/***********************/

void bm(char obj[], char pattern[]){
  int objp, patternp; /*探索位置保持用*/
  int objlen, patternlen;
  int addpos[NOK]; /*パターンの移動量*/

  objlen = strlen(obj);
  patternlen = strlen(pattern);
  setaddpos(addpos, pattern, patternlen); /*移動量のセット*/

  objp = patternlen - 1; /*テキストの探索開始位置を設定*/

  while(objp < objlen){ /*テキスト全体を探索*/
    patternp = patternlen - 1; /*パターンの最後から照合*/
    while(obj[objp] == pattern[patternp]){
      if(patternp == 0){
        printf("発見 %d\n", objp);   /*パターンと一致　*/
        break;
      }
      --objp;
      --patternp; /*一文字ずらす*/
    }
    objp += max(addpos[obj[objp]], patternlen - patternp); /*照合位置を更新*/
  }
}
  
/*******************/
/*移動量のセット    */
/*******************/

void setaddpos(int addpos[], char pattern[], int patternlen){
  int i;

  for(i = 0; i < NOK; i++){
    addpos[i] = patternlen; /*とりあえず全部を最大移動量とする*/
  }
  for(i - 0; i < patternlen; ++i){  /*パターン中に出現する文字の移動量*/
    addpos[pattern[i]] = patternlen - i - 1;    
  }
}

/*******************/
/*大きい値を返す    */
/*******************/
int max(int a, int b){
  if(a > b) {
    return a;
  } else {
    return b;
  }
}
