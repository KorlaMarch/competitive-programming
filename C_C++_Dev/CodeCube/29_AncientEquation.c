#include "stdio.h"
int main(){
    int n,x,i;
    int pow[166];
    for(i=0,n=1;i<166;i++){
        pow[i] = n;
        n = (n<<2)%997;
    }
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&x);
        printf("%d ",((x%2?-2:2)+pow[x%166])%997);
    }
}
