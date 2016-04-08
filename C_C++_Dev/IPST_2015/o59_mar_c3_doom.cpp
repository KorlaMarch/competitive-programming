#include "stdio.h"
#include "stack"
#include "vector"
struct pos{
    char x,y;
    short v;
    pos(char _x = 0, char _y = 0, short _v = 0) : x(_x), y(_y), v(_v) {}
};

int r,c,k,i,j;
bool isAns,canR;
bool isV[101][101][35000];
bool isV2[101][101];
char mp[105][105];
std::stack<pos,std::vector<pos>> qu[2];
pos t;

void moveTo(char x, char y, short v, char ind){
    if(mp[x][y]=='#') return;
    else if(mp[x][y]=='Z'){
        isAns = true;
        return;
    }else if(mp[x][y]>='a'&&mp[x][y]<'z'){
        v = (v|(1<<(mp[x][y]-'a')));
        if(!isV[x][y][v]){
            isV[x][y][v] = true;
            qu[ind].push(pos(x,y,v));
        }
    }else if(mp[x][y]>='A'&&mp[x][y]<'Z'){
        if(((v>>(mp[x][y]-'A'))&1)==1&&!isV[x][y][v]){
            isV[x][y][v] = true;
            qu[ind].push(pos(x,y,v));
        }
    }else{
        if(!isV[x][y][v]){
            isV[x][y][v] = true;
            qu[ind].push(pos(x,y,v));
        }
    }
}

void dfsCh(int x, int y){
    if(isV2[x][y]||mp[x][y]=='#') return;
    else if(mp[x][y]=='Z'){
        canR = true;
    }
    isV2[x][y] = true;
    if(x>0) dfsCh(x-1,y);
    if(y>0) dfsCh(x,y-1);
    if(x+1<r) dfsCh(x+1,y);
    if(y+1<c) dfsCh(x,y+1);
}

int main(){
    scanf("%d%d%d",&r,&c,&k);
    for(i = 0; i < r; i++){
        scanf(" %s",mp[i]);
    }

    for(i = 0; i < r && qu[0].empty(); i++){
        for(j = 0; j < c; j++){
            if(mp[i][j]=='z'){
                qu[0].push(pos(i,j));
                canR = false;
                dfsCh(i,j);
                break;
            }
        }
    }
    if(canR){
        for(i = 0; !qu[i%2].empty(); i++){
            while(!qu[i%2].empty()){
                t = qu[i%2].top();
                qu[i%2].pop();
                if(t.x>0) moveTo(t.x-1,t.y,t.v,(i+1)%2);
                if(t.y>0) moveTo(t.x,t.y-1,t.v,(i+1)%2);
                if(t.x+1<r) moveTo(t.x+1,t.y,t.v,(i+1)%2);
                if(t.y+1<c) moveTo(t.x,t.y+1,t.v,(i+1)%2);
            }
            if(isAns){
                printf("%d\n",i+1);
                break;
            }
        }
    }else printf("-1\n");
}
