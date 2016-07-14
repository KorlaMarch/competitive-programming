#include "stdio.h"
int n,c,x,y,a,l,b,r,t;
int fen[1025][1025];

void addFen(int x, int y, int v){
    int i,j;
    for(i = x;i<=n;i+=(i&-i)){
        for(j = y; j<=n; j+=(j&-j)){
            fen[i][j] += v;
        }
    }
}

int getFen(int x, int y){
    int i,j,sum=0;
    for(i = x; i>0; i-=(i&-i)){
        for(j = y; j>0; j-=(j&-j)){
            sum += fen[i][j];
        }
    }
    return sum;
}

int main(){
    while(1){
        scanf("%d",&c);
        if(c==0){
            scanf("%d",&n);
        }else if(c==1){
            scanf("%d%d%d",&x,&y,&a);
            addFen(x+1,y+1,a);
        }else if(c==2){
            scanf("%d%d%d%d",&l,&b,&r,&t);
            printf("%d\n",getFen(r+1,t+1)-getFen(r+1,b)-getFen(l,t+1)+getFen(l,b));
        }else{
            break;
        }
    }
}
