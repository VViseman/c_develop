#include <stdio.h>
#include "euclid.h"

int main()
{
   int x, y, z;

   x = input_data();
   y = input_data();
   fprintf(stderr, "Inputed Data are %d and %d\n", x, y);

   z = euclid(x, y);
   output_data(z);

   return 0;
}