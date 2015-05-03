#include "stdio.h"
typedef struct{
    int x,y,t;
}node;
typedef struct{
    node a[3000];
    int qf,ql;
}queue;
int r,c;
queue w,m;
char mp[51][51];
queue enq(queue q, int x, int y, int t){
    node tm;
    tm.x = x;
    tm.y = y;
    tm.t = t;
    q.a[q.qf] = tm;
    q.qf = (q.qf+1)%3000;
    return q;
}
void bfsW(int t){
    node tmp;
    while(w.qf-w.ql&&w.a[w.ql].t==t){
        tmp = w.a[w.ql];
        w.ql = (w.ql+1)%3000;
        if(tmp.x<0||tmp.y<0||tmp.x>=r||tmp.y>=c||mp[tmp.x][tmp.y]=='X'||mp[tmp.x][tmp.y]=='D'||mp[tmp.x][tmp.y]=='*') continue;
        mp[tmp.x][tmp.y] = '*';
        w = enq(w,tmp.x+1,tmp.y,tmp.t+1);
        w = enq(w,tmp.x-1,tmp.y,tmp.t+1);
        w = enq(w,tmp.x,tmp.y+1,tmp.t+1);
        w = enq(w,tmp.x,tmp.y-1,tmp.t+1);
    }
}
int bfsM(int t){
    node tmp;
    while(m.qf-m.ql&&m.a[m.ql].t==t){
        tmp = m.a[m.ql];
        m.ql = (m.ql+1)%3000;
        if(tmp.x<0||tmp.y<0||tmp.x>=r||tmp.y>=c||mp[tmp.x][tmp.y]=='X'||mp[tmp.x][tmp.y]=='*'||mp[tmp.x][tmp.y]=='S') continue;
        if(mp[tmp.x][tmp.y] == 'D') return 1;
        mp[tmp.x][tmp.y] = 'S';
        m = enq(m,tmp.x+1,tmp.y,tmp.t+1);
        m = enq(m,tmp.x-1,tmp.y,tmp.t+1);
        m = enq(m,tmp.x,tmp.y+1,tmp.t+1);
        m = enq(m,tmp.x,tmp.y-1,tmp.t+1);
    }
    return 0;
}
int main(){
    int i,j;
    scanf("%d%d", &r, &c);
    for(i = 0; i < r; i++){
        scanf(" %s", mp[i]);
        for(j = 0; j < c; j++){
            if(mp[i][j] == 'S'){
                m = enq(m,i,j,0);
                mp[i][j] = '.';
            }else if(mp[i][j] == '*'){
                w = enq(w,i,j,0);
                mp[i][j] = '.';
            }
        }
    }
    for(i = 0; m.qf-m.ql; i++){
        bfsW(i);
        if(bfsM(i)){
            printf("%d\n", i);
            return 0;
        }
    }
    printf("KAKTUS\n");
}
