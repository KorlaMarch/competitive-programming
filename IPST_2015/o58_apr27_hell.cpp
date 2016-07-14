#include "stdio.h"

int r,c,k,i,j;
char mp[105][105];
int way1[105][105];
int buf[105][105];
long long way[2][105][105];
long long tmp[105][105];
long long sum;
void initway(int n){
    int i,j;
    for(i = 0; i < r; i++){
        buf[i][0] = 0;
    }
    if(mp[n][0]) buf[n][0] = 1;
    for(j = 1; j < c; j++){
        for(i = 0; i < r; i++){
            if(mp[i][j]){
                buf[i][j] = buf[i][j-1];
                if(i>0) buf[i][j] += buf[i-1][j-1];
                if(i+1<r) buf[i][j] += buf[i+1][j-1];
                buf[i][j] = buf[i][j]%1000003;
            }else buf[i][j] = 0;
        }
    }
    for(i = 0; i < r; i++){
        way1[n][i] = buf[i][c-1];
    }
}

void calway(int d, int x){
    int i,j,k;
    if(x==1){
        for(i = 0; i < r; i++){
            for(j = 0; j < r; j++){
                way[d%2][i][j] = way1[i][j];
            }
        }
    }else{
        calway(d+1,x/2);
        for(i = 0; i < r; i++){
            for(j = 0; j < r; j++){
                way[d%2][i][j] = 0;
                for(k = 0; k < r; k++){
                    way[d%2][i][j] = (way[d%2][i][j]+way[(d+1)%2][i][k]*way[(d+1)%2][k][j])%1000003;
                }
            }
        }
        if(x%2){
            for(i = 0; i < r; i++){
                for(j = 0; j < r; j++){
                    tmp[i][j] = way[d%2][i][j];
                    way[d%2][i][j] = 0;
                }
            }
            for(i = 0; i < r; i++){
                for(j = 0; j < r; j++){
                    for(k = 0; k < r; k++){
                        way[d%2][i][j] = (way[d%2][i][j]+tmp[i][k]*way1[k][j])%1000003;
                    }
                }
            }
        }
    }
}

int main(){
    scanf("%d%d%d",&r,&c,&k);
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            scanf("%d",&mp[i][j]);
        }
    }
    for(i = 0; i < r; i++){
        initway(i);
    }
    calway(0,k);
    for(i = 0; i < r; i++){
        sum = 0;
        for(j = 0; j < r; j++){
            sum = (sum+way[0][i][j])%1000003;
        }
        printf("%lld\n",sum);
    }
}
