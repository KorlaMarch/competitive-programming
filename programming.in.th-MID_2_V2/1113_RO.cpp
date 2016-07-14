#include "stdio.h"
#include "map"
int n,k,i,mx;
long long int d;
char c;
std::map<long long int, int> minP;
int max(int a, int b){
    return a>b?a:b;
}
int main(){
    scanf("%d%d ",&n,&k);
    minP[0] = 1;
    for(i = 2,n += 2; i < n; i++){
        if(getchar()=='R') d -= k;
        else d++;
        if(minP.count(d)){
            mx = max(mx,i-minP[d]);
        }else{
            minP[d] = i;
        }
    }
    printf("%d\n",mx);
}
