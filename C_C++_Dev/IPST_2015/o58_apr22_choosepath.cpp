#include "stdio.h"
#include "vector"
#include "queue"

int n,i,j,mx;
std::vector<std::pair<int,int> > child[200005];
std::vector<int> dList[200005];
int p[200005],a[200005],l[200005],dep[200005];
long long sumP[200005],sumN[200005];
long long sumP2[200005],sumN2[200005];
long long sum;

void initDep(int x, int d){
    dep[x] = d;
    for(auto pi : child[x]){
        initDep(pi.first,d+1);
    }
}

int main(){
    scanf("%d%d",&n,&p[0]);
    for(i = 1; i < n; i++){
        scanf("%d%d%d",&p[i],&a[i],&l[i]);
        child[a[i]].push_back({i,l[i]});
    }
    initDep(0,0);
    for(i = 0; i < n; i++){
        dList[dep[i]].push_back(i);
        if(dep[i]>mx) mx = dep[i];
    }
    for(i = mx; i >= 0; i--){
        for(int j : dList[i]){
            if(p[j]>0){
                sum += p[j]*sumP[j];
                sumP[j] += p[j];
            }else{
                sum += -p[j]*sumN[j];
                sumN[j] += -p[j];
            }
            if(i){
                if(l[j]%2){
                    sumP[a[j]] += sumN[j];
                    sumN[a[j]] += sumP[j];
                }else{
                    sumP[a[j]] += sumP[j];
                    sumN[a[j]] += sumN[j];
                }
            }
        }
    }
    sumP2[0] = sumP[0];
    sumN2[0] = sumN[0];
    for(i = 1; i <= mx; i++){
        for(int j : dList[i]){
            if(l[j]%2){
                sumP2[j] = sumN2[a[j]]-sumP[j];
                sumN2[j] = sumP2[a[j]]-sumN[j];
            }else{
                sumP2[j] = sumP2[a[j]]-sumP[j];
                sumN2[j] = sumN2[a[j]]-sumN[j];
            }
            if(p[j]>0){
                sum += p[j]*sumP2[j];
            }else{
                sum += -p[j]*sumN2[j];
            }
            sumP2[j] += sumP[j];
            sumN2[j] += sumN[j];
        }
    }
    printf("%lld\n",sum/2);
}
