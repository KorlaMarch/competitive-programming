#include "stdio.h"

int w[4],u[4],s[4];
int min(int a,int b){
    return a<b?a:b;
}
int max(int a,int b){
    return a>b?a:b;
}
int findRec(int n){
    int m=0,i;
    if(n==4){
        return min(w[0],w[2])*min(w[1],w[3]);
    }
    for(i = 0; i < 4; i++){
        if(!u[i]){
            u[i]=1;
            w[n] = s[i];
            m = max(m,findRec(n+1));
            u[i]=0;
        }
    }
    return m;
}
int main(){
    scanf("%d%d%d%d",&s[0],&s[1],&s[2],&s[3]);
    printf("%d\n",findRec(0));
}
