#define BUFSIZE 256 /*文字列用配列の長さ*/
#include <stdio.h>

/*プロトタイプ宣言*/
void outputstring(char string[]); /*文字列の出力*/

/****************/
/*main()関数    */
/****************/

int main(void){
/*  char string[BUFSIZE]; /*文字列を表現する文字配列*/

/*  string[0] = 'C';
  string[1] = ' ';
  string[2] = 'l';
  string[3] = 'a';
  string[4] = 'n';
  string[5] = 'g';   
  string[6] = '\n';    /*改行*/
/*  string[7] = '\0';    /*文字列の終わり*/

  char string[] = "C lang\n";
  

  printf("outputstring()関数による文字列の出力\n");
  outputstring(string); /*文字列の出力*/
  

return 0;
}


/****************/
/*文字列の出力   */
/****************/

void outputstring(char string[]){
  int i = 0;

  while(string[i] != '\0'){ /*文字列の終わりが来るまで*/
    putchar(string[i++]); /*一文字ずつ出力*/
  }
}

