#include "stdio.h"
#include "queue"
#include "vector"

int minDis[101][101];

struct pos{
    char x,y;
    short v;
    int t;
    pos(char _x = 0, char _y = 0, short _v = 0, int _t = 0) : x(_x), y(_y), v(_v), t(_t){}
    bool operator()(pos a, pos b){
        return minDis[a.x][a.y]+a.t>minDis[b.x][b.y];+b.t;
    }
};

int r,c,k,i,j;
bool isAns,canR;
bool isV[101][101][35000];
bool isV2[101][101];
char mp[105][105];
std::priority_queue<pos,std::vector<pos>,pos> qu;
std::queue<pos> qu2;
pos t;

void moveTo(char x, char y, short v, int t){
    if(mp[x][y]=='#') return;
    else if(mp[x][y]=='Z'){
        isAns = true;
        return;
    }else if(mp[x][y]>='a'&&mp[x][y]<'z'){
        v = (v|(1<<(mp[x][y]-'a')));
        if(isV[x][y][v]) return;
    }else if(mp[x][y]>='A'&&mp[x][y]<'Z'){
        if(((v>>(mp[x][y]-'A'))&1)!=1||isV[x][y][v]) return;
    }else{
        if(isV[x][y][v]) return;
    }
    isV[x][y][v] = true;
    qu.push(pos(x,y,v,t));
}

void pushQU(int x, int y, int d){
    if(isV2[x][y]||mp[x][y]=='#') return;
    isV2[x][y] = true;
    minDis[x][y] = d;
    qu2.push(pos(x,y,0,d));
}

void bfsCh(int x, int y){
    pushQU(x,y,0);
    while(!qu2.empty()){
        t = qu2.front();
        qu2.pop();
        if(t.x>0) pushQU(t.x-1,t.y,t.t+1);
        if(t.y>0) pushQU(t.x,t.y-1,t.t+1);
        if(t.x+1<r) pushQU(t.x+1,t.y,t.t+1);
        if(t.y+1<c) pushQU(t.x,t.y+1,t.t+1);
    }
}

int main(){
    scanf("%d%d%d",&r,&c,&k);
    for(i = 0; i < r; i++){
        scanf(" %s",mp[i]);
    }

    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            if(mp[i][j]=='z'){
                qu.push(pos(i,j));
            }else if(mp[i][j]=='Z'){
                bfsCh(i,j);
            }
        }
    }
    if(isV2[qu.top().x][qu.top().y]){
        while(!qu.empty()){
            t = qu.top();
            qu.pop();
            //printf("%d %d %d\n",t.x,t.y,t.t);
            if(t.x>0) moveTo(t.x-1,t.y,t.v,t.t+1);
            if(t.y>0) moveTo(t.x,t.y-1,t.v,t.t+1);
            if(t.x+1<r) moveTo(t.x+1,t.y,t.v,t.t+1);
            if(t.y+1<c) moveTo(t.x,t.y+1,t.v,t.t+1);
            if(isAns){
                printf("%d\n",t.t+1);
                break;
            }
        }
    }else printf("-1\n");
}
