#include "stdio.h"
#include "stdlib.h"

typedef struct node{
    int num;
    struct node* l;
    struct node* r;
}node;

node* newNode(int i){
    node* n;
    printf("*\n");
    n = (node*)malloc(sizeof(node));
    n->num = i;
    n->l = n->r = NULL;
    return n;
}

void insert(node* n, int i){
    if(i >= n->num){
        printf("R");
        if(n->r == NULL) n->r = newNode(i);
        else insert(n->r,i);
    }else{
        printf("L");
        if(n->l == NULL) n->l = newNode(i);
        else insert(n->l,i);
    }
}

int main(){
    int n,i,x;
    node* root;
    scanf("%d%d",&n,&x);
    root = newNode(x);
    for(i=1;i<n;i++){
        scanf("%d",&x);
        insert(root,x);
    }
}
