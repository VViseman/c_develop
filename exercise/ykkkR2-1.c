#include <stdio.h>
#include <stdlib.h>

#define N 6

int GX = 4, GY = 1; /*Goal Point*/

int map[N][N] = {{-1, -1, -1, -1, -1, -1},
                 {-1,  0,  0, -1,  0, -1},
                 {-1, -1,  0, -1,  0, -1},
                 {-1,  0,  0,  0,  0, -1},
                 {-1,  0, -1,  0,  0, -1},
                 {-1, -1, -1, -1, -1, -1}};

int number = 1;

int inside(int x, int y){
    if(x < 0 || x >= N || y < 0 || y >= N){
        return -1;
    } else {
        return 1;
    }
};

void print_map(void) {
    int x, y;
    for (y = 0; y < N; y++) {
        for (x = 0; x < N; x++) {
            if (map[y][x] == -1) {
                printf(" . ");
            } else if (map[y][x] == 0) {
                printf("   ");
            } else {
                printf("%3d", map[y][x]);
            }
            printf("\n");
        }
    }
}

void search(int x, int y){
    if (inside(x, y)){
        if (map[x][y] == 0) {
            map[y][x] = number;
            number = number + 1;
            if (x == GX && y == GY){
                print_map();
                exit(0);
            }
//            search(x, y - 1); /* up    */
//            search(x + 1, y); /* right */
//            search(x, y + 1); /* down  */
//            search(x - 1, y); /* left  */

            search(x - 1, y); /* left  */
            search(x + 1, y); /* right */
            search(x, y + 1); /* down  */
            search(x, y - 1); /* up    */
        }
    }
}

int main(int argc, char *argv[]){

    search(1, 1);

    return 0;
}