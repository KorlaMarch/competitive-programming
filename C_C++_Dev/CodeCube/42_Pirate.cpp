#include "stdio.h"

int main(){
    int n,q,x,a,b,c,i,j,ptr;
    int ip[10000];
    int dp[10000];
    scanf("%d%d",&n,&q);
    for(i=ptr=0; i < q; i++){
        scanf("%d",&x);
        if(x){
            scanf("%d%d",&a,&b);
            ip[ptr] = a;
            dp[ptr++] = b+1;;
        }else{
            scanf("%d",&c);
            a = 0;
            for(j=0;j<ptr;j++){
                if(ip[j]<=c) a++;
                if(dp[j]<=c) a--;
            }
            switch(a%6){
            case 0: printf("sleep\n"); break;
            case 1: case 3: case 5: printf("eat\n"); break;
            default: printf("work\n"); break;
            }
        }
    }
}
