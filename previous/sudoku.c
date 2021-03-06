#include <stdio.h>
 
#define N 9
#define B 3 //square root of N
 
int canBePlaced(int board[], int pos, int x)
{
  int row=pos/N;
  int col=pos%N;
  int i, j, topLeft;
  for (i=0; i<N; ++i) {
    if (board[row*N+i]==x) return 0;
    if (board[col+i*N]==x) return 0;
  }
  topLeft=N*(row/B)*B+(col/B)*B;
  for (i=0; i<B; ++i) {
    for (j=0; j<B; ++j) {
      if (board[topLeft+i*N+j]==x) return 0;
    }
  }
  return 1;
}
 
void check(int board[], int pos)
{
  int i, x, newPos;
 
  //Solution is found.
  if (pos==N*N) {
    for (i=0; i<N*N; ++i) {
      printf("%d ", board[i]);
      if (i%N==N-1) printf("\n");
    }
    printf("\n");
    return;
  }
 
  //Find a blank.
  for (newPos=pos; newPos<N*N; ++newPos) {
    if (board[newPos]==0) break;
  }
 
  //Check recursively.
  for (x=1; x<=N; ++x) {
    if (canBePlaced(board, newPos, x)) {
      board[newPos]=x;
      check(board, newPos+1);
      board[newPos]=0;//backtracking
    }
  }
}
 
int main()
{
  int board[]={
    1,0,0,0,0,7,0,9,0,
    0,3,0,0,2,0,0,0,8,
    0,0,9,6,0,0,5,0,0,
    0,0,5,3,0,0,9,0,0,
    0,1,0,0,8,0,0,0,2,
    6,0,0,0,0,4,0,0,0,
    3,0,0,0,0,0,0,1,0,
    0,4,0,0,0,0,0,0,7,
    0,0,7,0,0,0,3,0,0};
  check(board, 0);
  return 0;
}


/*
    0,0,0,7,4,0,0,1,5,
    0,5,0,1,0,0,6,7,3,
    0,0,0,0,0,0,8,0,9,
    1,2,8,3,6,7,5,9,0,
    0,0,0,2,0,4,0,0,0,
    3,0,5,0,9,0,7,6,2,
    8,3,9,0,0,6,0,2,1,
    0,0,4,0,0,0,0,8,0,
    2,7,1,4,3,8,9,5,6};*/

