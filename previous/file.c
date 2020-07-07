/*メニューに従って処理を行う対話型プログラムの*/
/*拡張部分のソースファイルです               */
/*ヘッダファイルfcalc.hが必要です            */

#include <stdio.h>

#include "fcalc.h" /*共用のヘッダファイルです*/

/*******************/
/*fileout()関数    */
/*7 ファイル書き込み*/
/*******************/

void fileout(double data[], int no){
  FILE *fp; /*ファイルポインタ*/
  int i;

  printf("\n\n7 ファイル書き込み\n"); 
  if((fp = fopen(DATAFILENAME, "w")) == NULL){ /*ファイルおオープン失敗*/
    printf("ファイルをオープンできません\n");
    return ;
  }
  for(i = 0; i < no; ++i){   /*書き込み*/
    fprintf(fp, "%lf\n", data[i]);
  }
  printf("%d個のデータを書き込みました\n",no);
  fclose(fp); /*ファイルクローズ*/
}



/********************/
/*filein()関数      */
/*8 ファイル読み出し */
/********************/

int filein(double data[], int no){
  FILE *fp;
  double inputdata; /*データ入力用変数*/
  int oldno;

  printf("\n\n8 ファイル読み出し\n");
  oldno = no;   /*データ個数を保存しておく*/

  if((fp = fopen(DATAFILENAME, "r")) == NULL ){ /*ファイルオープン失敗*/
    printf("ファイルが見つかりません\n");
    return no ;
  }
  while(fgetdouble(fp, &inputdata) != EOF){ /*読み出し*/
    data[no++] = inputdata;
  }
  printf("%d個のデータを読み込みました\n", no - oldno);
  fclose(fp); /*ファイルクローズ*/
  return no;
}


/*********************/
/*fgetdouble()関数   */
/*実数の読み込み      */
/*********************/

int fgetdouble(FILE *fp, double *x){
  char linebuf[BUFSIZE]; /*1行入力用の文字配列*/
  int result = 0;        /*入力結果のコード*/

  if(fgets(linebuf, BUFSIZE, fp) != NULL){ /*行の読み取りが可能*/
    if(sscanf(linebuf, "%lf",x) <= 0) /*変換できなければ*/
      result = EOF; /*エラー*/
  } else {
    result = EOF; /*ファイルの終わり*/
  }
  return result;
}
