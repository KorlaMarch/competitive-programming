#include "stdio.h"

struct node{
    long long c,s;
    node *l,*r;
    node(long long _c = 0, long long _s = 0, node* _l = NULL, node* _r = NULL) : c(_c),s(_s),l(_l),r(_r) {}
};

bool isintersert(int x1, int y1, int x2, int y2){
    return (x2<=x1&&x1<=y2)||(x2<=y1&&y1<=y2)||(x1<=x2&&x2<=y1)||(x1<=y2&&y2<=y1);
}

int n,q,w,h,i,j,x,y,a,b,c,d;
node* segment[1001];
long long sm;

long long query(node*& no, int i, int j, int v, int x, int y){
    if(x<=i&&j<=y){
        if(no==NULL) no = new node(v,v*(j-i+1));
        else{
            no->c += v;
            no->s += v*(j-i+1);
        }
    }else if(isintersert(i,j,x,y)){
        if(no==NULL) no = new node();
        no->s = query(no->l,i,(i+j)/2,1,x,y) + query(no->r,(i+j)/2+1,j,1,x,y) + no->c*(j-i+1);
    }
    return no==NULL?0:no->s;
}

long long getSum(node*& no, int i, int j, int x, int y){
    //printf("GET %d %d : %d %d\n",i,j,x,y);
    if(no==NULL) return 0;
    else if(x<=i&&j<=y){
        //printf("1\n");
        return no->s;
    }else if(isintersert(i,j,x,y)){
        //printf("2\n");
        if(no->c!=0){
            if(no->l==NULL) no->l = new node();
            if(no->r==NULL) no->r = new node();
            no->l->c += no->c;
            no->l->s += no->c*((i+j)/2-i+1);
            no->r->c += no->c;
            no->r->s += no->c*(j-(i+j)/2);
            no->c = 0;
        }
        return getSum(no->l,i,(i+j)/2,x,y) + getSum(no->r,(i+j)/2+1,j,x,y);
    }else return 0;
}

int main(){
    scanf("%d%d%d%d",&n,&q,&w,&h);
    for(i = 0; i < n+q; i++){
        scanf("%d",&x);
        if(x==1){
            scanf("%d%d",&x,&y);
            query(segment[x],0,h,1,0,y);
        }else{
            scanf("%d%d%d%d",&a,&b,&c,&d);
            for(j = a,sm = 0; j <= c; j++){
                sm += getSum(segment[j],0,h,b+1,d);
            }
            printf("%lld\n",sm);
        }
    }

}
