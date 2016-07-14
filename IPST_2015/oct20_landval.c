#include "stdio.h"
int n,m,a,b,c,d,e,i;
int fen[200002];

void addFen(int i, int v){
    for(;i<=n;i+=(i&-i)){
        fen[i] += v;
    }
}

int getFen(int i){
    int sum = 0;
    for(;i>0;i-=(i&-i)){
        sum += fen[i];
    }
    return sum;
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < m; i++){
        scanf("%d",&a);
        if(a==1){
            scanf("%d%d%d",&b,&c,&d);
            addFen(b,d);
            addFen(c+1,-d);
        }else{
            scanf("%d",&e);
            printf("%d\n",getFen(e));
        }
    }
}
