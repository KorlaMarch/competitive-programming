#include "stdio.h"

int n,m,maxP;
int mon[51][3001];
int maxM[3001][51][51][2][2];


int main(){
    int i,j,x,y,a,b,c;
    char ta,tb,ta2,tb2;
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d",&mon[i][j]);
        }
    }
    maxM[0][0][n-1][0][0] = mon[0][0]+mon[n-1][0];
    for(i = 0; i < m; i++){
        for(a = 0; a < n; a++){
            for(b = 0; b < n; b++){
                for(ta = 0; ta <= 1; ta++){
                     for(tb = 0; tb <= 1; tb++){
                        if(maxM[i][a][b][ta][tb]){
                            for(x = a-1; x <= a+1; x++){
                                for(y = b-1; y <= b+1; y++){
                                    ta2 = ta;
                                    tb2 = tb;
                                    if(x==a) ta2++;
                                    if(y==b) tb2++;
                                    if(ta2>1||tb2>1||x<0||y<0||x>=n||y>=n) continue;
                                    if(x!=y) c = maxM[i][a][b][ta][tb]+mon[x][i+1]+mon[y][i+1];
                                    else c = maxM[i][a][b][ta][tb]+mon[x][i+1];
                                    if(c>maxM[i+1][x][y][ta2][tb2]){
                                        maxM[i+1][x][y][ta2][tb2] = c;
                                        //printf("%d %d %d %d %d %d %d :%d\n",i,a,b,ta,tb,x,y,c);
                                        if(c>maxP) maxP = c;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",maxP);
}
