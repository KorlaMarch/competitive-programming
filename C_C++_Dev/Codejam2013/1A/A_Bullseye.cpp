#include "stdio.h"

#define M_PI 3.141592653589793

int t,k,i;
long long r,l;
int main(){
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf("%lld%lld",&r,&l);
        for(i = 0; l >= (r+1)*(r+1)-r*r;r += 2,i++){
            l -= (r+1)*(r+1)-r*r;
        }
        printf("Case #%d: %d\n",k,i);
    }
}
