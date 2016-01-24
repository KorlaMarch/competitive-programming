#include "stdio.h"
#include "algorithm"

int n,d,i,j;
long long mx,fri;
std::pair<int,int> f[100005];

int main(){
    scanf("%d%d",&n,&d);
    for(i = 0; i < n; i++){
        scanf("%d%d",&f[i].first,&f[i].second);
    }
    std::sort(f,f+n);
    for(i=j=0,mx=fri=f[0].second; i<n && j<n;){
        if(f[j].first-f[i].first>=d){
            fri -= f[i].second;
            i++;
        }else{
            j++;
            fri += f[j].second;
        }
        if(fri>mx&&f[j].first-f[i].first<d) mx = fri;
    }
    printf("%I64d\n",mx);
}
