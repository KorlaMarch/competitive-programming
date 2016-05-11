#include "stdio.h"
#include "algorithm"

int t,k,n,i,j,mx;
int x[1005];
bool isWin[1005];
bool canW[1005][1005];
bool cw;

void addL(int l){
    int i,j;
    for(i = 0; i < n; i++){
        for(j = 0; j+l <= mx; j++){
            if(canW[i][j]){
                canW[i+1][j+l] = true;
            }
        }
    }
}

int main(){
    scanf("%d",&t);
    for(k = 0; k < t; k++){
        scanf("%d",&n);
        mx = 0;
        for(i = 0; i < n; i++){
            scanf("%d",&x[i]);
            mx = std::max(mx,x[i]);
        }
        for(i = 0; i <= n; i++){
            for(j = 0; j <= mx; j++){
                canW[i][j] = false;
            }
        }
        canW[0][0] = true;
        for(i = 0; i < n; i++){
            isWin[i] = false;
            if(i) addL(i);
        }
        for(; i <= mx; i++){
            isWin[i] = canW[n][i];
            if(!isWin[i]) addL(i);
            //printf("sw %d = %d\n",i,isWin[i]);
        }
        cw = false;
        for(i = 0; i < n; i++){
            if(isWin[x[i]]){
                cw = true;
                break;
            }
        }
        if(cw){
            printf("1\n");
        }else{
            printf("2\n");
        }
    }
}
