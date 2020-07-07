#include <stdio.h>
#include <string.h>

#define BUFLENGTH 256

/************/
/*main()関数*/
/************/
int main(){
  int i = 0;
  char ans[BUFLENGTH];
  char *q[] = {"常時書き換えできるか?", "リフレッシュが必要か?", "製造時に内容が固定されるか?",
               "Answer : DRAM", "Answer : SRAM", "Answer : マスクROM",
               "電気的に消去できるか?", "", "", "", "", "", "",
               "Answer : フラッシュメモリ", "Answer : UVEPROM"};

  /*処理の本体*/
  while(q[i][0] != 'A'){ /*答えが出るまで繰り返し*/
    printf("%s\n", q[i]); /*メッセージの出力*/
    fgets(ans, 255, stdin);
    if(strncmp(ans, "y", 1) == 0){
      i = 2 * i + 1; /*下位左ノードへ分岐*/
    } else {
      i = 2 * i + 2; /*下位右ノードへ分岐*/
    }
  }
  
  printf("%s\n", q[i]); /*答えの出力*/

  return 0;
}
