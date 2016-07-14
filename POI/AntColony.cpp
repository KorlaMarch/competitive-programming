#include "stdio.h"
#include "vector"
#include "algorithm"

#define MAX_ANT 1000000000

int n,g,k,i,j,da,db,a,b,x,y;
int m[1000005];
std::vector<int> edge[1000005];
std::vector<long long> divL;
long long sum;

void findDiv(int no, int o, long long d){
    int i;
    if(d>MAX_ANT) return;
    //printf("CAll %d %d %lld\n",no,o,d);
    if(edge[no].size()<=1){
        divL.push_back(d);
        return;
    }
    for(int i = 0; i < edge[no].size(); i++){
        if(edge[no][i]!=o){
            findDiv(edge[no][i],no,d*(edge[no].size()-1));
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&g,&k);
    for(i = 0; i < g; i++){
        scanf("%d",&m[i]);
    }
    scanf("%d%d",&da,&db);
    edge[da].push_back(db);
    edge[db].push_back(da);
    for(i = 2; i < n; i++){
        scanf("%d%d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    findDiv(da,db,1);
    findDiv(db,da,1);
    std::sort(divL.begin(),divL.end());
    /*printf("DIV : ");
    for(long long x : divL){
        printf("%lld ",x);
    }
    printf("\n");*/
    for(i = 0; i < g; i++){
        x = std::lower_bound(divL.begin(),divL.end(),(int)(m[i]/(double)(k+1)+1))-divL.begin();
        y = std::upper_bound(divL.begin(),divL.end(),m[i]/k)-divL.begin();
        sum += y-x;
        //printf("SUM %d %lld : %d %d\n",y-x,sum,x,y);
    }
    printf("%lld\n",sum*k);
}
