#include "stdio.h"
#include "queue"
#include "algorithm"

#define x first
#define y second

int n,m,i,j,t,mi;
int mp[1000][1000];
int sq[10001];
std::queue<std::pair<int,int>> qu[2];

void genSeq(){
    int i,j,t;
    for(t = 0,i = 1; t < 10000; i++){
        for(j = 1; j <= i && t < 10000; j++){
            sq[t++] = j;
        }
    }
}

void enq(int x, int y, int ch, int ind){
    if(x>=0&&y>=0&&x<n&&y<m&&mp[x][y]==ch){
        qu[ind].push(std::make_pair(x,y));
    }
}

void bfs(int sy){
    int i,j;
    std::pair<int,int> t;
    qu[1].push(std::make_pair(0,sy));
    for(i = 1; !qu[i%2].empty(); i++){
        while(!qu[i%2].empty()){
            t = qu[i%2].front();
            qu[i%2].pop();
            //printf("%d [%d]: %d %d : %d\n",i,sq[i],t.x+1,t.y+1,mp[t.x][t.y]);
            if(t.x==n-1){
                if(t.y<mi) mi = t.y;
                continue;
            }else{
                enq(t.x-1,t.y,sq[i],(i+1)%2);
                enq(t.x+1,t.y,sq[i],(i+1)%2);
                enq(t.x,t.y-1,sq[i],(i+1)%2);
                enq(t.x,t.y+1,sq[i],(i+1)%2);
            }
        }
    }
}

int main(){
    genSeq();
    for(scanf("%d",&t); t > 0; t--){
        scanf("%d%d",&n,&m);
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                scanf("%d",&mp[i][j]);
            }
        }
        mi = 1000;
        for(i = 0; i < m && mi == 1000; i++){
            if(mp[0][i]==1) bfs(i);
        }
        printf("%d %d\n%d %d\n",1,i,n,mi+1);
        if(t>1) printf("\n");
    }
}
