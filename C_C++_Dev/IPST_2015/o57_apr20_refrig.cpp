#include "stdio.h"
#include "algorithm"
#include "queue"
#include "vector"

int n,i,j,l;
long long t,a;
std::priority_queue<long long,std::vector<long long>,std::greater<long long> > qu;
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%lld",&l);
        qu.push(l);
    }
    while(!qu.empty()){
        t++;
        a = qu.top();
        if(a<t) break;
        qu.pop();
        qu.push(a+1);
    }
    printf("%d\n",t-1);
}
