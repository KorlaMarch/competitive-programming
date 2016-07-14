#include "stdio.h"
#include "algorithm"

int k,m,i,j,x,y,xi1,yi1,xi2,yi2,minD;
int sp[61][61];
int wx[61],wy[61];
bool isSet;
int abs(int x){
    return x<0?-x:x;
}

int manDis(int xi1, int yi1, int xi2, int yi2){
    return abs(xi1-xi2)+abs(yi1-yi2);
}

int main(){
    scanf("%d%d",&k,&m);
    for(i = 0; i <= 60; i++){
        for(j = 0; j <= 60; j++){
            sp[i][j] = -1;
        }
    }
    for(i = 0; i < k; i++){
        scanf("%d%d%d%d",&wx[i*2],&wy[i*2],&wx[i*2+1],&wy[i*2+1]);
        sp[i*2][i*2+1] = sp[i*2+1][i*2] = 0;
        sp[i*2][i*2] = sp[i*2+1][i*2+1] = 0;
    }
    for(i = 0; i < 2*k; i++){
        for(j = 0; j < 2*k; j++){
            if(sp[i][j]==-1){
                sp[i][j] = manDis(wx[i],wy[i],wx[j],wy[j]);
            }
        }
    }
    for(isSet=true; isSet; ){
        isSet = false;
        for(i = 0; i < 2*k; i++){
            for(j = 0; j < 2*k; j++){
                for(x = 0; x < 2*k; x++){
                    if(sp[i][x]+sp[x][j]<sp[i][j]){
                        sp[i][j] = sp[i][x]+sp[x][j];
                        isSet = true;
                    }
                }
            }
        }
    }
    for(x = 0; x < m; x++){
        scanf("%d%d%d%d",&xi1,&yi1,&xi2,&yi2);
        minD = manDis(xi1,yi1,xi2,yi2);
        //printf(":%d\n",minD);
        for(i = 0; i < 2*k; i++){
            for(j = 0; j < 2*k; j++){
                //printf("%d %d :%d %d %d\n",i,j,manDis(xi1,yi1,wx[i],wy[i]),manDis(wx[j],wy[j],xi2,yi2),sp[i][j]);
                minD = std::min(minD,manDis(xi1,yi1,wx[i],wy[i])+manDis(wx[j],wy[j],xi2,yi2)+sp[i][j]);
            }
        }
        printf("%d\n",minD);
    }
}
