#include "stdio.h"

int n,m,dis,i,j,way,t,ec;
int x1,y1,x2,y2,x3,y3;
bool isV[10][10];
bool isV2[10][10];
int abs(int n){
    return n<0?-n:n;
}
int taxiDis(int x, int y, int sx, int sy){
    return abs(x-sx)+abs(y-sy);
}

void couD(int x, int y){
    ec++;
    isV2[x][y] = true;
    if(x>0&&!isV2[x-1][y]) couD(x-1,y);
    if(y>0&&!isV2[x][y-1]) couD(x,y-1);
    if(x+1<n&&!isV2[x+1][y]) couD(x+1,y);
    if(y+1<m&&!isV2[x][y+1]) couD(x,y+1);
    return;
}
void copyV(){
    int i,j;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            isV2[i][j] = isV[i][j];
        }
    }
}
void recur(int x, int y, int d){
    if(d==dis){
        if(x==0&&y==1) way++;
        return;
    }else if((d!=dis/4&&(x==x1&&y==y1))||
       (d!=dis/2&&(x==x2&&y==y2))||
       (d!=3*dis/4&&(x==x3&&y==y3))||
       (x==0&&y==1)){
        return;
    }else if((d==dis/4&&(x!=x1||y!=y1))||
       (d==dis/2&&(x!=x2||y!=y2))||
       (d==3*dis/4&&(x!=x3||y!=y3))){
        return;
    }else{
        if(d<=dis/4){
            if(taxiDis(x,y,x1,y1)>dis/4-d) return;
        }else if(d<=dis/2){
            if(taxiDis(x,y,x2,y2)>dis/2-d) return;
        }else if(d<=3*dis/4){
            if(taxiDis(x,y,x3,y3)>3*dis/4-d) return;
        }
        ec = 0;
        copyV();
        couD(x,y);
        //printf("%d %d = %d\n",d,ec,dis-d+1);
        if(ec!=dis-d+1) return;
        isV[x][y] = true;
        if(x>0&&!isV[x-1][y]) recur(x-1,y,d+1);
        if(y>0&&!isV[x][y-1]) recur(x,y-1,d+1);
        if(x+1<n&&!isV[x+1][y]) recur(x+1,y,d+1);
        if(y+1<m&&!isV[x][y+1]) recur(x,y+1,d+1);
        isV[x][y] = false;
    }
}

int main(){
    for(t = 1; ; t++){
        scanf("%d%d",&n,&m);
        if(n==0&&m==0) break;
        dis = n*m;
        scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
        way = 0;
        recur(0,0,1);
        printf("Case %d: %d\n",t,way);
    }
}
