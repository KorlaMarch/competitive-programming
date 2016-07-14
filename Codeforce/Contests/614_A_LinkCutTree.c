#include "stdio.h"

long long int l,r,k,p,p2,i,j,c;
char isP;

int main(){
    scanf("%I64d%I64d%I64d",&l,&r,&k);
    for(p2 = 2,c = 1; p2 < r; p2 *= 2,c++);
    for(p2 = 2,i = 0; p2 < k; p2 *= 2,i++);
    for(p=1,j=0; p <= r; p*=k,j+=i){
        p2 = (1<<j);
        if(p2*2<p) j++;
        if(p>=l){
            printf("%I64d ",p);
            isP = 1;
        }
        //printf(":%lld %lld %lld\n",i,j,c);
        if(j+i>c){
            break;
        }
    }
    if(!isP){
        printf("-1\n");
    }
}
