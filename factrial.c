#define BUFSIZE 256 /*入力バッファ用配列の長さ*/

#include <stdio.h>

/*関数のプロトタイプ宣言*/
int getint(void); /*データをひとつだけ読み込む*/
int factrial();   /*nの階乗を計算する*/

int main(){
  int n; /*入力データ*/
  while((n = getint()) >= 0){
    printf("%d!=%d\n", n, factrial(n));
  }
  return 0;
}

/*******************/
/*factrial()関数    /
/*再帰的に階乗を計算*/
/*******************/

int factrial(int n){
  if(n == 0){
    return 1; /*0の階乗は1*/
  } else {
    return n * factrial(n - 1); /*n - 1の階乗にnをかける*/
  }
}

/***************/
/*getint()関数**/
/*整数の読み込み*/
/***************/

int getint(void){
  char linebuf[BUFSIZE]; /*1行入力の文字配列*/
  int n;                 /*入力データ*/
  
  if(fgets(linebuf, BUFSIZE, stdin) != NULL){ /*行の読み取りが可能*/
    if(sscanf(linebuf, "%d", &n) <= 0) /*変換できなければ*/
      n = -1; /*エラー*/
  } else {
    n = -1;   /*エラー*/
  }
  return n;
}



