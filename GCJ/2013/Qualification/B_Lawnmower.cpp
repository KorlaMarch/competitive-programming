#include "stdio.h"

int t,k,n,m,i,j;
int h[105][105];
bool isT;
bool check(int x, int y, int dx, int dy, int nh){
    if(x<0||y<0||x>=n||y>=m) return true;
    else if(h[x][y]>nh) return false;
    else return check(x+dx,y+dy,dx,dy,nh);
}

int main(){
    scanf("%d",&t);
    for(k = 1; k <= t; k++){
        scanf("%d%d",&n,&m);
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                scanf("%d",&h[i][j]);
            }
        }
        isT = true;
        for(i = 0; i < n && isT; i++){
            for(j = 0; j < m && isT; j++){
                if(!check(i,0,0,1,h[i][j])&&!check(0,j,1,0,h[i][j])) isT = false;
            }
        }
        if(isT) printf("Case #%d: YES\n",k);
        else printf("Case #%d: NO\n",k);
    }
}
