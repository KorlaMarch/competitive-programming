#include "stdio.h"
#include "algorithm"
#include "map"
int n,i,j,k,mx;
char s[40];
long long x,m;
std::map<long long,int> mp;
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        x = 0;
        for(j = 0; j < 3; j++){
            scanf(" %s",s);
            for(k=0,m=1; s[k]; k++,m*=26){
                x += s[k]*m;
            }
        }
        mp[x]++;
        if(mp[x]>mx) mx = mp[x];
    }
    printf("%d\n",mx);
}
