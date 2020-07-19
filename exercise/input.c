#include <stdio.h>

int input_data()
{
   int i;

   fprintf(stderr, "Input Num = ");
   scanf("%d", &i);

   return i;
}