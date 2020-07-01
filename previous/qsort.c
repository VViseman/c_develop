/*整列プログラム2　クイックソート版*/
/*整数を読み取り、昇順に整列します*/
/*クイックソートのアルゴリズムを実施します*/

#define MAXSIZE 32768 /*整列対象データであるdata[]配列の最大長*/
#define BUFSIZE 256   /*入力バッファ用配列の長さ*/

#include <stdio.h>

/*関数のプロトタイプ宣言*/
int getdata(int data[]);                          /*データの入力*/
void quicksort(int data[], int lower, int upper); /*クイックソート*/
void putdata(int data[], int n);                  /*結果の出力*/
void swapdata(int *i, int *j);                    /*データの入れ替え*/

int main(){
    int data[MAXSIZE]; /*整列対象データ*/
    int n;             /*入力データの個数*/

    n = getdata(data); /*データの入力*/
    quicksort(data, 0, n - 1); /*クイックソート*/
    putdata(data, n); /*結果の出力*/

    return 0;
}


/*quicksort()関数*/
/*引数data[]をソート*/

void quicksort(int data[], int lower, int upper){
  int i, boundary; /*変数boundaryは前半と後半の協会を示す*/
  if(lower >= upper) return; /*整列する部分がない*/
      swapdata(&data[lower], &data[(lower + upper) / 2]); /*中央のデータを基準値とする*/

      boundary = lower; /*変数boundary(配列の前半と後半の境を、データの先頭にセット)*/

      for (i = lower + 1; i <= upper; i++) {
        if(data[i] < data[lower]) /*基準値よりi番目の要素が小さかったら*/
        swapdata(&data[++boundary], &data[i]);  /*配列の前半部分に移動し、境界を移動する*/
      }

        swapdata(&data[lower], &data[boundary]); /*最後に、基準値を境界位置にコピー*/
        quicksort(data, lower, boundary - 1);   /*配列の前半部分をクイックソート*/
        quicksort(data, boundary + 1, upper);   /*配列の後半部分をクイックソート*/

}

/*putdata()関数*/
/*結果の出力*/

void putdata(int data[], int n){
  int i; /*繰り返しの制御用変数*/

  for(i = 0; i < n; i++){
    printf("%d : %d\n", i, data[i]);
  }
}

/*getdata()関数*/
/*データの入力*/

int getdata(int data[]){
  char linebuf[BUFSIZE]; /*1行入力用の文字配列*/
  int n = 0;

  while(fgets(linebuf, BUFSIZE, stdin) != NULL){ /*行の読み取りが可能な間繰り返す*/
    if(sscanf(linebuf, "%d", &data[n]) != 0) /*変換できたら*/
        ++n; /*データ個数をカウントアップ*/
    if(n >= MAXSIZE){ /*入力サイズの個数が上限に達した*/
      fprintf(stderr, "入力データの個数が上限に達しました\n");
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
