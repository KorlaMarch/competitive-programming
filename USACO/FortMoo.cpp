#include "stdio.h"

int n,m,i,j,x,y,mx;
char mp[205][205];
short qs[205][205][2];

int main(){
    freopen("fortmoo.in","r",stdin);
    freopen("fortmoo.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i = 1; i <= n; i++){
        scanf(" %s",mp[i]+1);
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            qs[i][j][0] = qs[i-1][j][0];
            qs[i][j][1] = qs[i][j-1][1];
            if(mp[i][j]=='X'){
                qs[i][j][0]++;
                qs[i][j][1]++;
            }
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            for(x = n; x >= i; x--){
                for(y = m; y >= j && (x-i+1)*(y-j+1) > mx; y--){
                    if(!(qs[x][j][0]-qs[i-1][j][0])&&!(qs[x][y][0]-qs[i-1][y][0])&&!(qs[i][y][1]-qs[i][j-1][1])&&!(qs[x][y][1]-qs[x][j-1][1])) mx = (x-i+1)*(y-j+1);
                }
            }
        }
    }
    printf("%d\n",mx);
}
