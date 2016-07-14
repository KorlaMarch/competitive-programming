#include "stdio.h"
#include "algorithm"

struct node{
    int v,lv;
    node *l,*r,*p;
    node(int _v = 0, int _lv = 0, node* _l = NULL, node* _r = NULL, node* _p = NULL) : v(_v),lv(_lv),l(_l),r(_r),p(_p) {}
};

int n,q,i,j,o,x,a,b,c;
node* st;

void clearLazy(node* no){
    if(no->lv){
        no->v += no->lv;
        if(no->r) no->r->lv += no->lv;
        if(no->l) no->l->lv += no->lv;
        no->lv = 0;
    }
}

void rotateR(node* no){
    if(!no->l) printf("ERROR R\n");
    clearLazy(no);
    if(no->l) clearLazy(no->l);
    if(no->p){
        if(no==no->p->l) no->p->l = no->l;
        else no->p->r = no->l;
    }
    no->l->p = no->p;
    no->p = no->l;
    no->l = no->p->r;
    if(no->l) no->l->p = no;
    no->p->r = no;
    //no = no->l;
}

void rotateL(node* no){
    if(!no->r) printf("ERROR L\n");
    clearLazy(no);
    if(no->r) clearLazy(no->r);
    if(no->p){
        if(no==no->p->l) no->p->l = no->r;
        else no->p->r = no->r;
    }
    no->r->p = no->p;
    no->p = no->r;
    no->r = no->p->l;
    if(no->r) no->r->p = no;
    no->p->l = no;
    //no = no->r;
}

void splay(node*& st, node* no){
    while(no->p){
        if(no==no->p->l){
            if(no->p->p&&no->p==no->p->p->l){
                rotateR(no->p->p);
            }
            rotateR(no->p);
        }else if(no==no->p->r){
            if(no->p->p&&no->p==no->p->p->r){
                rotateL(no->p->p);
            }
            rotateL(no->p);
        }else printf("ERROR : Splay\n");
    }
    st = no;
}

void insertN(node*& no, node* p, int v){
    if(no==NULL){
        no = new node(v,0,NULL,NULL,p);
        splay(st,no);
    }else if(v<no->v){
        insertN(no->l,no,v);
    }else{
        insertN(no->r,no,v);
    }
}

int countNO(node* no){
    if(no==NULL) return 0;
    else return 1+countNO(no->l)+countNO(no->r);
}

bool querry(node* no, int x){
    if(no==NULL) return false;
    clearLazy(no);
    //printf("TAR %d : %d\n",no->v,x);
    if(no->v==x){
        splay(st,no);
        return true;
    }else if(x<no->v){
        return querry(no->l,x);
    }else{
        return querry(no->r,x);
    }
}
node* findLMost(node* no){
    clearLazy(no);
    return no->l==NULL?no:findLMost(no->l);
}

bool checkTree(node* no, int op){
    if(no==NULL) return true;
    op += no->lv;
    if(no->p){
        if(no!=no->p->l&&no!=no->p->r) printf("Error at P\n");
    }
    if(no->l){
        if(no->l->v+no->l->lv>=no->v) printf("Error at L (%d %d)\n",no->v+op,no->l->v+no->l->lv+op);
        checkTree(no->l,op);
    }
    if(no->r){
        if(no->r->v+no->r->lv<no->v) printf("Error at R (%d %d)\n",no->v+op,no->r->v+no->r->lv+op);
        checkTree(no->r,op);
    }
}
int main(){
    scanf("%d%d",&n,&q);
    st = NULL;
    node* tmp;
    for(i = 0; i < n; i++){
        scanf("%d",&x);
        insertN(st,NULL,x);
    }
    for(i = 0; i < q; i++){
        scanf("%d",&o);
        if(o==1){
            scanf("%d",&x);
            printf("%d\n",querry(st,x));
        }else{
            scanf("%d%d%d",&a,&b,&c);
            if(querry(st,a)){
                st->v += c;
                if(st->l) st->l->lv += b;
                if(st->r) st->r->lv += c;
                if(st->l){
                    tmp = findLMost(st->l);
                    st->l->p = NULL;
                    splay(st->l,tmp);
                    tmp = st->l;
                    if(tmp->l) printf("ERROR : Cant Merge\n");
                    tmp->l = st;
                    //printf("TMP = %d %d\n",tmp->v,tmp->lv);
                    st->p = tmp;
                    st->l = NULL;
                    st = tmp;
                }
            }
        }
        //checkTree(st,0);
        //printf("COUNT = %d\n", countNO(st));
    }
}
