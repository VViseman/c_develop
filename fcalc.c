/*メニューに従って処理を行う対話型プログラム*/
/*最大32767個までの数値をメニューに使って処理します*/


#define BUFSIZE 256 /*入力バッファ用配列の長さ*/
#define MAXDATASIZE 32767 /*データ格納用配列の大きさ*/

#include <stdio.h>
#include <math.h>    /*標準偏差の計算に用いる*/
#include "fcalc.h"   /*共用のヘッダファイルですa*/


/*********************/
/*     main()関数    */
/*********************/

int main(){
  int command; /*コマンド番号*/
  double data[MAXDATASIZE]; /*データ格納用配列*/
  int no = 0; /*データの個数*/

  showmenu();  /*メニューの表示*/

  while((command = getint()) != 9){ /*終了(9)以外は入力継続*/
    switch(command){
      case 1 : no = datainput(data, no); break; /*1 データの新規入力・追加*/
      case 2 : display(data, no);     break; /*2 データの出力*/
      case 3 : correct(data,no);      break; /*3 データの修正*/
      case 4 : calc(data, no);        break; /*4 平均・分散・標準偏差の計算*/
      case 5 : search(data, no);      break; /*5 検索*/
      case 6 : sort(data, no);        break; /*6 整列*/
      case 7 : fileout(data, no);     break; /*7 ファイル書き込み*/
      case 8 : no = filein(data, no); break; /*8 ファイル読み出し*/
      default : printf("メニューの番号で選んでください\n>"); /*エラー*/
      continue;
    }
    showmenu(); /*メニューの表示*/
  }
  return 0;
}


/*************************/
/*datainput()関数        */
/*1 データの新規入力・追加*/
/*************************/

int datainput(double data[], int no){
  double inputdata; /*データ入力用変数*/

  printf("\n\n1 データの新規入力・追加\n");
  printf("データを入力してください(Ctrl-Dで終了)\n");
  while (getdouble(&inputdata) != EOF){
    data[no++] = inputdata;
  }
  return no;
}


/*************************/
/*display()関数           */
/*2  データの出力         */
/*************************/

void display(double data[], int no){
  int from, till; /*データの出力範囲*/

  printf("\n\n2 データの出力\n");
  printf("出力開始データ番号を入力(Enter:0番目から)\n");
  if((from = getint()) <= 0) from = 0;
  printf("出力終了データ番号を入力(Enter:最後まで)\n");
  if((till = getint()) <= 0) till = no - 1;/*デフォルト*/
  if(till > no - 1) till = no - 1; /*範囲指定がおかしい*/
  partdisplay(data, from, till); /*データの表示*/
}


/****************************/
/*partdisplay()関数         */
/*display()関数の下請け関数  */
/****************************/

void partdisplay(double data[], int from, int till){
  int i;
  for(i = from; i <= till; ++i){
    printf("%d:%lf\n",i,data[i]);
  }
}

/*****************************/
/*correct()関数              */
/*3 データの修正             */
/****************************/

void correct(double data[], int no){
  int cpoint;       /*修正データ番号*/
  double inputdata; /*修正値*/

  printf("\n\n3 データの修正\n");
  printf("修正対象データ番号を入力\n");
  if((cpoint = getint()) < 0){ /*入力エラー*/
    printf("修正を中止します\n");
    return ;
  }
  if((cpoint < 0) || (cpoint >= no)){ /*入力エラー*/
    printf("修正を中止します\n");
    return ;
  }

  printf("修正対象:");
  partdisplay(data, cpoint, cpoint); /*データの表示*/
  printf("修正値を入力してください\n");
  if(getdouble(&inputdata) == EOF){ /*入力エラー*/
    printf("修正を中止します\n");
    return ;
  }
  data[cpoint] = inputdata; /*データ書き換え*/
  printf("修正完了\n");
}


/*****************************/
/*calc()関数                 */
/*4 平均・分散・標準偏差の計算*/
/****************************/

void calc(double data[], int no){
  double ave;  /*平均値*/
  double var;  /*分散*/
  printf("\n\n4 平均・分散・標準偏差の計算\n");

  if(no <= 0){ /*データがない*/
    printf("データがありません\n");
    return ;
  }
  printf("データの個数:%d\n",no);
  printf("平均:%lf\n",ave = average(data, no));
  printf("分散:%lf\n",var = variance(data, no, ave));
  printf("標準偏差:%lf\n",sqrt(var));
}


