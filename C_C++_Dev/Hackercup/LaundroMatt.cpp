#include "stdio.h"
#include "algorithm"
#include "queue"

int t,l,n,m,d,k,i,j,dc;
long long minT,z;
int w[100005];
long long st[1000005];
std::queue<long long> ep;
long long getL(long long m){
    long long x = 0;
    for(i = 0; i < n; i++){
        x += m/w[i];
    }
    return x;
}

long long getMinT(){
    long long x=0,y=w[0]*l,m,lm;
    while(x<=y){
        m = (x+y)/2;
        //printf(":%lld %lld %lld\n",x,y,m);
        lm = getL(m);
        if(lm<l){
            x = m+1;
        }else{
            y = m-1;
        }
    }
    return y+1;
}

int main(){
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf("%d%d%d%d",&l,&n,&m,&d);
        for(i = 0; i < n; i++){
            scanf("%d",&w[i]);
        }
        std::sort(w,w+n);
        minT = getMinT();
        for(i=j=0; i < n; i++){
            for(z=w[i];z<=minT&&j<l;z+=w[i],j++){
                st[j] = z;
                //printf("T %d %d\n",w[i],z);
            }
        }
        std::sort(st,st+l);
        for(i=dc=0; i < l; i++){
            while(!ep.empty()&&ep.front()<=st[i]){
                dc--;
                ep.pop();
            }
            //printf("DC :%d\n",dc);
            if(dc<m){
                ep.push(st[i]+d);
                dc++;
            }else{
                ep.push(ep.front()+d);
                ep.pop();
            }
        }
        while(ep.size()>1) ep.pop();
        printf("Case #%d: %lld\n",k,ep.front());
        ep.pop();
    }
}
