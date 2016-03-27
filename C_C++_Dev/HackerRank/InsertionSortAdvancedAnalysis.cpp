#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

int t,n,i,j,s,p;
int tp[100005];
int a[100005];
int fen[100005];
long long ns;
void addFen(int i, int v){
    for(; i <= s; i += (i&-i)) fen[i] += v;
}

int getFen(int i){
    int sum = 0;
    for(; i > 0; i -= (i&-i)) sum += fen[i];
    return sum;
}

int main() {
    for(scanf("%d",&t); t > 0; t--){
        scanf("%d",&n);
        for(i = 0; i < n; i++){
            scanf("%d",&a[i]);
            tp[i] = a[i];
        }
        std::sort(tp,tp+n);
        s = std::unique(tp,tp+n)-tp;
        for(i = 0; i <= s; i++) fen[i] = 0;
        ns = 0;
        for(i = 0; i < n; i++){
            p = std::lower_bound(tp,tp+s,a[i])-tp+1;
            ns += i-getFen(p);
            //printf("GET : %d %d\n",getFen(p),p);
            addFen(p,1);
        }
        printf("%lld\n",ns);
    }
    return 0;
}
