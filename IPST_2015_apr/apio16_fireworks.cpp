#include "stdio.h"
#include "vector"
#include "algorithm"

int n,m,i,j;
std::vector<int> child[300005];
int p[300005];
long long c[300005];
long long a[300005],b[300005],s[300005];

void solve(int x){
    std::vector<long long> tp;
    int i,p;
    s[x] = 0;
    a[x] = 0;
    b[x] = 0;
    if(x>n){
        a[x] = b[x] = c[x];
        return;
    }
    for(int y : child[x]){
        solve(y);
    }
    tp.clear();
    for(int y : child[x]){
        tp.push_back(a[y]);
        tp.push_back(b[y]);
    }
    if(!tp.empty()){
        std::sort(tp.begin(),tp.end());
        a[x] = tp[tp.size()/2-1];
        b[x] = tp[tp.size()/2];
        for(int y : child[x]){
            s[x] += s[y];
            if(a[x]<a[y]) s[x] += a[y]-a[x];
            else if(a[x]>b[y]) s[x] += a[x]-b[y];
        }
    }
    //printf("%d : %lld %lld %lld\n",x,a[x],b[x],s[x]);
    a[x] += c[x];
    b[x] += c[x];
    //printf("%d: %lld %lld %lld\n",x,a[x],b[x],s[x]);
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 2; i <= n+m; i++){
        scanf("%d %lld",&p[i],&c[i]);
        child[p[i]].push_back(i);
    }
    solve(1);
    printf("%lld\n",s[1]);
}
