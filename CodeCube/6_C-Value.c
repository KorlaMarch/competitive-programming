#include "stdio.h"
int n,x,i,j,ans,min,max,minP,maxP;
int qs[1000001];
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&x);
        if(i%2) qs[i] += x;
        else qs[i] -= x;
        qs[i+1] = qs[i];
    }
    ans = qs[n-1]>0?qs[n-1]*-1:qs[n-1];
    for(i = 0; i < n; i++){
        x = qs[i]+(qs[n-1]-qs[i])*-1;
        if(x < ans) ans = x;
    }
    for(i=0,max=-100000000; i < n; i++){
        if(qs[i]>max){
            max = qs[i];
            maxP = i;
        }
    }
    for(i=0,min=max; i < maxP; i++){
        if(qs[i]<min){
            min = qs[i];
            minP = i;
        }
    }
    x = qs[minP]+(max-min)*-1+qs[n-1]-qs[maxP];
    if(x<ans) ans = x;

    for(i=0,min=max; i < n; i++){
        if(qs[i]<min){
            min = qs[i];
            minP = i;
        }
    }
    for(i=minP+1,max=min,maxP=minP; i < n; i++){
        if(qs[i]>max){
            max = qs[i];
            maxP = i;
        }
    }
    x = qs[minP]+(max-min)*-1+qs[n-1]-qs[maxP];
    if(x<ans) ans = x;

    printf("%d\n",ans);
}
