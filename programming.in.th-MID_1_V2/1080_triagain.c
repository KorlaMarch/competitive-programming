#include "stdio.h"
int n,i,j,x,m;
int st[501];
int getM(int n){
    for(n++; !(st[n]-st[n-1])&&n<=500; n++);
    return n;
}
int main(){
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d",&x);
        st[x]++;
    }
    for(i = 1; i<=500; i++){
        st[i] += st[i-1];
    }
    for(i = 1; i <= 500; i++){
        for(j = i; j <= 500; j++){
            if(st[i]-st[i-1]&&i+i>j&&st[j]-st[i-1]>m){
                m = st[j]-st[i-1];
            }else if(st[i]-st[i-1]&&i+getM(i)>j&&st[j]-st[i]+1>m){
                m = st[j]-st[i]+1;
            }
        }
    }
    printf("%d\n",m);
}
