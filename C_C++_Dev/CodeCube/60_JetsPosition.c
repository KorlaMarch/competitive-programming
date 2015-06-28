#include "stdio.h"
int n,i,sl,sr;
char c;
int v[100001];
int p[2][2];
int getMax(int d){
    int i,x,mi,mj;
    for(mi=mj=i=0,x=1; i < n; i++){
        if(mi+v[i]>0) mi = mi+v[i];
        else{
            mi = 0;
            x = i+2;
        }
        if(mi>mj){
            mj = mi;
            p[d][0] = x;
            p[d][1] = i+1;
        }
    }
    return mj;
}

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf(" %c %d",&c,v+i);
        if(c=='R'){
            sr += v[i];
            v[i] *= -1;
        }else{
            sl += v[i];
        }
    }
    sr += getMax(0);
    for(i = 0; i < n; i++) v[i] = -v[i];
    sl += getMax(1);
    if(sr>=sl&&p[0][0]){
        printf("R %d %d %d\n",sr,p[0][0],p[0][1]);
    }else{
        printf("L %d %d %d\n",sl,p[1][0],p[1][1]);
    }
}
