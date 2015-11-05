#include "stdio.h"
#include "algorithm"
int n,i,j,s;
int sy[100005],sc[100005];
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",sy+i);
    }
    for(i = 0; i < n; i++){
        scanf("%d",sc+i);
    }
    std::sort(sy,sy+n);
    std::sort(sc,sc+n);
    for(i = n-1,j = n-1; i >= 0; i--){
        for(;j>=0&&sy[i]<=sc[j];j--);
        if(j<0) break;
        else{
            j--;
            s += sy[i];
        }
    }
    printf("%d\n",s);
}
