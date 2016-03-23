#include "stdio.h"

int n,m,t,i,j,x,y,minA;
int mp[1005][1005];

int main(){
    minA = 4000000;
    scanf("%d%d%d",&n,&m,&t);
    for(i = 0; i < n; i++){
        scanf("%d%d",&x,&y);
        mp[x+1][y+1] = 1;
    }
    for(i = 1; i <= m; i++){
        for(j = 1; j <= m; j++){
            mp[i][j] += mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1];
        }
    }
    for(i = 1; i <= m; i++){
        for(j=x=1; j <= m; j++){
            while(x <= m&&mp[i][x]-mp[i][j-1]-mp[0][x]+mp[0][j-1]<t) x++;
            //if(i==1&&j==13)printf(":%d : (%d,%d) : (%d,%d) (%d)\n",minA,i,x,0,j-1,mp[i][x]-mp[i][j-1]-mp[0][x]+mp[0][j-1]);
            //if(x<=m&&mp[i][x]-mp[i][j-1]-mp[0][x]+mp[0][j-1]<0) printf("%d %d : %d %d : %d %d %d\n",i,x,0,j-1,mp[i][x],mp[i][j-1],mp[0][x],mp[0][j-1]);
            if(x<=m&&(x-j+1)*(i)<minA){
                minA = (x-j+1)*(i);
                //printf("%d : (%d,%d) : (%d,%d) (%d)\n",minA,i,x,0,j-1,mp[i][x]-mp[i][j-1]-mp[0][x]+mp[0][j-1]);
            }
        }
    }
    printf("%d\n",minA);
}
