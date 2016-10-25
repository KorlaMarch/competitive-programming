#include "stdio.h"
#include "algorithm"

int n,i,test;
long long l[100005];
long long t,rft;

int main(){
    for(scanf("%d",&test); test > 0; test--){
        scanf("%d",&n);
        for(i = 0; i < n; i++){
            scanf("%lld",&l[i]);
        }
        std::sort(l,l+n);
        for(t=rft=0,i = 0; i < n; i++){
            if((l[i]-t)*i-(l[i]-t)+1<=rft){
                rft -= (l[i]-t)*i-(l[i]-t);
                t = l[i];
            }else{
                break;
            }
        }
        if(rft%(i-1)) t += rft/(i-1);
        else if(rft) t += rft/(i-1)-1;
        printf("%lld\n",t);
    }
}
