#include "stdio.h"
int n,i,j,k,x,y,mn,dif;
char s[512][512];
int minDif[512][512],qs[512][512];
int getQS(int x1, int y1, int x2, int y2){
    if(x1&&y1) return qs[x2][y2]-qs[x1-1][y2]-qs[x2][y1-1]+qs[x1-1][y1-1];
    else if(x1) return qs[x2][y2]-qs[x1-1][y2];
    else if(y1) return qs[x2][y2]-qs[x2][y1-1];
    else return qs[x2][y2];
}
int getDif(int x1, int y1, int x2, int y2, int r){
    if(r==x) return getQS(x1,y1,x2,y2);
    else if(r==y) return k*k/4-getQS(x1,y1,x2,y2);
    else return minDif[x1][y1];

}
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf(" %s",s[i]);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i&&j) qs[i][j] = (s[i][j]-'0')+qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
            else if(i) qs[i][j] = (s[i][j]-'0')+qs[i-1][j];
            else if(j) qs[i][j] = (s[i][j]-'0')+qs[i][j-1];
            else qs[i][j] = (s[i][j]-'0');
        }
    }
    for(k = 2; k <= n; k *= 2){
        for(i = 0; i < n; i += k){
            for(j = 0; j < n; j += k){
                mn = 300000;
                //x==white  y==black
                for(x = 0; x < 4; x++){
                    for(y = 0; y < 4; y++){
                        if(x!=y){
                            dif  = getDif(i     ,j      ,i+k/2-1    ,j+k/2-1    ,0);
                            dif += getDif(i     ,j+k/2  ,i+k/2-1    ,j+k-1      ,1);
                            dif += getDif(i+k/2 ,j      ,i+k-1      ,j+k/2-1    ,2);
                            dif += getDif(i+k/2 ,j+k/2  ,i+k-1      ,j+k-1      ,3);
                            if(dif<mn) mn = dif;
                        }
                    }
                }
                minDif[i][j] = mn;
            }
        }
    }
    printf("%d\n",minDif[0][0]);
}
