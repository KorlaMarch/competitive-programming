#include "stdio.h"
#include "math.h"
#include "limits.h"
#include "algorithm"
#define x first
#define y second
using namespace std;
int n,i;
pair<int,int> p[100005],t[100005];
bool cmp(pair<int,int> a, pair<int,int> b){
    return a.y==b.y?a.x<b.x:a.y<b.y;
}
long long closestPair(pair<int,int> p[], int n){
    if(n<=1){
        return 9223372036854775;
    }else if(n==2){
        return (p[0].x-p[1].x)*(long long)(p[0].x-p[1].x) + (p[0].y-p[1].y)*(long long)(p[0].y-p[1].y);
    }
    int L = p[n/2].x,dt,i,j,s;
    long long l1,l2,l3;
    l1 = closestPair(p,n/2);
    l2 = closestPair(p+n/2,n-n/2);
    l3 = min(l1,l2);
    dt = (int)sqrt(l1)+1;
    for(i = 0; i<n&&p[i].x<L-dt; i++);
    for(s = 0; i<n&&p[i].x<=L+dt; s++,i++){
        t[s] = p[i];
    }
    sort(t,t+s,cmp);
    for(i = 0; i < s; i++){
        for(j = i+1; j<s&&j-i<=7; j++){
            l3 = min(l3,(t[j].x-t[i].x)*(long long)(t[j].x-t[i].x)+(t[j].y-t[i].y)*(long long)(t[j].y-t[i].y));
        }
    }
    return l3;
}
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    std::sort(p,p+n);
    printf("%lld\n",closestPair(p,n));
}
