#include "stdio.h"
char map[66][66];
int p[65][65],dyn[65][65];
int isF[5000];
int w,l,i,j,cnt,mx,mn,np,k;

void flood(int x, int y, int cn){
    if(map[x][y]!='P') return;
    p[x][y] = cn;
    if(x-1&&!p[x-1][y]) flood(x-1,y,cn);
    if(y-1&&!p[x][y-1]) flood(x,y-1,cn);
    if(x+1<=l&&!p[x+1][y]) flood(x+1,y,cn);
    if(y+1<=w&&!p[x][y+1]) flood(x,y+1,cn);
}
int getP(int x, int y, int s){
    int i,j,cn = 0;
    for(i = x-s+1; i <= x; i++){
        for(j = y-s+1; j <= y; j++){
            if(p[i][j]&&isF[p[i][j]]!=cnt){
                cn++;
                isF[p[i][j]] = cnt;
            }
        }
    }
    cnt++;
    return cn;
}
int main(){
    scanf("%d%d ",&w,&l);
    for(i = 1; i <= l; i++){
        gets(map[i]+1);
    }
    for(i=cnt=1; i <= l; i++){
        for(j = 1; j <= w; j++){
            if(map[i][j]=='P'&&!p[i][j]){
                flood(i,j,cnt++);
            }
        }
    }
    for(i = 1; i <= l; i++){
        for(j = 1; j <= w; j++){
            if(map[i][j]=='T')
                dyn[i][j] = 0;
            else{
                for(k = 1;k<=dyn[i-1][j-1]+1&&map[i][j-k+1]!='T'&&map[i-k+1][j]!='T';k++);
                dyn[i][j] = k-1;
                if(k-1>mx) mx = k-1;
            }
        }
    }
    printf("%d ",mx*mx);
    if(mx){
        for(i=cnt=1,mn = 5000; i <= l; i++){
            for(j = 1; j <= w; j++){
                if(dyn[i][j] == mx){
                    np = getP(i,j,dyn[i][j]);
                    if(np<mn) mn = np;
                }
            }
        }
        printf("%d\n",mn);
    }else printf("0\n");
}
