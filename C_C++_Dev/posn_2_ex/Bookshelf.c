#include "stdio.h"
#include "stdlib.h"

/*
TASK: Bookshelf
AUTHOR: Khemarat Boonyapaluk
CENTER: Samsenwittayalai
PROGRAM : Code::Block 12.11
*/

struct node{
    int data;
    struct node* next;
};

typedef struct node* nodeptr;

struct list{
    int size;
    nodeptr rear;
};

typedef struct list* linkedList;

void insert(linkedList l, int data){
    nodeptr n = (nodeptr)malloc(sizeof(struct node));
    n->data = data;

    if(l->rear == NULL){
        l->rear = n;
        n->next = NULL;
    }else{
        n->next = l->rear;
        l->rear = n;
    }
    l->size++;
}

int del(linkedList l, int k){
    int i;
    nodeptr n, n2;
    if(l->rear == NULL){
        printf("Empty\n");
        return -1;
    }
    if(k == l->size){
        n = l->rear;
        l->rear = n->next;
        i = n->data;
        free(n);
    }else{
        for(i = l->size-1, n = l->rear; i != k && i >= 0; i--){
            n = n->next;
        }
        if(i <= -1){
            printf("Error!\n");
            return -1;
        }
        i = n->next->data;
        n2 = n->next;
        n->next = n->next->next;
        free(n2);
    }
    l->size--;
    return i;
}

void delAll(nodeptr n){
    if(n == NULL){
        return;
    }
    delAll(n->next);
    free(n);
}

int main(){
    int fcount,i,n,m,x,y;
    linkedList l = (linkedList)malloc(sizeof(struct list));
    char inname[15];
    char outname[15];
    for(fcount = 0; fcount < 3; fcount++){
        sprintf(inname,"input%d.txt", fcount);
        sprintf(outname,"output%d.txt", fcount);
        freopen(inname, "r", stdin);
        freopen(outname, "w+", stdout);

        l->rear = NULL;
        l->size = 0;
        scanf("%d", &m);
        for(i = 0; i < m; i++){
            scanf("%d", &x);
            insert(l, x);
        }
        scanf("%d", &n);
        for(i = 0; i < n; i++){
            scanf("%d", &x);
            printf("%d\n", del(l, x));
        }

        delAll(l->rear);
    }
}
