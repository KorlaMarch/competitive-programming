#include "stdio.h"

int n,t,i,j,z;
long long x,y,m,sum,lb;
int vi[1000000];

int getT(long long c){
    long long p = c;
    int i,t;
    for(i=t=0; i < n; i++){
        if(p<vi[i]){
            t++;
            p = c;
            if(p<vi[i]) return 0;
        }
        p -= vi[i];
    }
    return t+1;
}

int main(){
    scanf("%d%d",&n,&t);
    for(i = 0; i < n; i++){
        scanf("%d",vi+i);
        sum += vi[i];
    }
    for(x=0,y=sum;x<=y;){
        m = (x+y)/2;
        z = getT(m);
        if(z>t||!z){
            x = m+1;
        }else if(z<=t){
            y = m-1;
        }
    }
    lb = y+1;

    for(x=0,y=sum+1;x<=y;){
        m = (x+y)/2;
        z = getT(m);
        if(z>=t||!z){
            x = m+1;
        }else if(z<t){
            y = m-1;
        }
    }
    if(y==sum+1){
        printf("-1\n");
    }else{
        printf("%lld\n",y-lb+1);
    }
}
