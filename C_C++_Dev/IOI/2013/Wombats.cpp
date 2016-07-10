#include "stdio.h"
#include "algorithm"

#define INF 1000000000

int r,c,i,j,e,o,p,q,w,v1,v2;
int h[5005][201];
int v[5005][201];
int dis[2][201][201];
void do_dynamic(){
    int i,j,k,mn;
    for(j = 0; j < c; j++){
        dis[0][j][j] = 0;
        for(k = j-1; k >= 0; k--){
            dis[0][j][k] = dis[0][j][k+1]+h[0][k];
        }
        for(k = j+1; k < c; k++){
            dis[0][j][k] = dis[0][j][k-1]+h[0][k-1];
        }
    }
    for(i = 1; i < r; i++){
        for(j = 0; j < c; j++){
            mn = INF;
            for(k = 0; k < c; k++){
                if(k) mn += h[i][k-1];
                if(mn<dis[(i-1)%2][j][k]+v[i-1][k]) dis[i%2][j][k] = mn;
                else mn = dis[i%2][j][k] = dis[(i-1)%2][j][k]+v[i-1][k];
            }
            mn = dis[i%2][j][c-1];
            for(k = c-2; k >= 0; k--){
                mn += h[i][k];
                if(mn<dis[i%2][j][k]) dis[i%2][j][k] = mn;
                else mn = dis[i%2][j][k];
            }
            //for(k = 0; k < c; k++) printf("R:%d C:%d->%d :%d\n",i,j,k,dis[i%2][j][k]);
        }
    }
}

int main(){
    scanf("%d%d",&r,&c);
    for(i = 0; i < r; i++){
        for(j = 0; j < c-1; j++){
            scanf("%d",&h[i][j]);
        }
    }
    for(i = 0; i < r-1; i++){
        for(j = 0; j < c; j++){
            scanf("%d",&v[i][j]);
        }
    }
    do_dynamic();
    scanf("%d",&e);
    for(i = 0; i < e; i++){
        scanf("%d",&o);
        if(o==3){
            scanf("%d%d",&v1,&v2);
            printf("%d\n",dis[(r-1)%2][v1][v2]);
        }else{
            scanf("%d%d%d",&p,&q,&w);
            if(o==1){
                h[p][q] = w;
            }else{
                v[p][q] = w;
            }
            do_dynamic();
        }
    }
}
