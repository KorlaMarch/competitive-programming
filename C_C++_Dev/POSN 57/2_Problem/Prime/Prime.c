#include "stdio.h"

char prime[10000000];
int main(){
    int i,j,n,c;
    scanf("%d", &n);
    for(i = 2,c = 0; c < n; i++){
        if(!prime[i]){
            c++;
            for(j = i; j < 10000000; j += i){
                prime[j] = 1;
            }
        }
    }
    printf("%d\n",i-1);
}
