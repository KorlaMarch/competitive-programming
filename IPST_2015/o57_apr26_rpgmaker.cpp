#include "stdio.h"

int r,c,b,f,i,j,k,x,y,l,cs;
long long way[100][1005][17];
long long sum;
bool isV[2][16][16];
char bitC[16];
bool checkV(int k1, int k2, int b2){
    int v1,v2,i;
    v1 = 0, v2 = b2;
    for(i = 0; i < c-1; i++){
        v1 += (k1>>i)%2;
        v2 += (k2>>i)%2;
        if(v1>v2||v2-v1>1){
            return false;
        }
    }
    return true;
}
int countBit(int n){
    return n?(n%2+countBit(n/2)):0;
}
void upW(int ri, int bi, int ki){
    int i;
    for(i = 0; i < cs; i++){
        if(isV[0][i][ki]) way[ri][bi][ki] += way[ri-1][bi][i];
        if(isV[1][i][ki]) way[ri][bi][ki] += way[ri-1][bi-1][i];
    }
    way[ri][bi][ki] = way[ri][bi][ki]%4294967296;
    //printf("WAY %d %d %d = %d\n",ri,bi,ki,way[ri][bi][ki]);
}
int getB(int bi, int ki, int ci){
    int i;
    for(i = 1; i < ci; i++,ki/=2) bi += ki%2;
    return bi;
}
int main(){
    scanf("%d%d%d%d",&r,&c,&b,&f);
    if(f) scanf("%d%d%d",&x,&y,&l);
    cs = (1<<(c-1));
    for(i = 0; i < cs; i++){
        bitC[i] = countBit(i);
    }
    //precompute
    for(i = 0; i < cs; i++){
        for(j = 0; j < cs; j++){
            isV[0][i][j] = checkV(i,j,0);
            isV[1][i][j] = checkV(i,j,1);
        }
    }
    for(i = 1; i <= b; i++){
        for(j = 0; j < cs; j++){
            if(!f||x!=1||getB(i,j,y)==l) way[0][i][j] = 1;
        }
    }
    for(i = 1; i < r; i++){
        for(j = 1; j <= b; j++){
            for(k = 0; k < cs; k++){
                if(!f||i+1!=x||getB(j,k,y)==l) upW(i,j,k);
            }
        }
    }
    for(i = 1; i <= b; i++){
        for(j = 0; j < cs; j++){
            if((!f||x!=r||getB(i,j,y)==l)&&bitC[j]+i<=b) sum += way[r-1][i][j];
        }
        sum = sum%4294967296;
    }
    printf("%lld\n",sum);
}
