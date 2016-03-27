#include "stdio.h"

struct node{
    int c;
    node* l,r;
    node(int _c = 0, node* _l = NULL, node* _r = NULL) c(_c),l(_l),r(_r) {}
};

bool isintersert(int x1, int y1, int x2, int y2){
    return (x2<x1&&x1<y2)||(x2<y1&&y1<y2)||(x1<x2&&x2<y1)||(x1<y2&&y2<y1);
}

int n,q,w,h,i,j,x,y,a,b,c,d;
node* segment[1001];

void query(){

}

int main(){
    scanf("%d%d%d%d",&n,&q,&w,&h);
    for(i = 0; i < n+q; i++){
        scanf("%d",&qu[i][0]);
        if(qu[i][0]==1){
            scanf("%d%d",&x,&y);
        }else{
            scanf("%d%d%d%d",&a,&b,&c,&d);
        }
    }

}
