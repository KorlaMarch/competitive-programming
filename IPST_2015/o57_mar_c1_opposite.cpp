#include "stdio.h"
#include "queue"

struct pos{
    int ax,ay,bx,by;
    pos(int _ax = 0, int _ay = 0, int _bx = 0, int _by = 0){
        ax = _ax;
        ay = _ay;
        bx = _bx;
        by = _by;
    }
};

int w,h,i,j,x,y,mnt,mnl;
char mp[35][35];
std::queue<pos> qu[2];
int path[31][31][31][31];
bool isV[31][31][31][31];
pos t;

bool isLe(int x, int y){
    if(x<0||y<0||x>=h||y>=w||mp[x][y]=='#') return false;
    else return true;
}

int main(){
    mnt = 0;
    mnl = -1;
    scanf("%d%d",&w,&h);
    for(i = 0; i < h; i++){
        scanf(" %s", mp[i]);
    }
    //All pair shortest path
    for(i = 0; i < h; i++){
        for(j = 0; j < w; j ++){
            for(x = 0; x < h; x++){
                for(y = 0; y < w; y++){
                    path[i][j][x][y] = -1;
                }
            }
            qu[0].push(pos(i,j));
            path[i][j][i][j] = 0;
            for(x = 0; !qu[x%2].empty(); x++){
                while(!qu[x%2].empty()){
                    t = qu[x%2].front();
                    qu[x%2].pop();
                    if(t.ax>0&&path[i][j][t.ax-1][t.ay]==-1&&mp[t.ax-1][t.ay]!='#'){
                        path[i][j][t.ax-1][t.ay] = x+1;
                        qu[(x+1)%2].push(pos(t.ax-1,t.ay));
                    }
                    if(t.ay>0&&path[i][j][t.ax][t.ay-1]==-1&&mp[t.ax][t.ay-1]!='#'){
                        path[i][j][t.ax][t.ay-1] = x+1;
                        qu[(x+1)%2].push(pos(t.ax,t.ay-1));
                    }
                    if(t.ax+1<h&&path[i][j][t.ax+1][t.ay]==-1&&mp[t.ax+1][t.ay]!='#'){
                        path[i][j][t.ax+1][t.ay] = x+1;
                        qu[(x+1)%2].push(pos(t.ax+1,t.ay));
                    }
                    if(t.ay+1<w&&path[i][j][t.ax][t.ay+1]==-1&&mp[t.ax][t.ay+1]!='#'){
                        path[i][j][t.ax][t.ay+1] = x+1;
                        qu[(x+1)%2].push(pos(t.ax,t.ay+1));
                    }
                }
            }
            /*printf("START %d %d\n",i,j);
            for(x = 0; x < h; x++){
                for(y = 0; y < w; y++){
                    printf("%d ",path[i][j][x][y]);
                }
                printf("\n");
            }*/
        }
    }
    //BFS for answer
    for(i = 0; i < h; i++){
        for(j = 0; j < w; j++){
            if(mp[i][j]=='A'){
                t.ax = i;
                t.ay = j;
            }else if(mp[i][j]=='B'){
                t.bx = i;
                t.by = j;
            }
        }
    }
    qu[0].push(t);
    for(i = 0; !qu[i%2].empty(); i++){
        while(!qu[i%2].empty()){
            t = qu[i%2].front();
            qu[i%2].pop();
            if(path[t.ax][t.ay][t.bx][t.by]!=-1&&(mnl==-1||path[t.ax][t.ay][t.bx][t.by]<mnl)){
                mnl = path[t.ax][t.ay][t.bx][t.by];
                //printf("MIN %d : %d : %d %d %d %d\n",i,mnl,t.ax,t.ay,t.bx,t.by);
                mnt = i;
            }
            ////////
            if(isLe(t.ax+1,t.ay)&&isLe(t.bx-1,t.by)){
                if(!isV[t.ax+1][t.ay][t.bx-1][t.by]){
                    isV[t.ax+1][t.ay][t.bx-1][t.by] = true;
                    qu[(i+1)%2].push(pos(t.ax+1,t.ay,t.bx-1,t.by));
                }
            }else if(isLe(t.ax+1,t.ay)){
                if(!isV[t.ax+1][t.ay][t.bx][t.by]){
                    isV[t.ax+1][t.ay][t.bx][t.by] = true;
                    qu[(i+1)%2].push(pos(t.ax+1,t.ay,t.bx,t.by));
                }
            }else if(isLe(t.bx-1,t.by)){
                if(!isV[t.ax][t.ay][t.bx-1][t.by]){
                    isV[t.ax][t.ay][t.bx-1][t.by] = true;
                    qu[(i+1)%2].push(pos(t.ax,t.ay,t.bx-1,t.by));
                }
            }
            ///////
            if(isLe(t.ax-1,t.ay)&&isLe(t.bx+1,t.by)){
                if(!isV[t.ax-1][t.ay][t.bx+1][t.by]){
                    isV[t.ax-1][t.ay][t.bx+1][t.by] = true;
                    qu[(i+1)%2].push(pos(t.ax-1,t.ay,t.bx+1,t.by));
                }
            }else if(isLe(t.ax-1,t.ay)){
                if(!isV[t.ax-1][t.ay][t.bx][t.by]){
                    isV[t.ax-1][t.ay][t.bx][t.by] = true;
                    qu[(i+1)%2].push(pos(t.ax-1,t.ay,t.bx,t.by));
                }
            }else if(isLe(t.bx+1,t.by)){
                if(!isV[t.ax][t.ay][t.bx+1][t.by]){
                    isV[t.ax][t.ay][t.bx+1][t.by] = true;
                    qu[(i+1)%2].push(pos(t.ax,t.ay,t.bx+1,t.by));
                }
            }

            if(isLe(t.ax,t.ay+1)&&isLe(t.bx,t.by-1)){
                if(!isV[t.ax][t.ay+1][t.bx][t.by-1]){
                    isV[t.ax][t.ay+1][t.bx][t.by-1] = true;
                    qu[(i+1)%2].push(pos(t.ax,t.ay+1,t.bx,t.by-1));
                }
            }else if(isLe(t.ax,t.ay+1)){
                if(!isV[t.ax][t.ay+1][t.bx][t.by]){
                    isV[t.ax][t.ay+1][t.bx][t.by] = true;
                    qu[(i+1)%2].push(pos(t.ax,t.ay+1,t.bx,t.by));
                }
            }else if(isLe(t.bx,t.by-1)){
                if(!isV[t.ax][t.ay][t.bx][t.by-1]){
                    isV[t.ax][t.ay][t.bx][t.by-1] = true;
                    qu[(i+1)%2].push(pos(t.ax,t.ay,t.bx,t.by-1));
                }
            }

            if(isLe(t.ax,t.ay-1)&&isLe(t.bx,t.by+1)){
                if(!isV[t.ax][t.ay-1][t.bx][t.by+1]){
                    isV[t.ax][t.ay-1][t.bx][t.by+1] = true;
                    qu[(i+1)%2].push(pos(t.ax,t.ay-1,t.bx,t.by+1));
                }
            }else if(isLe(t.ax,t.ay-1)){
                if(!isV[t.ax][t.ay-1][t.bx][t.by]){
                    isV[t.ax][t.ay-1][t.bx][t.by] = true;
                    qu[(i+1)%2].push(pos(t.ax,t.ay-1,t.bx,t.by));
                }
            }else if(isLe(t.bx,t.by+1)){
                if(!isV[t.ax][t.ay][t.bx][t.by+1]){
                    isV[t.ax][t.ay][t.bx][t.by+1] = true;
                    qu[(i+1)%2].push(pos(t.ax,t.ay,t.bx,t.by+1));
                }
            }
        }
    }
    printf("%d %d\n",mnl,mnt);
}
