int  euclid(int i, int j)
{
   while (i!=j) {
       if (i<j) {
           int swp = i;
           i = j;
           j = swp;
       }
       i = i - j;
   }
   return i;
}