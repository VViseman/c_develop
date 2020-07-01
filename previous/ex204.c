#define STRINGLENGTH 256   /*文字列の長さ*/
#define RECORDLIMIT  1024  /*レコード数の上限*/
#define BUFSIZE      256   /*入力バッファ要用配列の長さ*/

#include <stdio.h>
#include <string.h>

/*構造体の宣言*/
struct record {
  unsigned short int number;     /*番号*/
  char name[STRINGLENGTH];       /*名前*/
  char maddress[STRINGLENGTH];   /*メールアドレス*/
  unsigned short int telnumber;  /*内線電話番号*/
  char note[STRINGLENGTH];       /*備考*/
} ;


/*関数のプロトタイプ宣言*/
void printrecord(struct record list[], int no); /*名簿データを入力*/

int  searchno(struct record list[], int no);    /*名簿データの検索*/

/*********************/
/*      main()関数   */
/*********************/

int main(){

  struct record list[RECORDLIMIT] = { /*名簿格納用配列*/
    {1,"Satou Kentaro", "satou@xxx.jp",5678,"" },
    {2,"Yamada Momoko", "yamada@yyy.jp",6789,"" },
    {3,"Suzuki Yuu", "suzuki@aaa.jp",7890,"kakunin" },
    {4,"Tanaka Yoko", "yanaka@bbb.jp",5678,"" }
  };

 char linebuf[BUFSIZE];   /*1行入力用の文字配列*/
 int no;                  /*検索番号入力用変数*/

 /*検索開始*/
 printf("番号を入力してください\n");
 while(fgets(linebuf, BUFSIZE, stdin) != NULL){
   /*行の読み取りが可能な間繰り返す*/
   if(sscanf(linebuf, "%d", &no) != 0) /*変換できたら*/
     printrecord(list, searchno(list, no)); /*名簿データを入力*/
     printf("\n番号を入力してください\n");
 }
 return 0;
}


/*************************/
/*    searchno()関数     */
/*    名簿データ検索      */
/*************************/

int searchno(struct record list[], int no){
  int i = 0;

  while ((list[i].number > 0) && (i < RECORDLIMIT)){
    if(list[i].number == no) /*numberを発見*/
      return i;
    ++i;
  }
  return -1;  /*発見できなかった(エラー)*/
}
  
/*************************/
/*    printrecord()関数     */
/*    名簿データの出力      */
/*************************/

void printrecord(struct record list[], int no){
  if(no < 0){  /*レコード番号が不正*/
    printf("該当するデータが見つかりません\n");
  } else { /*名簿データの出力*/
    printf("番号: %d\n", list[no].number);
    printf("名前: %s\n", list[no].name);
    printf("メールアドレス: %s\n", list[no].maddress);
    printf("内線電話番号: %d\n", list[no].telnumber);
    printf("備考: %s\n", list[no].note);
  }
}
