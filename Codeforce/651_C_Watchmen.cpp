#include "stdio.h"
#include "algorithm"

int n,i;
long long c,c2,c3,way;
std::pair<int,int> wt[200005];
int x[200005],y[200005];
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d",&wt[i].first,&wt[i].second);
        y[i] = wt[i].second;
        x[i] = wt[i].first;
    }
    std::sort(x,x+n);
    std::sort(y,y+n);
    std::sort(wt,wt+n);
    c = c2 = c3 = 1;
    for(i = 1; i < n; i++){
        if(x[i-1]==x[i]){
            c++;
        }else{
            way += c*(c-1)/2;
            c = 1;
        }

        if(y[i-1]==y[i]){
            c2++;
        }else{
            way += c2*(c2-1)/2;
            c2 = 1;
        }

        if(wt[i-1]==wt[i]){
            c3++;
        }else{
            way -= c3*(c3-1)/2;
            c3 = 1;
        }
    }
    way += c*(c-1)/2+c2*(c2-1)/2-c3*(c3-1)/2;
    printf("%I64d\n",way);
}
