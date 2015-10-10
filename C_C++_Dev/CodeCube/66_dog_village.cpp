#include "stdio.h"
#include "queue"

typedef struct{
    int x,y;
}vi;
vi getVi(int x, int y){
    vi t;
    t.x = x;
    t.y = y;
    return t;
}
std::queue<vi> qu[2];
vi t;
int n,m,i,j,cu;
int day[1001][1001];

void spVi(int x, int y, int d){
    if(day[x][y]<=d) return;
    day[x][y] = 0;
    qu[(d+1)%2].push(getVi(x,y));
}

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d",&day[i][j]);
            if(day[i][j]==0) qu[1].push(getVi(i,j));
        }
    }
    for(i = 1; !qu[i%2].empty(); i++){
        while(!qu[i%2].empty()){
            t = qu[i%2].front();
            qu[i%2].pop();
            if(t.x+1<n) spVi(t.x+1,t.y,i);
            if(t.y+1<m) spVi(t.x,t.y+1,i);
            if(t.x-1>=0) spVi(t.x-1,t.y,i);
            if(t.y-1>=0) spVi(t.x,t.y-1,i);
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(!day[i][j]) cu++;
        }
    }
    printf("%d\n",n*m-cu);
}
