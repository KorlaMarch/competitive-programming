#include "stdio.h"
#include "stdlib.h"
typedef struct node{
    int a,s;
    struct node* next;
}node;
typedef struct{
    node* front;
    node* last;
}queue;
typedef struct nodeL{
    queue q;
    struct nodeL* next;
}nodeL;

int n,m,i,j,ai,li,si,ms,ma;
queue q[10000];
node* t;
nodeL *root,*ln,*tmp;
void enq(int Nq, int a, int s){
    node* t = (node*)malloc(sizeof(node));
    t->a = a;
    t->s = s;
    t->next = NULL;
    if(q[Nq].front==NULL){
        q[Nq].front = q[Nq].last = t;
    }else{
        q[Nq].front->next = t;
        q[Nq].front = t;
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(i = 0; i < m; i++){
        q[i].front = q[i].last = NULL;
    }
    for(i = 0; i < n; i++){
        scanf("%d%d%d", &ai, &li, &si);
        enq(li-1, ai, si);
    }
    root = ln = NULL;
    for(i = 0; i < m; i++){
        if(q[i].last!=NULL){
            tmp = (nodeL*) malloc(sizeof(nodeL));
            tmp->q = q[i];
            tmp->next = NULL;
            if(root == NULL){
                root = tmp;
                ln = tmp;
            }else{
                ln->next = tmp;
                ln = tmp;
            }
        }
    }
    while(root!=NULL){
        for(ln = root, ms = 0; ln != NULL; ln = ln->next){
            while(ln->next != NULL && ln->next->q.last == NULL){
                tmp = ln->next;
                ln->next = ln->next->next;
                free(tmp);
            }
            if(ln->q.last->s > ms){
                ma = ln->q.last->a;
                ms = ln->q.last->s;
            }
            t = ln->q.last;
            ln->q.last = ln->q.last->next;
            free(t);
        }
        while(root!=NULL&&root->q.last == NULL){
            root = root->next;
        }
        printf("%d\n", ma);
    }
}
