#include "stdio.h"
#include "algorithm"

int n,m,i,j,p;
long long si;
int en[100001];

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf("%d",&en[i]);
    }
    std::sort(en,en+n);
    for(i = 0; i < n && 2*en[i]<m; i++){
        p = std::lower_bound(en,en+n,m-en[i])-en;
        if(p<n&&en[p]==m-en[i]){
            si += std::upper_bound(en,en+n,m-en[i])-en-p;
        }
    }
    if(m%2==0){
        p = std::lower_bound(en,en+n,m/2)-en;
        if(p<n&&en[p]==m-en[i]){
            p = std::upper_bound(en,en+n,m/2)-en-p;
            si += p*(long long)(p-1)/2;
        }
    }
    printf("%lld\n",si);
}
