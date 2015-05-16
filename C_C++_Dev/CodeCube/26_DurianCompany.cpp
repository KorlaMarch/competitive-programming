#include "stdio.h"

int n,i,j,a,b,vi,max;
int t[1000001];

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d %d",&a,&b);
        t[a]++;
        t[b]--;
    }
    for(i=vi=0; i<=1000000;i++){
        vi += t[i];
        if(vi>max) max = vi;
    }
    printf("%d\n",max);
}
