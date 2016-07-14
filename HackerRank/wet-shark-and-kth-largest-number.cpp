#include "stdio.h"
#include "algorithm"
#include "vector"

struct node{
    int k;
    node *left,*right;
    node(int _k = 0, node* _left = NULL, node* _right = NULL) : k(_k), left(_left), right(_right) {}
};

bool isintersert(int x1, int y1, int x2, int y2){
    return (x2<x1&&x1<y2)||(x2<y1&&y1<y2)||(x1<x2&&x2<y1)||(x1<y2&&y2<y1);
}

struct segment{
    std::vector<node*> ver;
    int s;
    node* init_seg(int v, int l, int r){
        node* no = new node(v,NULL,NULL);
        if(l==r) return no;
        no->left = init_seg(v,l,(l+r)/2);
        no-> right = init_seg(v,(l+r)/2+1,r);
        return no;
    }
    segment(int n){
        s = n;
        ver.clear();
        ver.push_back(init_seg(0,0,n));
    }
    node* insert2(node* old, int vi, int x, int l, int r){
        if(l==r&&l==x){
            return new node(old->k+1);
        }else if(l<=x&&x<=r){
            node* no = new node(old->k+1);
            no->left = insert2(old->left,vi,x,l,(l+r)/2);
            no->right = insert2(old->right,vi,x,(l+r)/2+1,r);
            return no;
        }else return old;
    }
    void insert(int vi, int x){
        ver.push_back(insert2(vi,x,0,s));
    }
    int rmq(node* no, int x, int y, int l, int r){
        if(l<=x&&y<=r){

        }
        if(isintersert(x,y,)){

        }
    }
};

int n,q,l,k,i,j;
int a[100005];
int main(){
    scanf("%d%d",&n,&q);
    segment li(100000);
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
        li.insert(1,a[i]);
    }
}
