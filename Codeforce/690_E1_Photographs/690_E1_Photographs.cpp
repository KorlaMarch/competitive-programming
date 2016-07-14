#include "stdio.h"

int abs(int n){
    return n<0?-n:n;
}

double absD(double n){
    return n<0?-n:n;
}

int sq(int n){
    return n*n;
}

int q,h,w,i,j,t;
long long sumDiff;
long long sumMid;
int a[605][605];

int main(){
    scanf("%d",&q);
    for(t = 0; t < q; t++){
        sumDiff = sumMid = 0;
        scanf("%d%d",&h,&w);
        for(i = 0; i < h; i++){
            if(i==h/2){
                for(j = 0; j < w; j++){
                    scanf("%d",&a[i][j]);
                    sumMid += sq(abs(a[i-1][j]-a[i][j]));
                }
            }else{
                for(j = 0; j < w; j++){
                    scanf("%d",&a[i][j]);
                    if(i){
                        sumDiff += sq(abs(a[i-1][j]-a[i][j]));
                    }
                }
            }
        }
        //printf("%.4f MID :\t%.4f ->\t%.4f\n",sumDiff/(double)(h-2)/w,sumMid/(double)w,absD(sumDiff/(double)(h-2)-sumMid)/(double)w);
        if(absD(sumDiff/(double)(h-2)-sumMid)/(double)w>700.0) printf("YES\n");
        else printf("NO\n");
    }
}