/****************************/
/*average()関数             */
/*calc()関数の下請け関数     */
/****************************/

double average(double data[], int no){
  int i;
  double sum = 0;
  for(i = 0; i < no; ++i){
    sum += data[i];
  }
  return sum / no;
}


/*************************/
/*variance()関数　　　　　*/
/*calc()関数の下請け関数  */
/*************************/

double variance(double data[], int no,double ave){
  int i;
  double var = 0;
  for(i = 0; i < no; ++i){
    var += (data[i] - ave) * (data[i] - ave);
  }
  return var / no;
}

/*****************************/
/*search()関数               */
/*5 検索                     */
/****************************/

void search(double data[], int no){
  double searchdata; /*検索対象データ*/
  int i;

  printf("\n\n5 検索\n");
  if(no <= 0){   /*データがない*/
    printf("データがありません\n");
    return;
  }
  printf("検索対象データを入力してください\n");
  if(getdouble(&searchdata) == EOF){ /*入力エラー*/
    printf("検索を中止します\n");
    return;
  }
  /*該当データの入力*/
  for(i = 0; i < no; ++i){
    if(data[i] == searchdata) printf("%d:%lf\n",i,data[i]);
  }
}


/***************************/
/*sort()関数               */
/*6 整列                   */
/**************************/

void sort(double data[], int no){
  printf("\n\n6 整列\n");
  dqsort(data, 0, no - 1); /*クイックソート*/
  printf(" 整列終了\n");
}

/***************************/
/*dqsort()関数             */
/*クイックソート関数(実数用)*/
/***************************/

void dqsort(double data[], int lower, int upper){
  int i, boundary; /*変数boundaryは配列の前半と後半の境界を示す*/

  if(lower >= upper)
    return; /*整列する部分がない*/

  dswappdata(&data[lower], &data[(lower + upper) / 2]);  /*中央のデータを基準値とする*/

  boundary = lower;  /*変数boundary(配列の前半と後半の境)を、データの先頭にセット*/

  for(i = lower + 1; i <= upper ; i++){
    if(data[i] < data[lower]){ /*基準値よりi番目の要素が小さかったら*/
      dswappdata(&data[++boundary], &data[i]); /*配列の前半部分に移動し、境界を移動する*/
    }
  }

  dswappdata(&data[lower], &data[boundary]); /*最後に、基準値を境界位置にコピー*/
  dqsort(data, lower, boundary - 1); /*配列の前半部分をクイックソート*/
  dqsort(data, boundary + 1, upper); /*配列の後半部分をクイックソート*/
}

/********************/
/*dswappdata()関数  */
/*dqsort()関数で利用*/
/********************/

void dswappdata(double *i, double *j){
  double temp; /*値の一時保存領域*/

  temp = *i;
  *i = *j;
  *j = temp;
}


/*******************************/
/*showmenu()関数               */
/*メニューの表示               */
/******************************/

void showmenu(void){
  printf("\n\n計算処理プログラム\n");
  printf("処理番号を入力してください\n");
  printf("1 データの新規入力・追加\n");
  printf("2 データの出力\n");
  printf("3 データの修正\n");
  printf("4 平均・分散・標準偏差の計算\n");
  printf("5 検索\n");
  printf("6 整列\n");
  printf("7 ファイル書き込み\n");
  printf("8 ファイル読み出し\n");
  printf("9 終了\n>");
}

/*********************/
/*getint()関数       */
/*メニュー番号の表示  */
/*********************/

int getint(void){
  char linebuf[BUFSIZE]; /*1行入力用の文字配列*/
  int n;                 /*入力データ*/

  if(fgets(linebuf, BUFSIZE, stdin) != NULL){ /*行の読み取りが可能*/
    if(sscanf(linebuf, "%d", &n) <= 0)        /*変換できなければ*/
      n = -1;                                 /*エラー*/
  } else {
    n = -1;                                   /*エラー*/
  }
  return n;
}


/*********************/
/*getdouble()関数    */
/*実数の読み込み     */
/********************/

int getdouble(double *x){
  char linebuf[BUFSIZE]; /*1行入力用の文字配列*/
  int result = 0;        /*入力結果のコード*/

  if(fgets(linebuf, BUFSIZE, stdin) != NULL) { /*行の読み取りが可能*/
    if(sscanf(linebuf, "%lf", x) <= 0)        /*変換できなければ*/
    result = EOF;     /*エラー*/
  } else {  /*行が読めない*/
    result = EOF;     /*ファイルの終わり*/
  }
  return result;
}
