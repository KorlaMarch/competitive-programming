#include "stdio.h"
#include "queue"

struct node{
    int x,y,d,di;
    bool o;
};
node getNode(int x, int y, int d, int di, bool o){
    node tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.d = d;
    tmp.di = di;
    tmp.o = o;
    return tmp;
}
int n,m,i,j,f;
char mp[1005][1005];
bool isV[1005][1005][4][2];
node t;
std::queue<node> qu;
bool enq(node no){
    if(no.x<0||no.y<0||no.x>n||no.y>m||mp[no.x][no.y]==0||(mp[no.x][no.y]==3&&!no.o)) return false;
    if(isV[no.x][no.y][no.d][(int)no.o]) return true;
    isV[no.x][no.y][no.d][(int)no.o] = 1;
    qu.push(no);
    return true;
}
int main(){
    freopen("dream.in","r",stdin);
    freopen("dream.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d",&mp[i][j]);
        }
    }
    enq(getNode(0,0,0,0,false));
    while(!qu.empty()){
        t = qu.front();
        qu.pop();
        if(t.x==n-1&&t.y==m-1){
            printf("%d\n",t.di);
            f = 1;
            break;
        }
        switch(mp[t.x][t.y]){
        case 3: //blue
            if(!t.o) break;
        case 2: //orange
            t.o = true;
        case 4: //purple
            if(mp[t.x][t.y]==4){
                t.o = false;
                if(t.d==0){
                    if(enq(getNode(t.x+1,t.y,0,t.di+1,t.o))) break;
                }else if(t.d==1){
                    if(enq(getNode(t.x-1,t.y,1,t.di+1,t.o))) break;
                }else if(t.d==2){
                    if(enq(getNode(t.x,t.y-1,2,t.di+1,t.o))) break;
                }else if(t.d==3){
                    if(enq(getNode(t.x,t.y+1,3,t.di+1,t.o))) break;
                }
            }
        case 1: //pink
            enq(getNode(t.x+1,t.y,0,t.di+1,t.o));
            enq(getNode(t.x-1,t.y,1,t.di+1,t.o));
            enq(getNode(t.x,t.y-1,2,t.di+1,t.o));
            enq(getNode(t.x,t.y+1,3,t.di+1,t.o));
            break;
        case 0: //red
            break;
        }
    }
    if(!f) printf("-1\n");
}
