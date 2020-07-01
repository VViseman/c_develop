/*整列プログラム1　　バブルソート版*/
/*整数を読み取り、昇順に整列します*/
/*整列はしますが計算量の観点から問題があります*/


#define MAXSIZE 32768 /*整列対象データであるdata[]配列の最大長*/
#define BUFSIZE 256   /*入力バッファ用配列の長さ*/


#include <stdio.h>

/*関数のプロトタイプ宣言*/
int getdata(int data[]);             /*データの入力*/
void bubblesort(int data[], int n);  /*バブルソート*/
void putdata(int data[], int n);     /*結果の出力*/
void swapdata(int *i, int *j);       /*データの入れ替え*/

/*main関数*/

int main(){
  int data[MAXSIZE]; /*整列対象データ*/
  int n; /*入力データの個数*/

  n = getdata(data);    /*データの入力*/
  bubblesort(data, n);  /*バブルソート*/
  putdata(data, n);     /*結果の出力*/

  return 0;
}


/*bubblesort()関数*/
/*引数data[]をソート*/

void bubblesort(int data[], int n){
  int i,j; /*繰り返しの制御用変数*/

  for(i = n - 1; i >= 2; --i){    /*データ全体を処理する*/
    for(j = 0; j < i; ++j){       /*データを2個ずつ比較する*/
      if(data[j] > data[j + 1])   /*大きい方を後ろへ送る*/
        swapdata(&data[j], &data[j + 1]);
    }
  }
}

/*putdata()関数*/
/*結果の出力*/

void putdata(int data[], int n){
  int i; /*繰り返しの制御用変数*/

  for(i = 0; i < n; i++)
    printf("%d : %d\n", i, data[i]);
}


/*getdata()関数*/
/*データの入力*/

int getdata(int data[]){
  char linebuf[BUFSIZE]; /*1行入力用の文字配列*/
  int n = 0;

  while(fgets(linebuf, BUFSIZE, stdin) != NULL){
    /*行の読み取りが可能な間繰り返す*/
    if(sscanf(linebuf,"%d", &data[n]) != 0) /*変換出来たら*/
      ++n; /*データ個数をカウントアップ*/
    if(n >= MAXSIZE){ /*データ個数が上限に達した*/
      fprintf(stderr,"　入力データの個数が上限に達しました\n");
      break; /*入力終了*/
    }
  }
  printf("%d個のデータを読み取りました\n", n);
  return n;
}


/*swapdata()関数*/
/*データの入れ替え*/

void swapdata(int *i, int *j){
  int temp; /*値の一時保存領域*/

  temp = *i;
  *i = *j;
  *j = temp;
}
