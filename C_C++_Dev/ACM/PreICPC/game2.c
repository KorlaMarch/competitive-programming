#include "stdio.h"

int max(int a, int b){
    return a>b?a:b;
}
int min(int a, int b){
    return a<b?a:b;
}

int h,w,i,j,mx;
int sum;
int sc[301][301];
int msc[301][301];

void findMx(){
    int x,y;
    for(x = 0; x < h; x++){
        for(y = 0; y < w; y++){
            if(x&&y){
                msc[x][y] = max(msc[x-1][y],msc[x][y-1])+sc[x][y];
            }else if(x){
                msc[x][y] = msc[x-1][y]+sc[x][y];
            }else if(y){
                msc[x][y] = msc[x][y-1]+sc[x][y];
            }else{
                msc[0][0] = sc[0][0];
            }
        }
    }
}

void findMn(){
    int x,y;
    for(x = 0; x < h; x++){
        for(y = 0; y < w; y++){
            if(x&&y){
                msc[x][y] = min(msc[x-1][y],msc[x][y-1])+sc[x][y];
            }else if(x){
                msc[x][y] = msc[x-1][y]+sc[x][y];
            }else if(y){
                msc[x][y] = msc[x][y-1]+sc[x][y];
            }else{
                msc[0][0] = sc[0][0];
            }
        }
    }
}

int main(){
    scanf("%d%d",&h,&w);
    for(i = h-1; i >= 0; i--){
        for(j = 0; j < w; j++){
            scanf("%d", &sc[i][j]);
        }
    }
    findMx();
    mx = msc[h-1][w-1];
    findMn();
    printf("%d",mx-msc[h-1][w-1]);
}
