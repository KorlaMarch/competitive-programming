#include "stdio.h"
int max(int a, int b){
    return a>b?a:b;
}
int n,i,j;
int no[3005],so[3005];
int dyn[2][3005];
int main(){
    scanf("%d",&n);
    for(i = 1; i <= n; i++){
        scanf("%d",&no[i]);
    }
    for(i = 1; i <= n; i++){
        scanf("%d",&so[i]);
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            dyn[i%2][j] = max(dyn[(i+1)%2][j],dyn[i%2][j-1]);
            if(no[i]==so[j]) dyn[i%2][j] = max(dyn[i%2][j],dyn[(i+1)%2][j-1]+1);
        }
    }
    printf("%d\n",dyn[n%2][n]);
}
