#include "stdio.h"

int t,s,k,i;
unsigned long long a,x,ans,m;

int main(){
    for(scanf("%d",&t); t > 0; t--){
        scanf("%llu %d",&a,&k);
        for(x=a,s=0; x>0; x /= 10){
            s += x%10;
        }
        x = a;
        ans = 0;
        if(s==k) printf("%llu\n",a);
        else if(s>k){
            for(m=1;s>k;m*=10){
                s -= x%10;
                x /= 10;
            }
            ans = m*(k-s+x*10)/10;
            printf("1: %llu\n",ans);
        }else if(s<k){
            for(m=1;s<k;m*=10){
                s += (9-x%10);
                ans += m*9;
                x /= 10;
            }
            ans += m*(s-k+x*10);
            printf("2: %llu\n",ans);
        }
    }
}
