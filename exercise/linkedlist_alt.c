#include <stdio.h>
#include <stdlib.h>

typedef struct mynode{
    int value;
    struct mynode *next;
}MYNODE;

/*リストの全要素を列挙する関数*/
void printList(MYNODE* head){
    MYNODE* now_node;
    for(now_node=head->next;now_node!=NULL;now_node=now_node->next){
        printf("%d\n",now_node->value);
    }
}

/*リストの末尾に新しいノードを追加する関数*/
void addList(MYNODE* head,int value){
    MYNODE* prev_node;
    MYNODE* new_node;

    /*リスト末尾まで進める*/
    prev_node=head;
    while(prev_node->next!=NULL){
        prev_node=prev_node->next;
    }

    /*新しいノードを作成*/
    new_node=(MYNODE*)malloc(sizeof(MYNODE));
    new_node->value=value;
    new_node->next=NULL;

    /*新しいノードを末尾に連結*/
    prev_node->next=new_node;
}

/*リストの指定位置(0から始まるindex)に新しいノードを挿入する関数*/
/*  指定されたindexがリスト要素数に比べて多い場合、末尾に追加する*/
/*  参考：head→ノード0番→ノード1番→・・・→NULL*/
void insertList(MYNODE* head,int value,int index){
    int ctr=0;
    int i;
    MYNODE* prev_node=head;
    MYNODE* next_node=NULL;
    MYNODE* new_node;

    /*指定位置まで進める*/
    for(i=0;i<index;i++){
        if(prev_node==NULL){
            /*指定位置に到達する前にリストが終わったので末尾に追加*/
            addList(head,value);
            return;
        }
        prev_node=prev_node->next;
    }
    next_node=prev_node->next;

    /*新しいノードを作成*/
    new_node=(MYNODE*)malloc(sizeof(MYNODE));
    new_node->value=value;

    /*挿入*/
    new_node->next=next_node;
    prev_node->next=new_node;
}

/*リスト指定位置の要素を削除する*/
void deleteList(MYNODE* head,int index){
    MYNODE* prev_node=head;
    MYNODE* now_node;
    int i;

    /*指定位置まで進める*/
    for(i=0;i<index;i++){
        if(prev_node==NULL){
            /*指定位置に要素はない*/
            printf("指定された位置にノードが存在しません。\n");
            return;
        }
        prev_node=prev_node->next;
    }
    now_node=prev_node->next;
    if(now_node==NULL){
        /*指定位置に要素はない*/
        printf("指定された位置にノードが存在しません。\n");
        return;
    }

    /*消すノードの直前と直後をつなぐ*/
    prev_node->next=now_node->next;
    /*ノードを消す*/
    free(now_node);
    return;
}

/*リストの要素をすべて削除する*/
void destroyList(MYNODE* head){
    MYNODE* now_node;

    while(head->next!=NULL){
        now_node=head->next;
        head->next=now_node->next;
        free(now_node);
    }
}

int main(void){
    MYNODE head;
    head.next=NULL;

    /*ノードを追加する → [0,1,2,3,4]*/
    addList(&head,0);
    addList(&head,1);
    addList(&head,2);
    addList(&head,3);
    addList(&head,4);
    printList(&head);
    printf("-----------------\n");

    /*ノードを挿入する → [0,1,2,5,3,4]*/
    insertList(&head,5,3);
    printList(&head);
    printf("-----------------\n");

    /*ノードを削除する → [1,3]*/
    deleteList(&head,0);/*0番目の要素である0を削除 → [1,2,5,3,4]*/
    deleteList(&head,1);/*1番目の要素である2を削除 → [1,5,3,4]*/
    deleteList(&head,1);/*1番目の要素である5を削除 → [1,3,4]*/
    deleteList(&head,2);/*2番目の要素である4を削除 → [1,3]*/
    printList(&head);
    printf("-----------------\n");

    /*リストの中身を全部削除*/
    destroyList(&head);
    printList(&head);
    printf("-----------------\n");

    return 0;
}