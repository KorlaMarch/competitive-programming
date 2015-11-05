#include "stdio.h"
#include "stdlib.h"
typedef struct node{
    int v;
    struct node* next;
}node;
node* getNode(int v, node* next){
    node* tmp = (node*)malloc(sizeof(node));
    tmp->v = v;
    tmp->next = next;
    return tmp;
}
node* l[300002];
node *tmp,*ptr;
int p[300002];
int n,i,x,y;
int union_find(int x){
    if(x==p[x]) return x;
    else return p[x] = union_find(p[x]);
}
int main(){
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        l[i] = getNode(i,NULL);
        p[i] = i;
    }
    for(i = 1; i < n; i++){
        scanf("%d%d",&x,&y);
        tmp = l[y]->next;
        l[y]->next = l[x];
        for(ptr = l[x]; ptr->next != NULL; ptr = ptr->next);
        ptr->next = tmp;
        p[x] = p[y];
    }
    for(ptr = l[union_find(1)]; ptr != NULL; ptr = ptr->next){
        printf("%d ",ptr->v);
    }
}
