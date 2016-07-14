#include "stdio.h"
#include "queue"
#include "vector"
#include "algorithm"
typedef struct{
    int x,y,t;
    char ty;
}pos;
pos getPos(int x, int y, int t, char ty){
    pos tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.t = t;
    tmp.ty = ty;
    return tmp;
}
bool cmp(pos a, pos b){
    return a.t<b.t;
}
class cmp2{
public:
    bool operator()(pos a, pos b){
        return a.t==b.t?(a.ty=='G'):(a.t>b.t);
    }
};
using namespace std;
int k,R,C,r,c,n,T,i,j,t,pt,isPW;
pos tmp,s;
pos gh[200];
char mp[200][200];
priority_queue<pos,vector<pos>,cmp2> qu;
void enP(int x, int y, int t){
    if(x>=0&&y>=0&&x<R&&y<C&&mp[x][y]=='.'){
        mp[x][y] = 'P';
        qu.push(getPos(x,y,t,'P'));
    }
}
void enG(int x, int y, int t){
    if(x>=0&&y>=0&&x<R&&y<C&&(mp[x][y]=='.'||mp[x][y]=='P')){
        //printf("MP %d %d %c\n",x,y,mp[x][y]);
        mp[x][y] = 'G';
        qu.push(getPos(x,y,t,'G'));
    }
}
void printM(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            putchar(mp[i][j]);
        }
        putchar('\n');
    }
    printf("\n");
}
int main(){
    for(scanf("%d",&k);k>0;k--){
        scanf("%d%d%d%d%d%d",&R,&C,&n,&T,&r,&c);
        for(i = 0; i < n; i++){
            scanf("%d%d%d",&gh[i].t,&gh[i].x,&gh[i].y);
            gh[i].ty = 'G';
        }
        std::sort(gh,gh+n,cmp);
        for(i = 0; i < R; i++){
            scanf(" %s",mp[i]);
        }
        t = 0;
        pt = 0;
        while(!qu.empty()) qu.pop();
        enP(r,c,0);
        while(pt<n&&gh[pt].t==0){
            enG(gh[pt].x,gh[pt].y,0);
            pt++;
        }
        while(!qu.empty()){
            tmp = qu.top();
            qu.pop();
            //printf("TMP: %d %d %d %c\n",tmp.x,tmp.y,tmp.t,tmp.ty);
            if(tmp.t!=t){
                t++;
                while(pt<n&&gh[pt].t==t){
                    enG(gh[pt].x,gh[pt].y,t);
                    pt++;
                }
                printf("t = %d\n", t);
                printM();
                if(t>=T) break;
            }
            if(tmp.ty=='P'){
                if(mp[tmp.x][tmp.y]=='G'){
                    continue;
                }else{
                    enP(tmp.x+1,tmp.y,tmp.t+1);
                    enP(tmp.x-1,tmp.y,tmp.t+1);
                    enP(tmp.x,tmp.y+1,tmp.t+1);
                    enP(tmp.x,tmp.y-1,tmp.t+1);
                }
            }else{
                enG(tmp.x+1,tmp.y,tmp.t+1);
                enG(tmp.x-1,tmp.y,tmp.t+1);
                enG(tmp.x,tmp.y+1,tmp.t+1);
                enG(tmp.x,tmp.y-1,tmp.t+1);
            }
        }
        for(i = 0,isPW = 0; i < R && !isPW; i++){
            for(j = 0; j < C; j++){
                //printf("%c",mp[i][j]);
                if(mp[i][j]=='P'){
                    isPW = 1;
                    break;
                }
            }
            //printf("\n");
        }
        if(isPW) printf("YES\n");
        else printf("NO\n");
    }
}
