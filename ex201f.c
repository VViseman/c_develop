/*ファイルの終わり(EOF)まで              */
/*整数を読み取り2乗の値を求めます         */
/*ただし、このプログラムは失敗例ですから、*/
/*このまま使うのは危険です               */

#include <stdio.h>

#define BUFSIZE 256 /*入力バッファ用配列の長さ*/

int  main(){
  int i; /*読み込んだ整数を格納するためのint型整数*/
  char linebuf[BUFSIZE]; /*１行入力用の文字配列*/
  
  while(fgets(linebuf, BUFSIZE, stdin) != NULL){
    /*行の読み取りが可能な間繰り返す*/
    /*scanfだと期待した入力と異なるデータ形式が入力されるとエラーになる*/
    if(sscanf(linebuf, "%d", &i) != 0) /*変換できたら*/
    printf("2乗の値 :  %d\n",i * i);
  }

  return 0;
}


/*データの読み込みにおいてscanf()関数の代わりに、fgets()関数を用いている。
fgets()関数は、標準入力から１行のデータを読み取り、引数で指定された配列
linebuf[]に入力された文字列を格納する。次にsscanf()関数を使って、
linebuf[]に格納された文字列から、整数型の数値を取り出す*/


