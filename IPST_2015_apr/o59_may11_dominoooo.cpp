#include "stdio.h"

#define MOD 1000000007

int r,c,i,j,lm;
// 0 = empty 1 = must match
long long sway[256][256];
long long eway[256];
long long way[35][256][256];
long long tmp[256][256];
bool isV[256];
bool checkV(int j){
    while(j > 0){
        if(j%2==1){
            if(j%4==3){
                j /= 2;
            }else return false;
        }
        j /= 2;
    }
    return true;
}

void geneway(){
    int i,j;
    for(i = 0; i < lm; i++){
        for(j = 0; j < lm; j++){
            if((i|j)==(i^j)&&isV[j]){
                eway[i]++;
            }
        }
    }
}

void genway1(){
    int i,j;
    for(i = 0; i < lm; i++){
        for(j = 0; j < lm; j++){
            if((i|j)==(i^j)){
                sway[i][j] = eway[i|j];
            }
        }
    }
}

void findWay(int c, int d){
    int i,j,k;
    if(c==1){
        for(i = 0; i < lm; i++){
            for(j = 0; j < lm; j++){
                way[d][i][j] = sway[i][j];
            }
        }
    }else{
        findWay(c/2,d+1);
        for(i = 0; i < lm; i++){
            for(j = 0; j < lm; j++){
                for(k = 0; k < lm; k++){
                    way[d][i][j] = (way[d][i][j]+way[d+1][i][k]*way[d+1][k][j])%MOD;
                }
            }
        }
        if(c%2){
            for(i = 0; i < lm; i++){
                for(j = 0; j < lm; j++){
                    tmp[i][j] = way[d][i][j];
                }
            }
            for(i = 0; i < lm; i++){
                for(j = 0; j < lm; j++){
                    way[d][i][j] = 0;
                    for(k = 0; k < lm; k++){
                        way[d][i][j] = (way[d][i][j]+tmp[i][k]*sway[k][j])%MOD;
                    }
                }
            }
        }
    }
}

int main(){
    scanf("%d%d",&r,&c);
    lm = (1<<r);
    //printf("lm = %d\n",lm);
    for(i = 0; i < lm; i++){
        isV[i] = checkV(i);
        //printf("isV[%d] = %d\n",i,isV[i]);
    }
    geneway();
    genway1();
    findWay(c,0);
    printf("%lld\n",way[0][0][0]);
}
