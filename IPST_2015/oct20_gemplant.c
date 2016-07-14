#include "stdio.h"
int n,m,i,a,b,c;
int fen[200001];
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
        scanf("%d %d%d",&a,&b,&c);
        if(a==1) addFen(c,b);
        else{
            printf("%d\n",getFen(c)-getFen(b-1));
        }
    }
}
