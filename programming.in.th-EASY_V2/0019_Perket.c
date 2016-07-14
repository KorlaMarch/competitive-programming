#include "stdio.h"
int n,min_d=2000000005;
int s[10],b[10];
int abs(int n){
    return n<0?n*-1:n;
}
void findP(int d,int sn,int bn){
    int i;
    if(abs(sn-bn) < min_d) min_d = abs(sn-bn);
    for(i = d; i < n; i++) findP(i+1, sn*s[i],bn+b[i]);
}
int main(){
    int i;
    scanf("%d",&n);
    for(i = 0; i < n; i++) scanf("%d%d",&s[i],&b[i]);
    for(i = 0; i < n; i++) findP(i+1,s[i],b[i]);
    printf("%d\n",min_d);
}
