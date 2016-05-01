#include "stdio.h"
#include "algorithm"

std::pair<int,int> itv[100005];
int i,c,n,le;

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d%d",&itv[i].second,&itv[i].first);
    }
    std::sort(itv,itv+n);
    for(i = 0; i < n; i++){
        if(itv[i].second>=le){
            le = itv[i].first;
            c++;
        }
    }
    printf("%d\n",c);
}
