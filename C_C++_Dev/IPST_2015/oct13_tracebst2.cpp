#include "stdio.h"
#include "list"
#include "stdlib.h"
typedef struct node{
    std::list<int>* v;
    struct node *l,*r;
}node;
node* getNode(int v){
    node* tmp = (node*)malloc(sizeof(node));
    tmp->v = new std::list<int>();
    tmp->v->push_back(v);
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
    }else if(s[d]=='L'){
        if(no->l==NULL){
            no->l = getNode(v);
        }else{
            insert(no->l,d+1,v);
        }
    }else{
        no->v->push_back(v);
    }
}
void inorder(node* no){
    if(no->l!=NULL) inorder(no->l);
    for(std::list<int>::iterator it = no->v->begin(); it != no->v->end(); ++it){
        ans[*it] = c;
    }
    c++;
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
