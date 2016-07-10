#include "stdio.h"
#include "algorithm"

#define INF 1000000000

int r,c,i,j,e,o,p,q,w,v1,v2;
int h[5005][101];
int v[5005][101];
int dis[5005][101][101];
int tmp1[101][101],tmp2[101][101];

void calSingleRow(int r, int ptr){
    int i,j,k,mn;
    for(j = 0; j < c; j++){
        dis[ptr][j][j] = 0;
        for(k = j-1; k >= 0; k--){
            dis[ptr][j][k] = dis[ptr][j][k+1]+h[r][k];
        }
        for(k = j+1; k < c; k++){
            dis[ptr][j][k] = dis[ptr][j][k-1]+h[r][k-1];
        }
    }
}

void findAll(int no, int x, int y){
    int i,j,k,mn;
    findAll(no*2+1,x,x+(y-x)/2);
    findAll(no*2+2,x+(y-x)/2+1,y)
    for(i = 0; i < c; i++){
        for(j = 0; j < c; j++){

        }
    }
}
void do_dynamic(int b){
    int i,j,k,mn;
    for(i = b; i < r; i++){
        for(j = 0; j < c; j++){
            mn = INF;
            for(k = 0; k < c; k++){
                if(k) mn += h[i][k-1];
                if(mn<dis[i-1][j][k]+v[i-1][k]) dis[i][j][k] = mn;
                else mn = dis[i][j][k] = dis[i-1][j][k]+v[i-1][k];
            }
            mn = dis[i][j][c-1];
            for(k = c-2; k >= 0; k--){
                mn += h[i][k];
                if(mn<dis[i][j][k]) dis[i][j][k] = mn;
                else mn = dis[i][j][k];
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
    initDyn();
    do_dynamic(1);
    scanf("%d",&e);
    for(i = 0; i < e; i++){
        scanf("%d",&o);
        if(o==3){
            scanf("%d%d",&v1,&v2);
            printf("%d\n",dis[r-1][v1][v2]);
        }else{
            scanf("%d%d%d",&p,&q,&w);
            if(o==1){
                h[p][q] = w;
            }else{
                v[p][q] = w;
            }
            if(p>=2){
                do_dynamic(p-1);
            }else{
                initDyn();
                do_dynamic(1);
            }
        }
    }
}
