#include "stdio.h"
int n,k,p,i,j;
int max_sum[2][100000],vi[100000];
int max(int a, int b){
    return a>b?a:b;
}

int main(){
    scanf("%d%d%d%d",&n,&k,&p,&vi);
    for(i = 1; i < n; i++){
        scanf("%d",vi+i);
        vi[i] += vi[i-1];
    }
    for(i = 0; i < k; i++){
        for(j = 0; j < n; j++){
            max_sum[i&1][j] = max(max_sum[!(i&1)][j],vi[j]-(j-p>=0?vi[j-p]:0)+(j-p>=0?max_sum[!(i&1)][j-p]:0));
            if(j) max_sum[i&1][j] = max(max_sum[i&1][j],max_sum[i&1][j-1]);
        }
    }
    printf("%d\n",max_sum[!(i&1)][n-1]);
}
