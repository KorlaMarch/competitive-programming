#include "stdio.h"
#include "algorithm"

int d,n,i,b;
int num[51];

int main(){
    for(scanf("%d",&d); d>0; d--){
        scanf("%d",&n);
        for(i = 0; i < n; i++){
            scanf("%d",&num[i]);
        }
        std::sort(num,num+n);
        for(b = 0,i = 1; i < n; i++){
            if(num[i-1]+1!=num[i]){
                if(i-1==b) printf("%d,",num[b]);
                else printf("%d->%d,",num[b],num[i-1]);
                b = i;
            }
        }
        if(i-1==b) printf("%d\n",num[b]);
        else printf("%d->%d\n",num[b],num[i-1]);
    }
}
