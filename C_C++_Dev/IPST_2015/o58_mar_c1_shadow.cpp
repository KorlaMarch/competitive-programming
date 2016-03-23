#include "stdio.h"
#include "queue"
#include "vector"

struct pos{
    int x,y,t;
    char di;
    pos(int _x = 0, int _y = 0, int _t = 0, char _di = 'D'){
        x = _x;
        y = _y;
        t = _t;
        di = _di;
    }
    bool operator()(pos a, pos b){
        return a.t>b.t;
    }
};

int n,m,i,j,x,y,v;
int c[2005],d[2005];
bool mp[2005][2005];
int minV[2005][2005][2];
std::priority_queue<pos,std::vector<pos>,pos> qu;
pos t;

int main(){
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        scanf("%d",&c[i]);
    }
    for(i = 0; i < n; i++){
        scanf("%d",&d[i]);
    }
    for(i = 0; i < m; i++){
        scanf("%d%d",&x,&y);
        mp[x][y] = true;
    }
    qu.push(pos());
    while(!qu.empty()){
        t = qu.top();
        qu.pop();
        if(t.x==n-1&&t.y==n-1){
            break;
        }
        if(t.di=='D') v = 0;
        else v = 1;
        if(minV[t.x][t.y][v]!=0&&t.t>=minV[t.x][t.y][v]) continue;
        minV[t.x][t.y][v] = t.t;
        //stay the same direction
        if(t.di == 'D'){
            if(t.x+1<n){
                qu.push(pos(t.x+1,t.y,t.t,'D'));
            }
            if(t.y+1<n) qu.push(pos(t.x,t.y,t.t,'L'));
        }else if(t.di == 'L'){
            if(t.y+1<n){
                if(t.y+1<n-1-t.x){
                    v = c[t.y+1];
                }else{
                    v = d[t.y+1];
                }
                if(mp[t.x][t.y+1]){
                    qu.push(pos(t.x,t.y+1,t.t+v,'D'));
                }else{
                    qu.push(pos(t.x,t.y+1,t.t+v,'L'));
                }
            }
        }
    }
    printf("%d\n",t.t);
}
