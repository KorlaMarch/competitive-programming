#include "stdio.h"
#include "algorithm"
#include "stdlib.h"
typedef struct node{
    int v,lh,rh,lc,rc;
    struct node *l,*r,*p;
}node;
node* getNode(int v){
    node* tmp = (node*)malloc(sizeof(node));
    tmp->v = v;
    tmp->lh = tmp->rh = -1;
    tmp->lc = tmp->rc = 0;
    tmp->l = tmp->r = tmp->p = NULL;
    return tmp;
}
int abs(int n){
    return n<0?-n:n;
}
void rotateC(node*& no){
    node* tmp = no;
    no = no->l;
    /*if(tmp->p){
        if(tmp->p->l == tmp) tmp->p->l = no;
        else tmp->p->r = no;
    }*/
    tmp->l = no->r;
    no->r = tmp;
    no->p = tmp->p;
    tmp->p = no;
    if(tmp->l) tmp->l->p = tmp;
    tmp->lh = no->rh;
    tmp->lc = no->rc;
    no->rh = std::max(tmp->lh,tmp->rh)+1;
    no->rc = tmp->lc+tmp->rc+1;
}
void rotateAC(node*& no){
    node* tmp = no;
    no = no->r;
    /*if(tmp->p){
        if(tmp->p->l == tmp) tmp->p->l = no;
        else tmp->p->r = no;
    }*/
    tmp->r = no->l;
    no->l = tmp;
    no->p = tmp->p;
    tmp->p = no;
    if(tmp->r) tmp->r->p = tmp;
    tmp->rh = no->lh;
    tmp->rc = no->lc;
    no->lh = std::max(tmp->lh,tmp->rh)+1;
    no->lc = tmp->lc+tmp->rc+1;
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
            no->rc++;
        }else{
            if(no->l==NULL){
                no->l = getNode(v);
                no->l->p = no;
                no->lh = 0;
            }else{
                no->lh = AVLins(no->l,v);
            }
            no->lc++;
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
void mergeG(node*& a, node*& b){
    if(b->l) mergeG(a,b->l);
    if(b->r) mergeG(a,b->r);
    AVLins(a,b->v);
    free(b);
}
int getRank(node* no, node* last){
    int sum = no->l==last?1+no->rc:0;
    if(no->p) return sum+getRank(no->p,no);
    else return sum;
}
node* searchALV(node* no, int k){
    if(no == NULL) return 0;
    else if(no->v == k) return no;
    else if(k > no->v) return searchALV(no->r,k);
    else return searchALV(no->l,k);
}
int t,n,l,i,j,x,y,k;
int p[100005];
node* g[100005];
node* tmp;
int union_find(int x){
    if(x==p[x]) return x;
    else return (p[x] = union_find(p[x]));
}

int main(){
    for(scanf("%d",&t); t > 0; t--){
        scanf("%d%d",&n,&l);
        for(i = 1; i <= n; i++){
            g[i] = getNode(i);
            p[i] = i;
        }
        for(i = 0; i < l; i++){
            scanf("%d",&k);
            if(k==1){
                scanf("%d%d",&x,&y);
                p[y] = x;
                mergeG(g[x],g[y]);
            }else{
                scanf("%d",&j);
                tmp = searchALV(g[union_find(j)],j);
                printf("%d\n",getRank(tmp,tmp->l));
            }
        }
    }
}
