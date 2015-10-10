#include "stdio.h"

int max(int a, int b){
    return a>b?a:b;
}
int t,n,k,a1,b1,c1,d1,a2,b2,c2,d2,hi,i,j,x,y,minL;
int hiL[10000500];

int main(){
    for(scanf("%d",&t); t > 0; t--){
        for(i = 0; i < 10000050; i++) hiL[i] = 0;
        scanf("%d%d%d%d%d%d%d%d%d%d",&n,&k,&a1,&b1,&c1,&d1,&a2,&b2,&c2,&d2);
        minL = 0;
        for(x=d1,y=d2,i=1;i<=n;i++,x=(a1*x+b1)%c1,y=(a2*y+b2)%c2){
            hi = 1+((x+3000*y)%10000000);
            for(j = max(1,hi-k); j <= hi+k; j++){
                if(hiL[j]&&(!minL||(i-hiL[j])<minL)){
                    minL = i-hiL[j];
                }
            }
            hiL[hi] = i;
        }
        if(minL){
            printf("%d\n",minL);
        }else{
            printf("-1\n");
        }
    }
}
