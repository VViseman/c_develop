#include <stdio.h>

char f[5][6] = {"acaxx", "cccxx", "bbxax", "bbxdd", "adxxb"};

void print(){
    int i, j;
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            printf("%c" , f[i][j]);
        }
    printf("\n");
    }
    printf("\n");
}

void replace(char ch, char ch2){
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (f[i][j] == ch)
            {
                f[i][j] = ch2;
            }
        }
    }
}

int count (char ch){
    int i, j, c = 0;
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            if (f[i][j] == ch){
                c++;
            }
        }
    }
    return c;
}

void fall(){
    int i, j, k;
    for (i = 0; i < 5; i++){
        for (j = 0, k = 0; j < 5; j++, k++){
            while(f[i][k] == 'x' && k < 5){ //f[i][k]がxでなく、kが5より小さい間
                k++;
            }
            printf("%d\n", k);
            if (k < 5){
                f[i][j] = f[i][k];
                //printf("%d\n", k);
                //printf("f[i][j] %c\n", f[i][j]);
                //printf("f[i][k] %c\n", f[i][k]);
            } else {
                f[i][j] = 'x';
            }
        }
//        printf("k %d\n", k);
//        printf("j %d\n", j);
    }
}

//[][6] space

void del(int x, int y, char orig){
    if(f[y][x] == orig){
        f[y][x] = 'z';
        if(0 < x) {
            del(x - 1, y, orig);
        }
        if(x < 4) {
            del(x + 1, y, orig);
        }
        if (0 < y){
            del(x, y - 1, orig);
        }
        if (y < 4){
            del(x , y + 1, orig);
        }
    }
}

int main(int argc, char *argv[])
{
    print();  //a

    fall();
    print();  //b

/*    char orig = f[2][1];
    printf("%c\n", orig); //c
    del(1, 2, orig);
    print();  //d

    if(count('z') >= 4){
        replace('z', 'x');
    } else {
        replace('z', orig);
    }
    print(); //e

    fall();
    print(); //f
*/
    return 0;
}
