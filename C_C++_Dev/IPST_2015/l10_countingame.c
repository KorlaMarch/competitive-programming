#include "stdio.h"

int n,i,j;
int ls[1020];
int isContain(int n, int a){
    while(n){
        if(n%10==a) return 1;
        n /= 10;
    }
    return 0;
}
int main(){
    scanf("%d",&n);
    ls[1] = 1;
    for(i = 1; i < n; i++){
        if(ls[i]){
            for(j = 2; j <= 5; j++){
                if((i+j)%j!=0&&!isContain(i+j,j)&&(ls[i+j]==0||ls[i]+1<ls[i+j])){
                    ls[i+j] = ls[i]+1;
                }
            }
        }
    }
    if(ls[n]){
        printf("%d\n",ls[n]-1);
    }else{
        printf("-1\n");
    }
}
