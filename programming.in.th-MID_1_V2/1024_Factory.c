#include "stdio.h"
int diff(int a, int b, int c){
    if(a>=b&&a>=c){
        if(b<c){
            return a-b;
        }else{
            return a-c;
        }
    }else if(b>=a&&b>=c){
        if(a<c){
            return b-a;
        }else{
            return b-c;
        }
    }else{
        if(a<b){
            return c-a;
        }else{
            return c-b;
        }
    }
}
int main(){
    int fac[1000],n,i,j,a,mi,mj,m=3000000;
    scanf("%d%d", &n,&fac[0]);
    for(i = 1; i < n; i++){
        scanf("%d", &fac[i]);
        fac[i] += fac[i-1];
    }
    for(i = 1; i < n; i++){
        for(j = i+1; j < n; j++){
            a = diff(fac[i-1], fac[j-1]-fac[i-1],fac[n-1]-fac[j-1]);
            if(a < m){
                mi = i;
                mj = j;
                m = a;
            }
        }
    }
    printf("%d %d\n",mi+1,mj+1);
}
