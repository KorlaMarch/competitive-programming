#include "stdio.h"
#include "vector"
#include "algorithm"
#include "math.h"

#define BOUND 100000000005LL

int n,i,j;
long long k,x,y,m,sol;
long long a[100005];
int fen[100005];
std::vector<long long> pt;

void addFen(int x, int v){
    for(; x <= pt.size(); x += (x&-x)) fen[x] += v;
}
int getFen(int x){
    int v = 0;
    for(; x > 0; x -= (x&-x)) v += fen[x];
    return v;
}

long long countPI(long long m){
    long long co,sm = 0;
    int i;
    pt.clear();
    for(i = 0; i < n; i++){
        pt.push_back(sm);
        sm += a[i];
    }
    std::sort(pt.begin(),pt.end());
    for(i = 1; i <= pt.size(); i++) fen[i] = 0;
    sm=co=0;
    for(i = 0; i < n; i++){
        addFen(std::lower_bound(pt.begin(),pt.end(),sm)-pt.begin()+1,1);
        sm += a[i];
        co += getFen(std::upper_bound(pt.begin(),pt.end(),sm-m)-pt.begin());
    }
    return co;
}

int main(){
    scanf("%d %lld",&n,&k);
    for(i = 0; i < n; i++){
        scanf("%lld",&a[i]);
    }
    x = -BOUND, y = BOUND;
    while(x<=y){
        m = (x+y)/2;
        if(countPI(m)>=k){
            sol = m;
            x = m+1;
        }else{
            y = m-1;
        }
    }
    printf("%lld\n",sol);
}
