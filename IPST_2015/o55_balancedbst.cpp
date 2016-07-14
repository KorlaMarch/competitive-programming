#include "stdio.h"
#include "algorithm"
#include "stdlib.h"
typedef struct node{
    int v,lh,rh;
    struct node *l,*r,*p;
}node;
node* getNode(int v){
    node* tmp = (node*)malloc(sizeof(node));
    tmp->v = v;
    tmp->lh = tmp->rh = -1;
    tmp->l = tmp->r = tmp->p = NULL;
    return tmp;
}
int abs(int n){
    return n<0?-n:n;
}
void rotateC(node*& no){
    node* tmp = no;
    no = no->l;
    tmp->l = no->r;
    no->r = tmp;
    no->p = tmp->p;
    tmp->p = no;
    tmp->lh = no->rh;
    no->rh = std::max(tmp->lh,tmp->rh)+1;
}
void rotateAC(node*& no){
    node* tmp = no;
    no = no->r;
    tmp->r = no->l;
    no->l = tmp;
    no->p = tmp->p;
    tmp->p = no;
    tmp->rh = no->lh;
    no->lh = std::max(tmp->lh,tmp->rh)+1;
}
int AVLins(node*& no, int v){
    if(no==NULL){
        no = getNode(v);
    }else{
        if(v>=no->v){
            if(no->r==NULL){
                no->r = getNode(v);
                no->r->p = no;
                no->rh = 0;
            }else{
                no->rh = AVLins(no->r,v);
            }
        }else{
            if(no->l==NULL){
                no->l = getNode(v);
                no->l->p = no;
                no->lh = 0;
            }else{
                no->lh = AVLins(no->l,v);
            }
        }
        if(abs(no->lh-no->rh)>=2){
            if(no->lh>no->rh){
                if(no->l->rh > no->l->lh){
                    rotateAC(no->l);
                }
                rotateC(no);
            }else{
                if(no->r->lh > no->r->rh){
                    rotateC(no->r);
                }
                rotateAC(no);
            }
        }
    }
    return std::max(no->lh,no->rh)+1;
}
int searchALV(node* no, int k){
    if(no == NULL) return 0;
    else if(no->v == k) return 1;
    else if(k > no->v) return searchALV(no->r,k);
    else return searchALV(no->l,k);
}
int n,m,i,x;
node* root;
int main(){
    root=NULL;
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf("%d",&x);
        AVLins(root,x);
    }
    for(i = 0; i < m; i++){
        scanf("%d",&x);
        if(searchALV(root,x)) printf("y\n");
        else printf("n\n");
    }
}
