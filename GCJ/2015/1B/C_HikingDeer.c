#include "stdio.h"
typedef struct{
    int d,m;
}hiker;
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int t,k,i,j,n,d,h,m,p,minEn,enc;
    double travel_time;
    hiker hk[100];
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf("%d",&n);
        for(i=p=0; i < n; i++){
            scanf("%d%d%d",&d,&h,&m);
            for(j = 0; j < h; j++){
                hk[p].d = d;
                hk[p].m = j+m;
                p++;
            }
        }
        minEn = p;

        for(i = 0; i < p; i++){
            enc = 0;
            travel_time = (360-hk[i].d)/360.0*hk[i].m;
            for(j = 0; j < p; j++){
                if(i!=j){
                    if(hk[j].d<hk[i].d) enc++;
                    //faster
                    if(hk[i].m<hk[j].m&&hk[i].d<=hk[j].d&&hk[j].d+travel_time/hk[j].m<360.0) enc++;
                    //slower
                    else if(hk[i].m>hk[j].m){
                        enc += max(0,(int)(travel_time/hk[j].m)-1);
                        //if(hk[j].d<=hk[i].d&&hk[i].d+((360-hk[j].d)/360.0*hk[j].m)/hk[i].m<360.0) enc++;
                    }
                }
            }
            //printf("%d %d %f\n",i,enc,travel_time);
            if(enc<minEn) minEn = enc;
        }
        printf("Case #%d: %d\n",k,minEn);
    }
}
