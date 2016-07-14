#include "stdio.h"
#include "vector"
#include "queue"

typedef struct{
    int x,y,t;
}pos;
typedef struct{
    bool operator()(pos a, pos b){
        return a.t>b.t?true:false;
    }
}cmp;
int n,i,j,minP;
char mp[1000][1000];
int minT[1000][1000];
int toP[4][1000][1000];
std::priority_queue<pos,std::vector<pos>,cmp> qu;
pos p,t;

int main(){
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d",&mp[i][j]);
        }
    }
    //up
    for(j=0; j < n; j++){
        for(i=minP=0; i < n; i++){
            if(mp[i][j]) minP = i+1;
            else toP[0][i][j] = minP;
        }
    }
    //down
    for(j=0; j < n; j++){
        for(i=minP=n-1; i >= 0; i--){
            if(mp[i][j]) minP = i-1;
            else toP[1][i][j] = minP;
        }
    }
    //left
    for(i=0; i < n; i++){
        for(j=minP=0; j < n; j++){
            if(mp[i][j]) minP = j+1;
            else toP[2][i][j] = minP;
        }
    }
    //right
    for(i=0; i < n; i++){
        for(j=minP=n-1; j >= 0; j--){
            if(mp[i][j]) minP = j-1;
            else toP[3][i][j] = minP;
        }
    }

    t.x = t.y = t.t = 0;
    minT[0][0] = -1;
    qu.push(t);
    while(!qu.empty()){
        p = qu.top();
        qu.pop();
        if(p.x == n-1 && p.y == n-1){
            printf("%d\n", p.t);
            break;
        }else{
            if(!minT[toP[0][p.x][p.y]][p.y]|| p.t + p.x-toP[0][p.x][p.y] < minT[toP[0][p.x][p.y]][p.y]){
                t.x = toP[0][p.x][p.y];
                t.y = p.y;
                t.t = p.t + p.x-toP[0][p.x][p.y];
                minT[toP[0][p.x][p.y]][p.y] = t.t;
                qu.push(t);
            }
            if(!minT[toP[1][p.x][p.y]][p.y]|| p.t + toP[1][p.x][p.y]-p.x < minT[toP[1][p.x][p.y]][p.y]){
                t.x = toP[1][p.x][p.y];
                t.y = p.y;
                t.t = p.t + toP[1][p.x][p.y]-p.x;
                minT[toP[1][p.x][p.y]][p.y] = t.t;
                qu.push(t);
            }
            if(!minT[p.x][toP[2][p.x][p.y]]|| p.t + p.y-toP[2][p.x][p.y] < minT[p.x][toP[2][p.x][p.y]]){
                t.x = p.x;
                t.y = toP[2][p.x][p.y];
                t.t = p.t + p.y-toP[2][p.x][p.y];
                minT[p.x][toP[2][p.x][p.y]] = t.t;
                qu.push(t);
            }
            if(!minT[p.x][toP[3][p.x][p.y]]|| p.t + toP[3][p.x][p.y]-p.y < minT[p.x][toP[3][p.x][p.y]]){
                t.x = p.x;
                t.y = toP[3][p.x][p.y];
                t.t = p.t + toP[3][p.x][p.y]-p.y;
                minT[p.x][toP[3][p.x][p.y]] = t.t;
                qu.push(t);
            }
        }
    }
}
