#include "stdio.h"
#include "stdlib.h"
typedef struct node{
    int v;
    struct node *l,*r;
}node;
node* getNode(int v){
    node* tmp = (node*)malloc(sizeof(node));
    tmp->v = v;
    tmp->l = tmp->r = NULL;
    return tmp;
}
void insert(node* no, int v){
    if(v>=no->v){
        if(no->r==NULL){
            printf("R*\n");
            no->r = getNode(v);
        }else{
            putchar('R');
            insert(no->r,v);
        }
    }else{
        if(no->l==NULL){
            printf("L*\n");
            no->l = getNode(v);
        }else{
            putchar('L');
            insert(no->l,v);
        }
    }
}
int main(){
    int n,i,v;
    node* root;
    scanf("%d%d",&n,&v);
    root = getNode(v);
    printf("*\n");
    for(i = 1; i < n; i++){
        scanf("%d",&v);
        insert(root,v);
    }
}
