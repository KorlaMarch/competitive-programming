#include "stdio.h"
#include "stdlib.h"

typedef struct node{
    char s[32];
    struct node* right;
    struct node* left;
}node;

int strcmp(char s[], char s2[]){
    int i;
    for(i = 0;s[i]||s2[i];i++){
        if(s[i]=='\0'){
            return -1;
        }else if(s2[i]=='\0'){
            return 1;
        }else if(s[i] < s2[i]){
            return -1;
        }else if(s[i] > s2[i]){
            return 1;
        }
    }
    return 0;
}

void ins(node* r, node* h){
    int i = strcmp(h->s,r->s);
    if(i==-1){
        if(r->left) ins(r->left,h);
        else r->left = h;
    }else if(i==1){
        if(r->right) ins(r->right,h);
        else r->right = h;
    }
}

void infix(node* r){
    if(r->left) infix(r->left);
    printf("%s\n",r->s);
    if(r->right) infix(r->right);
}

int main(){
    int n,i;
    node* root = (node*)malloc(sizeof(node));
    node* t;
    scanf("%d",&n);
    scanf(" %s",root->s);
    root->left = root->right = NULL;
    for(i=1;i<n; i++){
        t = (node*)malloc(sizeof(node));
        scanf(" %s", t->s);
        t->left = t->right = NULL;
        ins(root, t);
    }
    infix(root);
}
