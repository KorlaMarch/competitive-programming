#include "stdio.h"
#include "queue"

typedef struct{
    char x,y,ox,oy;
    short s;
}pos;
pos getP(char x, char y, char ox, char oy, short s){
    pos t;
    t.x = x;
    t.y = y;
    t.ox = ox;
    t.oy = oy;
    t.s = s;
    return t;
}
int a,b,i,j,pr;
char mp[101][101];
char isP[101][101];
pos p;
std::queue<pos> qu;
void place(char x, char y, pos o){
    if(!isP[x][y]){
        isP[x][y] = 1;
        qu.push(getP(x,y,o.x,o.y,o.s+1));
    }else if(x!=p.ox||y!=p.oy){
        printf("%d\n%d %d\n",o.s+1,x+1,y+1);
        pr = 1;
    }

}
int main(){
    scanf("%d%d",&a,&b);
    for(i = 0; i < a; i++){
        for(j = 0; j < b; j++){
            scanf(" %c", &mp[i][j]);
        }
    }
    qu.push(getP(0,0,0,0,1));
    while(!qu.empty()&&!pr){
        p = qu.front();
        qu.pop();
        isP[p.x][p.y] = p.s;
        if(p.x&&(mp[p.x-1][p.y]=='D'||mp[p.x-1][p.y]=='B')) place(p.x-1,p.y,p);
        if(p.y&&(mp[p.x][p.y-1]=='R'||mp[p.x][p.y-1]=='B')) place(p.x,p.y-1,p);
        if(p.x+1<a&&(mp[p.x][p.y]=='D'||mp[p.x][p.y]=='B')) place(p.x+1,p.y,p);
        if(p.y+1<b&&(mp[p.x][p.y]=='R'||mp[p.x][p.y]=='B')) place(p.x,p.y+1,p);
    }
}
