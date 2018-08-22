#include "stdio.h"

int x;
long long mem[1000005];

long long count_way(int x){
    //if we already cal them, return
    if(mem[x]){
        return mem[x];
    }
    //else, find it's factor
    mem[x] = 1;
    for(int i = 2; i <= x/i; i++){
        if(x%i==0){
            mem[x] += count_way(x/i);
            printf("x : %d : %d , %lld\n", x, x/i, count_way(x/i));
        }
    }
    printf("mem %d = %lld\n",x,mem[x]);
    return mem[x];
}

int main(){
    mem[1] = 1;
    printf("Enter number? ");
    scanf("%d",&x);
    printf("Total=%lld\n",count_way(x));
}
