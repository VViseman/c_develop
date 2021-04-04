#include <stdio.h>
#include <string.h>
#include <stdbool.h>

enum {S = 0, A, B, C, D, E, F, G};

#define N 7
#define M 4

// 隣接リスト
int adjacent[N + 1][M] = {
  {S},
  {B, C, S},
  {A, C, D, S},
  {A, B, E, S},
  {B, E, F, S},
  {C, D, G, S},
  {D, S},
  {E, S},
};

// 経路
typedef struct {
  int path[N];
  int len;
} Path;

// 現在地点を求める
int top(Path *p)
{
  return p->path[p->len - 1];
}

// 経路に頂点が含まれているか
bool visited(Path *p, int x)
{
  for (int i = 0; i < p->len; i++) {
    if (p->path[i] == x) return true;
  }
  return false;
}

// 経路の表示
void print_path(Path *p)
{
  for (int i = 0; i < p->len; i++)
    printf("%c ", 'A' + p->path[i] - 1);
  printf("\n");
}

// キュー
#define Q 64

Path buff[Q];
int  front, rear;

// 初期化
void init_queue(int start)
{
  buff[0].path[0] = start;
  buff[0].len = 1;
  rear = 1;
}

// データの取り出し
Path *deq(void)
{
  return &buff[front++];
}

// データの追加
void enq(Path *p, int x)
{
  buff[rear] = *p;
  buff[rear].path[p->len] = x;
  buff[rear++].len++;
}

// キューは空か
bool is_empty(void)
{
  return front == rear;
}

// 幅優先探索
void bfs(int start, int goal)
{
  init_queue(start);
  while (!is_empty()) {
    Path *p = deq();
    int x = top(p);
    if (x == goal) {
      print_path(p);
    } else {
      for (int i = 0; i < M; i++) {
        int y = adjacent[x][i];
        if (y == 0) break;
        if (!visited(p, y)) enq(p, y);
      }
    }
  }
}

int main(void)
{
  bfs(A, G);
  return 0;
}