#include <stdio.h>

int main(void)(
  char *str; /*文字列へのポインタ*/

  str = "Hello!\n"; /*文字列定数のアドレスをstrに代入*/

  printf(str);

  return 0;
}
