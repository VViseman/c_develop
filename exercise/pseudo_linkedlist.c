//リスト構造っていうのはあるデータに次のデータのアドレスが入っていて、そのまたあるデータにはその次のデータのアドレスが入っていて・・・、のように数珠つなぎになっているデータ構造になります。
//例えば配列にデータを詰める時、末尾にデータを追加する分には簡単ですが、先頭または途中にデータを挿入、後のデータを一つずつ後方にずらすなどの場合は大変な手間がかかりますよね
//動的にメモリを確保しながらリストを作り上げていくので、最後メモリを解放するまでがセットのプログラムになる

//配列[0]に必要なのは「データ」、「リストでの位置」なのでこれを表現したいので構造体で実装する。

#include <stdio.h>
#include <string.h>

#define MY_NULL -1
#define MAX_LIST 20

struct LIST {  //構造体
    char name[128];
    char num[128];
    int next;
    int flag;
};

struct LIST list[MAX_LIST];  // javaでいうインスタンスの作成

void init(void);
void add_tail(char *, char *);
void disp_list(void);
void disp_memory(void);
void free_list(void);
int my_malloc(void);
void my_free(int);

int head, tail;

int main() {
    //    int p, p2, p3;

    //    p = my_malloc();   //1番目を1にする  使用中のシグナル
    //    p2 = my_malloc();  // 2番目を1にする
    //    p3 = my_malloc();  // 3番目を1にする

    char input_name[128];
    char input_num[128];

    init();

    strcpy(input_name, "tanaka");  // input_nameに"tanaka"をコピー
    strcpy(input_num, "09011111111");  // input_numに"09011111111"をコピー

    add_tail(input_name, input_num); //

    strcpy(input_name, "saitou");
    strcpy(input_num, "09022222222");

    add_tail(input_name, input_num);

    strcpy(input_name, "watanabe");
    strcpy(input_num, "09033333333");

    add_tail(input_name, input_num);

    disp_list();

    printf("使用中のメモリ(使用中:1 未使用:0)\n");
    disp_memory();
    printf("\n\n");

    free_list();

    //    my_free(p);
    //    my_free(p2);
    //    my_free(p3);

    printf("使用中のメモリ(使用中:1 未使用:0)\n");
    disp_memory();  //配列の表示
    printf("\n");

    return 0;
}

//最初リストは空の状態なので先頭、末尾のアドレスを保存する変数
//「head,tail」も無効データ「MY_NULL」で初期化
void init() {
    head = MY_NULL;
    tail = MY_NULL;
}

//リストを末尾に追加する
void add_tail(char *input_name, char *input_num) {
    int p;

    p = my_malloc();  //未使用のメモリアドレスを保存。シグナルを1にしてその要素の番号をpに

    if (tail == MY_NULL) {  //リストが空の時 何も要素がないのでtails はMY_NULLになる
        head = p;  //「head,tail」両方に同じアドレスを設定する
    } else {
        list[tail].next = p;  //「list[tail]」の表す場所がそのリストの末尾にあたるので、その次「list[tail].next」に新しく確保したメモリ番号を保存
    }

    tail = p;  //「head,tail」両方に同じアドレスを設定する

    strcpy(list[tail].name, input_name);  //引数として受け取ったデータを保存
    strcpy(list[tail].num, input_num);  //引数として受け取ったデータを保存

    list[tail].next = MY_NULL;  //リストを辿る時の末尾の目印「MY_NULL」を設定
}

void disp_list() {
    int temp;
    int n = 0;
    temp = head;  //先頭アドレスを保存

    printf("\n名前　電話番号\n");
    while (temp != MY_NULL) {  //アドレスがリストの末尾を示す「MY_NULL」ではない間
        printf("%d:%s %s\n", n + 1, list[temp].name, list[temp].num);
        n++;
        temp = list[temp].next;  //その時のリストが保存している次のリストのアドレスと入れ替える
                                 //「MY_NULL」が来るまでひたすらリストを辿る
    }
}

void disp_memory() { //メモリの表示
    int i;
    for (i = 0; i < MAX_LIST; i++) {
        printf("[%d]", list[i].flag);
    }
}

void free_list() {  //メモリをすべて解放する
                    //そのリストが持っている次のアドレスの値を退避させながらメモリを解放してい
    int p;
    int p2;  //退避用変数
    p = head;
    while (p != MY_NULL) {
        p2 = list[p].next;  // list[p].nextをpに
        my_free(p);//メモリの開放
        p = p2;  //要素の番号を退避させたのでpに戻す
    }
    head = MY_NULL;
    tail = MY_NULL;
}

//実行すると
// i = 1 でbreak
// i = 2 でbreak
// i = 3 でbreak

int my_malloc() {  //メモリを確保 未使用[0]の要素を1にしてその要素の位置を渡す
    int i;
    for (i = 0; i < MAX_LIST; i++) {
        if (list[i].flag == 0) {
            list[i].flag = 1;
            break;
        }
    }
    return i;
}

void my_free(int num) {
    list[num].flag =
        0;  //引数にもらったアドレスのメモリを解放する シグナルを0にする
}