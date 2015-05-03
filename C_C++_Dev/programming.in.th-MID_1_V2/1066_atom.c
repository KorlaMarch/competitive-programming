#include "stdio.h"
#include "stdlib.h"

typedef struct node{
    int x;
    struct node* next;
}node;

node* getNode(int x){
    node *t = (node*)malloc(sizeof(node));
    t->x = x;
    t->next = NULL;
    return t;
}

int abs(int n){
    return n<0?n*-1:n;
}

int main(){
    int n,i,x,maxV,sum;
    node *root=getNode(-1),*tmp,*maxN;
    scanf("%d",&n);
    for(i = 0,tmp=root; i < n; i++){
        scanf("%d",&x);
        tmp->next = getNode(x);
        tmp = tmp->next;
    }
    n /= 2;
    for(i=0,sum=0; i < n; i++){
        for(tmp = root,maxV=0; tmp->next->next != NULL; tmp = tmp->next){
            if(abs(tmp->next->x-tmp->next->next->x)>maxV){
                maxV = abs(tmp->next->x-tmp->next->next->x);
                maxN = tmp;
            }
        }
        sum += maxV;
        tmp = maxN->next;
        maxN->next = maxN->next->next->next;
        free(tmp->next);
        free(tmp);
    }
    printf("%d\n", sum);
}
