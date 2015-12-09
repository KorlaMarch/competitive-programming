#include "stdio.h"

int n,k,i,j,x,y,t,p;
int fen[200005];

void addFen(int i, int v){
    for(;i<=n;i += (i&-i)) fen[i] += v;
}

int getFen(int i){
    int sum;
    for(sum = i; i > 0; i -= (i&-i)) sum += fen[i];
    return sum;
}

int binaryS(int v){
    int x,y,m;
    for(x = 0, y = n-1; x <= y;){
        m = (y+x)/2;
        if(v<=getFen(m)){
            y = m-1;
        }else{
            x = m+1;
        }
    }
    return y+1;
}

int main(){
    scanf("%d%d",&n,&k);
    for(i = n,t=1; i > 0; i--){
        t = (t+k-2+i)%i+1;
        p = binaryS(t);
        //printf("%d : %d\n",t,p);
        addFen(p,-1);
        k = p;
    }
    printf("%d\n",p);
}
