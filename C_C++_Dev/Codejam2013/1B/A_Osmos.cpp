#include "stdio.h"
#include "algorithm"

int t,k,a,n,i,j,mn,op;
int s[105];

int main(){
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf("%d%d",&a,&n);
        mn = n;
        op = 0;
        for(i = 0; i < n; i++){
            scanf("%d",&s[i]);
        }
        std::sort(s,s+n);
        if(a>1) for(i = 0; i < n; i++){
            while(a<=s[i]){
                a += a-1;
                op++;
            }
            a += s[i];
            mn = std::min(mn,op+(n-i-1));
        }
        printf("Case #%d: %d\n",k,mn);
    }
}
