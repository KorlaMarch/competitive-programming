#include "stdio.h"

int n,i;
int px,py;
int dc[3000],rdc[3000];
long long sum;
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d",&px,&py);
        dc[py-px+1500]++;
        rdc[py+px]++;
    }
    for(i = 0; i < 3000; i++){
        sum += dc[i]*(dc[i]-1)/2 + rdc[i]*(rdc[i]-1)/2;
    }
    printf("%I64d\n",sum);
}
