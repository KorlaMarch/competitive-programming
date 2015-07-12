#include "stdio.h"
#include "stdlib.h"
typedef struct node{
    int num;
    struct node* next;
}node;
typedef node* nodeptr;
int n,k,i,j;
nodeptr head,t,t2;
int main(){
    scanf("%d%d",&n,&k);
    head = t = (nodeptr)malloc(sizeof(node));
    head->num = 1;
    for(i = 2; i <= n; i++){
        t->next = (nodeptr)malloc(sizeof(node));
        t = t->next;
        t->num = i;
    }
    t->next = head;
    for(i = n; i > 0; i--){
        for(j = (k-1)%i; j > 0; j--){
            t = t->next;
        }
        printf("%d\n",t->next->num);
        t2 = t->next;
        t->next = t->next->next;
        free(t2);
    }
}
