#include "stdio.h"
#include "stdlib.h"

struct node{
    int data;
    struct node* next;
};

typedef struct node* nodeptr;

struct qu{
    nodeptr head;
};

typedef struct qu* queue;

int stuTable[10010] = {};

void insert(queue q, int data){
    nodeptr n = (nodeptr)malloc(sizeof(struct node));
    nodeptr p;
    n->data = data;

    if(q->head == NULL){
        n->next = NULL;
        q->head = n;
    }else{
        for(p = q->head; p->next != NULL && stuTable[p->data] != stuTable[data];p = p->next);
        for(; p->next != NULL && stuTable[p->next->data] == stuTable[data]; p = p->next);
        n->next = p->next;
        p->next = n;
    }
}

void del(queue q){
    nodeptr n = q->head;
    if(q->head == NULL){
        printf("empty\n");
    }else{
        printf("%d\n", q->head->data);
        q->head = q->head->next;
        free(n);
    }
}

int main(){
    int Nc, Ns;
    int i,j,k;
    char c;
    queue q = (queue)malloc(sizeof(struct qu));
    q->head = NULL;

    scanf("%d%d", &Nc, &Ns);
    for(i = 0; i < Ns; i++){
        scanf("%d%d", &j, &k);
        stuTable[k] = j;
    }

    while((c = getchar()) != 'X'){
        if(c == 'E'){
            scanf(" %d", &k);
            insert(q, k);
        }else if(c == 'D'){
            del(q);
        }
    }
    printf("0\n");
}
