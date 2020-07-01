#include <stdio.h>

#define ROWS  9  /* 盤面の行数 */
#define COLS  9  /* 盤面の列数 */
#define BROWS 3  /* ブロックの行数 */
#define BCOLS 3  /* ブロックの列数 */
#define CELLS ROWS*COLS  /* 盤面のマスの数 */
#define NUMS  9  /* 数字の種類 (1～9) */
#define EMPTY 0  /* マスの空白は0で表す */

/* 盤面を表示する */
void display(const int board[])
{
  int i;
  for( i = 0; i < CELLS; i++ ) {
    printf("%d", board[i]);
    if( i % NUMS == NUMS - 1 ) {
      printf("\n");
    }
    else {
      printf(",");
    }
  }
  printf("\n");
}

/* 数字が重複しているかどうか */
int isDuplicate(const int board[], int p, int k)
{
  int i, j, col, row, bRow, bCol;

  /* 同じ行に k がある */
  col = p % COLS;
  for( i = 0; i < ROWS; i++ ) {
    if( board[col+i*COLS] == k ) { return 1; }
  }

  /* 同じ列に k がある */
  row = p / COLS;
  for( j = 0; j < COLS; j++ ) {
    if( board[j+row*COLS] == k ) { return 1; }
  }

  /* 同じブロックに k がある */
  bRow = (row / BROWS) * BROWS;
  bCol = (col / BCOLS) * BCOLS;
  for( i = 0; i < BROWS; i++ ) {
    for( j = 0; j < BCOLS; j++ ) {
      if( board[(bCol+j)+(bRow+i)*COLS] == k ) { return 1; }
    }
  }  

  /* 重複していない */
  return 0;
}

/* 全ての解答を求める */
void solve(const int board_org[])
{
  int board[CELLS];
  int i, k, p;

  /* 盤面のコピー */
  for( i = 0; i < CELLS; i++ ) {
    board[i] = board_org[i];
  }

  p = 0;  /* 位置 */
  while(p >= 0) {

    /* ある解答が見つかった */
    if( p >= CELLS ) {
      /* 解答の表示 */
      display(board);
      /* 別の解答を探しに戻る */
      p--;
      while( board_org[p] != EMPTY ) { p--; }
    }

    /* 出題時点で数字が書かれていないマスのとき */
    if( board_org[p] == EMPTY ) {
      k = board[p];  
      if( k == EMPTY ) { k = 1; }
      while( isDuplicate(board, p, k) ) { k++; }
      /* 行き詰ったら戻ってやり直し */
      if( k > NUMS ) {
        board[p] = EMPTY;
        p--;
        while( board_org[p] != EMPTY ) { p--; }
      }
      /* マスに数字を入れて先に進む */
      else {
        board[p] = k;
        p++;
      }
    }
    /* 出題時点で数字が書かれたマスは素通り */
    else {
      p++;
    }
  }
}

int main()
{
  int board_org[] = {
/*
    0,0,9,4,0,0,1,0,0,
    4,0,3,0,0,0,0,5,0,
    0,6,0,0,0,3,0,0,0,
    0,0,6,0,4,0,7,2,0,
    3,0,0,2,0,8,0,0,5,
    0,2,1,0,0,0,3,0,0,
    0,0,0,9,7,0,0,0,0,
    7,4,0,0,0,0,6,0,9,
    0,0,2,0,0,1,4,0,0,
*/

/*
    1,0,0,0,0,7,0,9,0,
    0,3,0,0,2,0,0,0,8,
    0,0,9,6,0,0,5,0,0,
    0,0,5,3,0,0,9,0,0,
    0,1,0,0,8,0,0,0,2,
    6,0,0,0,0,4,0,0,0,
    3,0,0,0,0,0,0,1,0,
    0,4,0,0,0,0,0,0,7,
    0,0,7,0,0,0,3,0,0
*/

0,0,0,3,0,6,2,0,1,
0,0,6,8,5,0,9,4,0,
7,5,0,0,0,1,0,0,6,
1,0,0,0,9,0,4,7,0,
0,0,7,1,0,4,3,0,0,
0,3,4,0,2,0,0,0,5,
2,0,0,6,0,0,0,9,8,
0,7,5,0,8,9,1,0,0,
8,0,1,2,0,7,0,0,0


  };
  solve(board_org);

  return 0;
}
