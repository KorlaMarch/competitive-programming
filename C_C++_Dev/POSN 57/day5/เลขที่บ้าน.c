#include "stdio.h"

int num[10] = {};

void plusNum(int n){
    while(n != 0){
        num[n%10]++;
        n /= 10;
    }
}

int main(){
    int n,m,i;
    scanf("%d%d", &n, &m);
    for(i = n; i <= m; i++){
        plusNum(i);
    }
    for(i = 0; i < 10; i++){
        printf("%d %d\n", i, num[i]);
    }
}
