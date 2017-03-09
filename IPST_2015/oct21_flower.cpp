#include "stdio.h"
#include "algorithm"

int m,k,mx;
int a[105],b[105],t[105];
int dyn[2][105][105][105];

int main(){
    scanf("%d%d",&m,&k);
    for(int i = 0; i < k; i++){
        scanf("%lld%lld%lld",&a[i],&b[i],&t[i]);
    }

    //init value
    for(int x = 0; x <= k; x++){
        for(int y = 0; y <= k; y++){
            dyn[0][0][x][y] = -1;
        }
    }
    dyn[0][0][0][0] = 0;

    for(int j = 0; j <= m; j++){
        for(int x = 0; x <= k; x++){
            for(int y = 0; y <= k; y++){
                dyn[1][j][x][y] = -1;
            }
        }
        dyn[1][j][0][0] = 0;
    }

    for(int i = 0; i < k; i++){
        const int ind = i%2;
        for(int j = 1; j <= m; j++){
            for(int x = 0; x <= k; x++){
                for(int y = 0; y <= k; y++){
                    if(x+y<=i+1&&x-2<=2*y&&y-2<=2*x){
                        dyn[ind][j][x][y] = std::max( dyn[!ind][j][x][y], dyn[ind][j-1][x][y] );
                        if(t[i]==1){
                            if(y>0 && j-a[i]>=0 && dyn[!ind][ j-a[i] ][x][y-1] != -1){
                                dyn[ind][j][x][y] = std::max(dyn[ind][j][x][y] , dyn[!ind][ j-a[i] ][x][y-1] + b[i]);
                            }
                        }else{
                            if(x>0 && j-a[i]>=0 && dyn[!ind][ j-a[i] ][x-1][y] != -1){
                                dyn[ind][j][x][y] = std::max(dyn[ind][j][x][y] , dyn[!ind][ j-a[i] ][x-1][y] + b[i]);
                            }
                        }
                    }else{
                        dyn[ind][j][x][y] = -1;
                    }

                }
            }
        }
    }

    //find max in dyn
    mx = -1;
    for(int x = 0; x <= k; x++){
        for(int y = 0; y <= k; y++){
            if(dyn[(k-1)%2][m][x][y]>mx){
                //printf("Find max at %d : %d %d\n",dyn[(k-1)%2][m][x][y],x,y);
                mx = dyn[(k-1)%2][m][x][y];
            }
        }
    }
    printf("%lld\n",mx);
}