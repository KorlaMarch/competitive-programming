#include "stdio.h"
#include "algorithm"

std::pair<long long,int> p[100005];
std::pair<int,int> c[100005];
int n,i,j,x,v,minI,ans;
long long int t;

bool cmp(std::pair<long long,int> a, std::pair<long long,int> b){
    return a.first==b.first?a.second>b.second:a.first<b.first;
}

int main(){
    scanf("%d%lld",&n,&t);
    for(i = 0; i < n; i++){
        scanf("%d%d",&x,&v);
        c[i].first = x;
        c[i].second = v;
    }
    std::sort(c,c+n);
    for(i=j=0; i < n; i++,j++){
        //printf("%d %d\n",c[i].first,c[i].second);
        p[i].first = c[i].first + t*c[i].second;
        if(i>0&&c[i-1].first==c[i].first) j--;
        p[i].second = j;
    }
    std::sort(p,p+n,cmp);
    for(i = n-1,minI = n; i >= 0; i--){
        //printf(":%lld %d %d\n",p[i].first,p[i].second,minI);
        if(p[i].second<minI){
            minI = p[i].second;
            ans++;
        }
    }
    printf("%d\n",ans);
}
