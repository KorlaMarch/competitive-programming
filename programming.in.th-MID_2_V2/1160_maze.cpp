#include "stdio.h"
#include "queue"
typedef struct{
    int x,y;
}pos;
int m,n,i,j,c,x,y,minD;
pos s,e;
std::queue<pos> qu;
char mp[150][150];
int dis[2][150][150];

void pu(int i, int j, int p, int d){
    pos t;
    if(mp[i][j]=='1'&&!dis[p][i][j]){
        dis[p][i][j] = d;
        t.x = i;
        t.y = j;
        qu.push(t);
    }
}

void bfs(int p,pos st){
    pos t;
    int d;
    st.x--,st.y--;
    dis[p][st.x][st.y] = 1;
    qu.push(st);
    while(!qu.empty()){
        t = qu.front();
        d = dis[p][t.x][t.y]+1;
        qu.pop();
        if(t.x) pu(t.x-1,t.y,p,d);
        if(t.y) pu(t.x,t.y-1,p,d);
        if(t.x+1<m) pu(t.x+1,t.y,p,d);
        if(t.y+1<n) pu(t.x,t.y+1,p,d);
    }
}

int getMinDis(int i, int j, int p){
    int m = 100000;
    if(i&&dis[p][i-1][j]&&dis[p][i-1][j]<m) m = dis[p][i-1][j];
    if(j&&dis[p][i][j-1]&&dis[p][i][j-1]<m) m = dis[p][i][j-1];
    if(i+1<m&&dis[p][i+1][j]&&dis[p][i+1][j]<m) m = dis[p][i+1][j];
    if(j+1<n&&dis[p][i][j+1]&&dis[p][i][j+1]<m) m = dis[p][i][j+1];
    if(m==100000) return 0;
    else return m;
}

int main(){
    scanf("%d %d %d %d %d %d",&m,&n,&s.x,&s.y,&e.x,&e.y);
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf(" %c", &mp[i][j]);
        }
    }
    bfs(0,s);
    bfs(1,e);
    for(i=c=0,minD=100000; i < m; i++){
        for(j = 0; j < n; j++){
            if(mp[i][j]=='0'){
                x = getMinDis(i,j,0);
                y = getMinDis(i,j,1);
                if(x&&y){
                    c++;
                    if(x+y<minD) minD = x+y;
                }
            }
        }
    }
    printf("%d\n%d\n",c,minD+1);
}
