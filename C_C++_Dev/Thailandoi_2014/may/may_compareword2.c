#include "stdio.h"'
int t,a1,b1,c1,a2,b2,c2,n,m,i,j;
long long ls1,ls2,dif;
char num[1000000];
int feq[52];

int main(){
    for(scanf("%d",&t); t>0; t--){
        scanf("%d %d %d %d",&n,&a1,&b1,&c1);
        scanf("%d %d %d %d",&m,&a2,&b2,&c2);
        for(i = 0; i < 52; i++) feq[i] = 0;
        ls1 = c1,ls2 = c2,dif = 0;
        for(i = 0; i < n-m; i++){
            feq[ls1%52]++;
            num[i] = ls1%52;
            ls1 = (ls1*a1+b1)%57885161;
        }
        for(j = 0; j < m; j++){
            feq[ls1%52]++;
            dif += feq[ls2%52];
            ls1 = (ls1*a1+b1)%57885161;
            ls2 = (ls2*a2+b2)%57885161;
            feq[num[j]]--;
        }
        printf("%lld\n",dif);
    }
}
