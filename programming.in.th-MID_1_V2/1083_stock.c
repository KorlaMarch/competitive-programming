#include "stdio.h"
int n,q,i,a,b;
int pr[1000000];
int in[2];
int getPositive(int n){
    return n<0?0:n;
}
int main(){
    scanf("%d%d", &n, &in[0]);
    for(i = 1; i < n; i++){
        scanf("%d", &in[i%2]);
        pr[i] = pr[i-1]+ getPositive(in[i%2]-in[(i+1)%2]);
    }
    scanf("%d", &q);
    for(i = 0; i < q; i++){
        scanf("%d%d",&a,&b);
        printf("%d\n",pr[b-1]-pr[a-1]);
    }
}
