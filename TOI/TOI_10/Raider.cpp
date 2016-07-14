#include "stdio.h"
#include "queue"
typedef struct{
    int x,y,step;
}pos;
int n,m,i,j,step;
pos t;
std::queue<pos> q;
char sNum[100][100];
char isVisit[100][100][8201];
void enqueue(int x, int y, int step){
    pos t;
    if(x>=0&&y>=0&&x<m&&y<n&&sNum[x][y]&&!(step%sNum[x][y])&&!isVisit[x][y][step]){
        isVisit[x][y][step] = 1;
        t.x = x;
        t.y = y;
        t.step = step;
        q.push(t);
    }
}
int main(){
    scanf("%d%d",&m,&n);
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf(" %c", &sNum[i][j]);
            sNum[i][j] -= '0';
        }
    }
    enqueue((m-1)/2-1,0,1);
    enqueue((m-1)/2,0,1);
    enqueue((m-1)/2+1,0,1);
    while(!q.empty()){
        t = q.front();
        step = t.step+1;
        q.pop();
        if(t.x==(m-1)/2&&t.y == n-1){
            printf("%d\n",t.step);
            break;
        }else if(t.x%2){
            enqueue(t.x-1,t.y-1,step);
            enqueue(t.x-1,t.y,step);
            enqueue(t.x,t.y-1,step);
            enqueue(t.x,t.y+1,step);
            enqueue(t.x+1,t.y-1,step);
            enqueue(t.x+1,t.y,step);
        }else{
            enqueue(t.x-1,t.y,step);
            enqueue(t.x-1,t.y+1,step);
            enqueue(t.x,t.y-1,step);
            enqueue(t.x,t.y+1,step);
            enqueue(t.x+1,t.y,step);
            enqueue(t.x+1,t.y+1,step);
        }
    }
}
