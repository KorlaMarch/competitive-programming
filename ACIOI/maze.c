#include "stdio.h"

int qx[200],qy[200],dis[200];
char map[100][101];
int r,c,i,qf,ql,x,y,d;

void enque(int x,int y,int d){
    map[x][y] = '#';
    dis[ql] = d;
    qx[ql] = x;
    qy[ql] = y;
    ql = (ql+1)%200;
}

int bfs(){
    enque(0,0,0);
    while(qf!=ql){
        x = qx[qf];
        y = qy[qf];
        d = dis[qf];
        qf = (qf+1)%200;
        if(x==r-1&&y==c-1){
            return d;
        }
        if(x>0&&map[x-1][y]=='.') enque(x-1,y,d+1);
        if(x+1<r&&map[x+1][y]=='.') enque(x+1,y,d+1);
        if(y>0&&map[x][y-1]=='.') enque(x,y-1,d+1);
        if(y+1<c&&map[x][y+1]=='.') enque(x,y+1,d+1);
    }
    return -1;
}

int main(){
    scanf("%d%d",&r,&c);
    for(i = 0; i < r; i++){
        scanf(" %s", map[i]);
    }
    printf("%d\n", bfs());
}
