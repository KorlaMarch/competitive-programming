#include "stdio.h"
#include "stdlib.h"

struct node{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node *NODEPTR;

NODEPTR getNode(){
    return (NODEPTR)malloc(sizeof(struct node));
}

NODEPTR maketree(int n){
    NODEPTR t = getNode();
    t->data = n;
    t->left = NULL;
    t->right = NULL;
    return t;
}

void setleft(NODEPTR p, int n){
    p->left = maketree(n);
}

void setright(NODEPTR p, int n){
    p->right = maketree(n);
}

void insTree(NODEPTR p, int x){
    if(x >= p->data){
        if(p->right == NULL){
            setright(p, x);
        }else{
            insTree(p->right, x);
        }
    }else{
        if(p->left == NULL){
            setleft(p, x);
        }else{
            insTree(p->left, x);
        }
    }
}

void preorderTra(NODEPTR p){
    printf("%d ", p->data);
    if(p->left != NULL) preorderTra(p->left);
    if(p->right != NULL) preorderTra(p->right);
}

void inorderTra(NODEPTR p){
    if(p->left != NULL) inorderTra(p->left);
    printf("%d ", p->data);
    if(p->right != NULL) inorderTra(p->right);
}

void inorderTraInv(NODEPTR p){
    if(p->right != NULL) inorderTraInv(p->right);
    printf("%d ", p->data);
    if(p->left != NULL) inorderTraInv(p->left);
}

void postorderTra(NODEPTR p){
    if(p->left != NULL) postorderTra(p->left);
    if(p->right != NULL) postorderTra(p->right);
    printf("%d ", p->data);
}

int main(){
    int i;
    int data[] = {5,10,5,3,8,6,1,9,12,1,-1};
    NODEPTR root = maketree(data[0]);
    for(i = 1; data[i] != -1; i++){
        insTree(root, data[i]);
    }

    printf("Pre : "); preorderTra(root); printf("\n");
    printf("In : "); inorderTra(root); printf("\n");
    printf("In2 : "); inorderTraInv(root); printf("\n");
    printf("Post : "); postorderTra(root); printf("\n");
}
