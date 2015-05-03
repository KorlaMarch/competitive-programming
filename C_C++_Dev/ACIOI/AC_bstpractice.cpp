#include "stdio.h"
#include "stdlib.h"

struct node{
    int data;
    struct node* lnode;
    struct node* rnode;
};

typedef struct node* nodeptr;

nodeptr addNode(nodeptr root, int data){
    nodeptr t;
    if(root == NULL){
        t = (nodeptr)malloc(sizeof(struct node));
        t->data = data;
        t->lnode = NULL;
        t->rnode = NULL;
        root = t;
    }else{
        if(data >= root->data){
            printf("R");
            root->rnode = addNode(root->rnode, data);
        }else{
            printf("L");
            root->lnode = addNode(root->lnode, data);
        }
    }

    return root;
}

int main(){
    int n,i,t;
    nodeptr root = NULL;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &t);
        root = addNode(root, t);
        printf("*\n");
    }
}
