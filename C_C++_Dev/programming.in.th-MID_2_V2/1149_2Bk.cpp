#include "stdio.h"
#include "queue"
#include "vector"
typedef struct{
    short x,y;
    int a;
}pos;
typedef struct{
    bool operator()(pos a, pos b){
        return a.a>b.a?true:false;
    }
}cmp;
int n,i,j,f,l;
int game[1000][1000];
int mx[1000][1000];
pos st,t;
std::priority_queue<pos,std::vector<pos>,cmp> qu;
int max(int a, int b){
    return a>b?a:b;
}
void enq(short x, short y, int a){
    pos t;
    t.x = x;
    t.y = y;
    t.a = max(game[x][y],a);
    if(!mx[x][y]||(t.a<mx[x][y])){
        mx[x][y] = t.a;
        qu.push(t);
    }
}
int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf(" %d", &game[i][j]);
            if(!game[i][j]){
                st.x = i;
                st.y = j;
            }
        }
    }
    st.a = 0;
    game[st.x][st.y] = 2000000;
    qu.push(st);
    while(!qu.empty()){
        t = qu.top();
        qu.pop();
        if(t.a==mx[t.x][t.y]){
            if(game[t.x][t.y]==0){
                printf("%d\n",t.a);
                break;
            }
            if(t.x) enq(t.x-1,t.y,t.a);
            if(t.y) enq(t.x,t.y-1,t.a);
            if(t.x+1<n) enq(t.x+1,t.y,t.a);
            if(t.y+1<n) enq(t.x,t.y+1,t.a);
        }
    }
}
