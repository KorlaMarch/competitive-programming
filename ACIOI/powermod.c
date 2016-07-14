#include "stdio.h"
int powermod(int a,int k,int m){
    int i;
    if(k==1) return a%m;
    i = powermod(a,k/2,m);
    return ((i*i)%m*(k%2?a%m:1))%m;
}
int main(){
    int a,k,m;
    scanf("%d%d%d",&a,&k,&m);
    printf("%d\n", powermod(a,k,m));
}
