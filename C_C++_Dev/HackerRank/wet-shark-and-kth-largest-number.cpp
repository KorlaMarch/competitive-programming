#include "stdio.h"
#include "algorithm"
#include "vector"

struct node{
    int k,l,r;
    node *left,*right;
    node(int _k = 0, node* _left = NULL, node* _right = NULL) : k(_k), left(_left), right(_right) {}
};

bool isintersert(int x1, int y1, int x2, int y2){
    return (x2<x1&&x1<y2)||(x2<y1&&y1<y2)||(x1<x2&&x2<y1)||(x1<y2&&y2<y1);
}

struct segment{
    std::vector<node*> ver;
    void init_seg(node* &no, int v,int l, int r){
        if(l<=r)
        no = new node(v,NULL,NULL);
        init_seg(no->left,v,l,(l+r)/2);
        init_seg(no->right,v,,r);
    }
};

int n,q,l,k,i,j;
int a[100005];
segment li;
int main(){
    scanf("%d%d",&n,&q);
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
        li.insert(a[i]);
    }
}
