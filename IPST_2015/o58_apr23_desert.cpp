#include "stdio.h"
#include "queue"
#include "algorithm"
#include "vector"

struct pos{
    int x,y,w;
    pos(int _x = 0, int _y = 0, int _w = 0): x(_x), y(_y), w(_w) {}
    bool operator()(pos a, pos b){
        return a.w<b.w;
    }
};

int r,c,m,i,j,k,x,y,lc,maxA;
bool mp[305][305];
int qs[2][305][305];
bool isV[305][305];
std::priority_queue<pos,std::vector<pos>,pos> qu;

void enq(int x, int y, int w, int ind){
    if(!isV[x][y]&&std::min(w,qs[ind][x][y])!=0){
        isV[x][y] = true;
        qu.push(pos(x,y,std::min(w,qs[ind][x][y])));
    }
}

void bfs(int ind, int h){
    pos t;
    int i,j;
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            isV[i][j] = false;
        }
    }
    while(!qu.empty()) qu.pop();
    qu.push(pos(0,0,qs[ind][0][0]));
    isV[0][0] = true;
    while(!qu.empty()){
        t = qu.top();
        qu.pop();
        if(t.x+h==r&&t.y+t.w==c){
            if(t.w*h>maxA){
                maxA = t.w*h;
            }
            return;
        }
        if(t.x>0) enq(t.x-1,t.y,t.w,ind);
        if(t.y>0) enq(t.x,t.y-1,t.w,ind);
        if(t.x+1<r) enq(t.x+1,t.y,t.w,ind);
        if(t.y+1<c) enq(t.x,t.y+1,t.w,ind);
    }
}

int main(){
    scanf("%d%d%d",&r,&c,&m);
    for(i = 0; i < m; i++){
        scanf("%d%d",&x,&y);
        mp[x][y] = true;
    }
    for(i = 0; i < r; i++){
        for(j = c-1,lc = c; j >= 0; j--){
            if(mp[i][j]){
                lc = j;
            }else{
                qs[1][i][j] = lc-j;
            }
        }
    }
    bfs(1,1);
    for(k = 2; k <= r; k++){
        for(i = 0; i+1 < r; i++){
            for(j = 0; j < c; j++){
                qs[k%2][i][j] = std::min(qs[!(k%2)][i][j],qs[!(k%2)][i+1][j]);
            }
        }
        for(j = 0; j < c; j++) qs[k%2][r-1][j] = 0;
        bfs(k%2,k);
    }
    printf("%d\n",maxA);
}
