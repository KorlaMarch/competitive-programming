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
char s[100005];
int ans[100005];
int c;
void insert(node* no, int d, int v){
    if(s[d]=='R'){
        if(no->r==NULL){
            no->r = getNode(v);
        }else{
            insert(no->r,d+1,v);
        }
    }else{
        if(no->l==NULL){
            no->l = getNode(v);
        }else{
            insert(no->l,d+1,v);
        }
    }
}
void inorder(node* no){
    if(no->l!=NULL) inorder(no->l);
    ans[no->v] = c++;
    if(no->r!=NULL) inorder(no->r);
}
int main(){
    int n,i;
    node* root;
    scanf("%d %s",&n,s);
    root = getNode(0);
    for(i = 1; i < n; i++){
        scanf(" %s",s);
        insert(root,0,i);
    }
    c = 1;
    inorder(root);
    for(i = 0; i < n; i++) printf("%d\n",ans[i]);
}
