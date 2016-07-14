#include "stdio.h"
#include "algorithm"

int t,k,i,j,n;
long long e,r;
int v[10005];
long long gain;

void divide(int x, int y, int beg, int endW){
    int i,mp;
    long long mx = 0;
    for(i = x; i <= y; i++){
        if(v[i]>mx){
            mx = v[i];
            mp = i;
        }
    }
    //printf("call %d %d %d %d -> %d %d\n",x,y,beg,endW,mx,mp);
    if(r*(y-mp+1)<endW){
        gain += mx*(std::min(beg+r*(mp-x),e)-(endW-r*(y-mp+1)));
        if(mp-1>=x) divide(x,mp-1,beg,std::min(beg+r*(mp-x),e));
    }else{
        gain += mx*std::min(beg+r*(mp-x),e);
        if(mp-1>=x) divide(x,mp-1,beg,std::min(beg+r*(mp-x),e));
        if(mp+1<=y) divide(mp+1,y,r,endW);
    }
}

int main(){
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf("%d%d%d",&e,&r,&n);
        for(i = 0; i < n; i++){
            scanf("%d",&v[i]);
        }
        gain = 0;
        divide(0,n-1,e,0);
        printf("Case #%d: %lld\n",k,gain);
    }
}
