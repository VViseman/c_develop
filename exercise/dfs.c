#include <stdio.h>
#include <stdbool.h>

enum {S, A, B, C, D, E, F, G};

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
int path[N];
bool visited[N + 1];

// 経路の表示
void print_path(int n)
{
  for (int i = 0; i < n; i++)
    printf("%c ", 'A' + path[i] - 1);
  printf("\n");
}

// 深さ優先探索
void dfs(int n, int goal)
{
  int x = path[n - 1];
  if (x == goal) {
    print_path(n);
  } else {
    for (int i = 0; i < M; i++) {
      int y = adjacent[x][i];
      if (y == 0) break;
      if (!visited[y]) {
        path[n] = y;
        visited[y] = true;
        dfs(n + 1, goal);
        visited[y] = false;
      }
    }
  }
}

int main(void)
{
  path[0] = A;
  visited[A] = true;
  dfs(1, G);
  return 0;
}

