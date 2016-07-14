#include "stdio.h"
#include "time.h"
int n,k,i,j,maxK;
int a[30005];

int main(){
    clock_t st = clock();
    scanf("%d%d",&n,&k);
    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    for(i=j=0; i < n; i++){
        while(j<n&&a[j]-a[i]<=k) j++;
        if(j-i>maxK) maxK = j-i;
    }
    printf("%d (%d ms)\n",maxK,clock()-st);
}
