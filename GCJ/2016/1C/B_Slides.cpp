#include "stdio.h"

int t,b,k,i,j;
long long m,om;
long long tpow[55];
int mtx[55][55];

bool check(){
    long long dyn[55];
    int i,j;
    dyn[1] = 1;
    for(i = 2; i <= b; i++){
        dyn[i] = 0;
        for(j = 1; j <= b; j++){
            if(mtx[j][i]) dyn[i] += dyn[j];
        }
        //printf("%d %lld\n",i,dyn[i]);
    }
    return dyn[b]==om;
}

int main(){
    scanf("%d",&t);
    tpow[0] = 1;
    for(i = 1; i <= 50; i++){
        tpow[i] = tpow[i-1]*2;
        //printf("%lld\n",tpow[i]);
    }
    for(k = 1; k <= t; k++){
        scanf("%d%lld",&b,&m);
        om = m;
        if(m>tpow[b-2]){
            printf("Case #%d: IMPOSSIBLE\n",k);
        }else{
            printf("Case #%d: POSSIBLE\n",k);
            for(i = 1; i < b; i++){
                for(j = 1; j < i; j++){
                    mtx[j][i] = 1;
                }
                for(; j <= b; j++) mtx[j][i] = 0;
            }
            //find Last
            for(i = b-1; i > 1; i--){
                if(m>=tpow[i-2]){
                    m -= tpow[i-2];
                    mtx[i][b] = 1;
                    //printf("m = %lld %lld\n",m,tpow[i-2]);
                }else mtx[i][b] = 0;
            }
            if(m) mtx[1][b] = 1;
            else mtx[1][b] = 0;
            for(i = 1; i <= b; i++){
                for(j = 1; j <= b; j++){
                    printf("%d",mtx[i][j]);
                }
                printf("\n");
            }
            if(!check()) printf("ERROR\n");
        }
    }
}
