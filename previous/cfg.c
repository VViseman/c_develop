#define BUFSIZE 256 /*文字列用の長さ*/
#define TABLESIZE 256 /*ルール格納用配列の長さ*/
#define START "<S>"   /*開始記号*/
#define RULEFILENAME  "rulefile.dat" /*生成規則格納用ファイルの名前*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*構造体のテンプレートの宣言*/
struct rule {
  char left[BUFSIZE]; /*ルールの左辺*/
  char right[BUFSIZE]; /*ルールの右辺*/
} ;

/*関数のプロトタイプ宣言*/
int setrule(struct rule ruletable[]);  /*ルール表の読み込み*/
void extraction(char string[], struct rule ruletable[], int no_of_rule); /*ルールによる書き換え*/
void setnt(char nt[], char string[], int head, int rail); /*headからtailをntにコピー*/
int setruleno(struct rule ruletable[], int no_of_rule, char nt[]); /*適用ルールの決定*/
void generation(char string[], char right[], int head, int tail); /*非終端記号の書き換え*/

/****************/
/*main()関数    */
/****************/

int main(void){
  struct rule ruletable[TABLESIZE]; /*ルール用配列*/
  int no_of_rule = 0; /*ルールの個数*/
  char string[BUFSIZE]; /*文字列を表現する文字配列*/

  srand(time(NULL)); /*乱数の設定*/
  no_of_rule = setrule(ruletable); /*ルール表の読み込み*/

  /*開始記号の設定*/
  strncpy(string, START, BUFSIZE);

  /*ルールによる書き換え*/
  while (strchr(string, '<') != NULL){ /*非終端記号がある間繰り返す*/
    printf("生成中 : %s\n", string);
    extraction(string, ruletable, no_of_rule);
  }


  printf("\n生成終了 : %s\n", string);
  
  return 0;
}



/**********************/
/*ルールによる書き換え */
/**********************/

void extraction(char string[], struct rule ruletable[], int no_of_rule){
  int head, tail; /*書き換え対象の非終端記号の位置*/
  char nt[BUFSIZE];  /*書き換え対象の非終端記号*/
  int ruleno; /*適用ルールの番号*/

  /*書き換え対象の非終端記号を決定*/
  head = strchr(string, '<') - string;
  tail = strchr(string, '>') - string;
  setnt(nt, string, head, tail); /*headからtailまでをntコピー*/

  /*適用ルールの決定*/
  ruleno = setruleno(ruletable, no_of_rule, nt);


  /*非終端記号の書き換え*/
  generation(string, ruletable[ruleno].right, head, tail);
  
}

/**********************/
/*非終端記号の書き換え */
/**********************/
void generation(char string[], char right[], int head, int tail){
  int i; /*カウンタ*/
  int stringlength; /*当初のstring[]の長さ*/
  int dist; /*文字列の移動距離*/

  stringlength = strlen(string);
  dist = strlen(right) - (tail - head + 1);

  /*挿入場所を作る*/
  for(i = 0; i < stringlength - tail ; ++i){
    string[stringlength - i + dist] = string[stringlength - i];
  }

  /*元の非終端記号は消去する*/
  for(i = head; i < strlen(right); ++i){
    string[i] = ' ';
  }

  /*ルールの右辺を挿入*/
  for(i = 0; i < strlen(right); ++i){
    string[i + head] = right[i];
  }
}


/**********************/
/*適用ルールの決定     */
/**********************/
int setruleno(struct rule ruletable[], int no_of_rule, char nt[]){
  int ptr = -1; /*ルール探索用のポインタ*/
  int rnd;      /*試行回数を決める乱数*/
  int i;        /*カウンタ*/


  rnd = rand() / (double)RAND_MAX * no_of_rule + 1; /*試行回数*/

  for(i = 0; i < rnd; ++i){
    ++ptr;
    if(ptr >= no_of_rule){
      ptr = 0; /*やり直し*/
    }
    while(ptr < no_of_rule){
      if(strncmp(ruletable[ptr].left, nt, BUFSIZE) == 0){
        break; /*発見*/
      }
      ++ptr;
      if(ptr >= no_of_rule){
      ptr = 0; /*やり直し*/ 
      }
    }
  }
  return ptr;
}


/****************************/
/*headからtailまでをntコピー*/
/****************************/
void setnt(char nt[], char string[], int head, int tail){
  int i; /*ループカウンタ*/

  for(i = head; i <= tail; ++i){
    nt[i - head] = string[i]; /*一文字づつコピー*/
  }
  nt[i - head] = '\0'; /*文字の終わり*/
}

/****************************/
/*ルール表の読み込み         */
/****************************/

int setrule(struct rule ruletable[]){
  FILE *fp; /*ファイルポインタ*/
  char linebuf[BUFSIZE]; /*データ入力用変数*/
  int no = 0;

  /*ファイルオープン*/
  if((fp = fopen(RULEFILENAME, "r")) == NULL){ /*ファイルオープン失敗*/
    printf("ファイル%sが見つかりません\n",RULEFILENAME);
    exit(1); /*生成規則が読み込めないので異常終了*/
  }

  while(fgets(linebuf, BUFSIZE, fp) != NULL){ /*行の読み取りが可能*/
    if(strchr(linebuf, '\n') != NULL)
    *strchr(linebuf, '\n') = '\0'; /*改行コードを消す*/
    strncpy(ruletable[no].left, linebuf, BUFSIZE); /*左辺をセット*/
    
    fgets(linebuf, BUFSIZE, fp);
    if(strchr(linebuf, '\n') != NULL);
    strncpy(ruletable[no].right, linebuf, BUFSIZE); /*右辺をセット*/
    ++no;
  }

  fclose(fp); /*ファイルクローズ*/
  return no; /*ルールの個数を返す*/
}
