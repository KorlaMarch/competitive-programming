#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "math.h"

#define DEBUG 0

//////////////////////// Queue ////////////////////////
typedef struct node *nodeptr;
typedef struct queue *queueptr;

struct node{
    int table[9];
    int sum;
    struct node *parent;
    struct node *next;
};

struct queue{
    nodeptr front;
    nodeptr rear;
    int size;
};

nodeptr getNode(){
    return (nodeptr)malloc(sizeof(struct node));
}

queueptr createQueue(){
    queueptr q = (queueptr)malloc(sizeof(struct node));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(queueptr q, nodeptr parent, int t[]){
    nodeptr p = getNode();
    int sum = 0;
    for(int i = 0; i < 9; i++){
        sum += pow(10, i)*t[i];
        p->table[i] = t[i];
    }
    p->sum = sum;
    p->parent = parent;
    p->next = NULL;
    if(q->size > 0) q->rear->next = p;
    q->rear = p;
    q->size++;
    if(q->front == NULL){
        q->front = q->rear;
    }
}

struct node dequeue(queueptr q){
    nodeptr p = q->front;
    struct node re = *p;
    q->front = q->front->next;
    free(p);
    q->size--;
    return re;
}

struct node front(queueptr q){
    return *q->front;
}

////////////////////////////////////////////////////
//////////////////////// Al ////////////////////////

int win[] = {1,2,3,
             4,5,6,
             7,8,0};

// q = running list
queueptr q;

queueptr exilist;

int checkMatch(int t[], int j[]){
    for(int i = 0; i < 9; i++){
        if(t[i] != j[i]){
            return 0;
        }
    }
    return 1;
}

int getSum(int table[]){
    int sum = 0;
    for(int i = 0; i < 9; i++){
        sum += pow(10, i)*table[i];
    }
    return sum;
}

int checkMatchInList(int i[]){
    nodeptr ptr;
    int s = getSum(i);
    for(ptr = q->front; ptr != NULL; ptr = ptr->next){
        if(s == ptr->sum){
        //if(checkMatch(i, ptr->table)){
            return 1;
        }
    }
    return 0;
}



int checkWin(int t[]){
    return checkMatch(t, win);
}

void copyArray(int dis[], int so[]){
    for(int i = 0; i < 9; i++){
        dis[i] = so[i];
    }
}

void printData(nodeptr ptr){
    if(ptr == NULL) return;
    if(DEBUG){
    printf("ptr : %p p : %p\n", ptr, ptr->parent);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", ptr->table[i*3 + j]);
        }
        printf("\n");
    }
    printf("\n\n");
    getch();
    }
    printData(ptr->parent);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", ptr->table[i*3 + j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void enqueueEX(queueptr q, nodeptr parent, int t[]){
    if(!checkMatchInList(t)){
        enqueue(q, parent, t);
    }
}

void caluResule(int table[]){
    nodeptr no;
    int temp[9];
    q = createQueue();
    exilist = createQueue();
    //printf("call2");
    enqueue(exilist, NULL, table);
    //printf("call3");
    while(exilist->size > 0){
        //if(DEBUG) getch();
        no = exilist->front;
        if(DEBUG){
        nodeptr t = exilist->front;
        for(nodeptr t = exilist->front; t != NULL; t = t->next){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                printf("%d ", t->table[i*3 + j]);
            }
            printf("\n");
        }
        printf("\n");
        }
        printf(" size : %d\n", q->size);
        }
        if(checkWin(no->table)){
            printf("Finding!\n");
            printf("Looking Up...\n");
            printData(no);
            break;
        }else /*if(!checkMatchInList(no->table))*/{
            int i;
            for(i = 0; no->table[i] != 0; i++);
            enqueue(q, no->parent, no->table);
            no = q->rear;
            if(DEBUG) printf("parent = %p ,ptr = %p data = %d\n", no->parent, no, getSum(no->table));
            dequeue(exilist);
            if(i >= 3){
                copyArray(temp, no->table);
                temp[i] = temp[i] ^ temp[i-3];
                temp[i-3] = temp[i] ^ temp[i-3];
                temp[i] = temp[i] ^ temp[i-3];
                enqueueEX(exilist, no, temp);
                if(DEBUG) printf("en1\n");
            }

            if(i < 6){
                copyArray(temp, no->table);
                temp[i] = temp[i] ^ temp[i+3];
                temp[i+3] = temp[i] ^ temp[i+3];
                temp[i] = temp[i] ^ temp[i+3];
                enqueueEX(exilist, no, temp);
                if(DEBUG) printf("en2\n");
            }

            if(i % 3 != 0){
                copyArray(temp, no->table);
                temp[i] = temp[i] ^ temp[i-1];
                temp[i-1] = temp[i] ^ temp[i-1];
                temp[i] = temp[i] ^ temp[i-1];
                enqueueEX(exilist, no, temp);
                if(DEBUG) printf("en3\n");
            }

            if(i % 3 != 2){
                copyArray(temp, no->table);
                temp[i] = temp[i] ^ temp[i+1];
                temp[i+1] = temp[i] ^ temp[i+1];
                temp[i] = temp[i] ^ temp[i+1];
                enqueueEX(exilist, no, temp);
                if(DEBUG) printf("en4\n");
            }
        }
        if(DEBUG) printf("===============\n");
    }
}


//////////////////////////////////////////////////

int main(){
    int n[9];
    for(int i = 0; i < 9; i++){
        scanf("%d", &n[i]);
    }
    //printf("call");
    caluResule(n);
}
