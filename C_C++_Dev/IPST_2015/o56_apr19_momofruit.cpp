#include "stdio.h"
#include "algorithm"
#include "math.h"

int n,i,j,k,c,bu,p;
long long sum;
int t[100006];
int qs[100006];
int pos[100006];
int sumM[500];
std::pair<int,int> qs2[100006];
int qs3[100006];
int maxT[100006];

int main(){
    scanf("%d",&n);
    bu = (int)ceil(sqrt(n));
    qs2[0].second = 0;
    qs2[0].first = 0;
    for(i = 1; i <= n; i++){
        scanf("%d",&t[i]);
        qs[i] = qs[i-1]+t[i];
        qs2[i].first = qs[i];
        qs2[i].second = i;
    }
    std::sort(qs2,qs2+1+n);
    for(i = 0; i <= n; i++){
        pos[qs2[i].second] = i;
        qs3[i] = qs2[i].first;
        maxT[i] = -10000;
    }
    for(i = 0; i < 500; i++){
        sumM[i] = -10000;
    }
    maxT[pos[0]] = 0;
    sumM[pos[0]/bu] = 0;
    for(i = 1; i <= n; i++){
        p = pos[i];
        k = std::lower_bound(qs3,qs3+n+1,qs[i])-qs3;
        for(j = 0; j < k/bu; j++){
            if(sumM[j]>maxT[p]){
                maxT[p] = sumM[j];
            }
        }
        for(j = k-1; j >= 0 && j%bu != bu-1; j--){
            if(maxT[j]>maxT[p]){
                maxT[p] = maxT[j];
            }
        }
        if(maxT[p]>=0) maxT[p]++;
        if(maxT[p]>sumM[p/bu]){
            sumM[p/bu] = maxT[p];
        }
    }
    printf("%d\n",maxT[pos[n]]);
}
