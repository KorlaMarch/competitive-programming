#include "stdio.h"

int t,i,j,n,k,x,y,in;
bool canR[2][100010];
int main(){
    scanf("%d",&t);
    for(i = 1; i <= t; i++){
        scanf("%d%d",&n,&k);
        for(j = 0; j < k; j++){
            canR[0][j] = canR[1][j] = false;
        }
        canR[0][0] = true;
        for(j = 0; j < n; j++){
            scanf("%d",&x);
            in = (j+1)%2;
            for(y = 0; y < k; y++){
                if(canR[!in][y]){
                    canR[in][y] = true;
                    canR[in][(x+y)%k] = true;
                }
            }
        }
        for(j = k-1; j >= 0; j--){
            if(canR[in][j]){
                printf("Case #%d: %d\n",i,j);
                break;
            }
        }
    }
}
