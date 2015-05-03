#include "stdio.h"

int main(){
    int n,i,j,k,c;
    int prime[55];
    char isP[233]={};
    freopen("in.txt", "r", stdin);
    for(i = 2,k=0; i <= 232; i++){
        if(!isP[i]){
            prime[k++] = i;
            for(j = i+i; j <= 232; j += i){
                isP[j] = 1;
            }
        }
    }
    while(1){
        scanf("%d", &n);
        if(!n) break;
        printf("%d = ",n);
        if(n<0){
            n *= -1;
            printf("-1*");
        }
        for(i = c = 0; i < k&&n!=1; i++){
            while(n%prime[i]==0){
                if(c) printf("*%d", prime[i]);
                else{
                    printf("%d", prime[i]);
                    c = 1;
                }
                n /= prime[i];
            }
        }
        printf("\n");
    }
}
