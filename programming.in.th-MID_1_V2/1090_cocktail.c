#include "stdio.h"
int n,i,a,x,m;
int num[100001];
long long unsigned int s;
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&x);
        num[x]++;
        if(x>m) m = x;
    }
    scanf("%d",&a);
    for(i = a-m>0?a-m:0; i<=a/2; i++){
        if(a-i==i){
            s += num[i]*(long long unsigned int)(num[i]-1)/2;
        }else s += num[i]*(long long unsigned int)num[a-i];
    }
    printf("%llu\n",s);
}
