#include "stdio.h"
#include "queue"
typedef struct{
    int x,y;
}pos;
pos makepos(int x, int y){
    pos t;
    t.x = x;
    t.y = y;
    return t;
}
std::queue<pos> qu;
char mp[155][155];
int disS[155][155],disE[155][155];
int m,n,i,j,minD,minC,d1,d2;
pos s,e,t;

int main(){
    scanf("%d%d %d%d %d%d",&m,&n,&s.x,&s.y,&e.x,&e.y);
    s.x--,s.y--,e.x--,e.y--;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d",&mp[i][j]);
        }
    }
    disS[s.x][s.y] = 1;
    qu.push(s);
    while(!qu.empty()){
        t = qu.front();
        qu.pop();
        if(t.x&&mp[t.x-1][t.y]&&!disS[t.x-1][t.y]){
            disS[t.x-1][t.y] = disS[t.x][t.y]+1;
            qu.push(makepos(t.x-1,t.y));
        }
        if(t.x+1<m&&mp[t.x+1][t.y]&&!disS[t.x+1][t.y]){
            disS[t.x+1][t.y] = disS[t.x][t.y]+1;
            qu.push(makepos(t.x+1,t.y));
        }
        if(t.y&&mp[t.x][t.y-1]&&!disS[t.x][t.y-1]){
            disS[t.x][t.y-1] = disS[t.x][t.y]+1;
            qu.push(makepos(t.x,t.y-1));
        }
        if(t.y+1<n&&mp[t.x][t.y+1]&&!disS[t.x][t.y+1]){
            disS[t.x][t.y+1] = disS[t.x][t.y]+1;
            qu.push(makepos(t.x,t.y+1));
        }
    }

    disE[e.x][e.y] = 1;
    qu.push(e);
    while(!qu.empty()){
        t = qu.front();
        qu.pop();
        if(t.x&&mp[t.x-1][t.y]&&!disE[t.x-1][t.y]){
            disE[t.x-1][t.y] = disE[t.x][t.y]+1;
            qu.push(makepos(t.x-1,t.y));
        }
        if(t.x+1<m&&mp[t.x+1][t.y]&&!disE[t.x+1][t.y]){
            disE[t.x+1][t.y] = disE[t.x][t.y]+1;
            qu.push(makepos(t.x+1,t.y));
        }
        if(t.y&&mp[t.x][t.y-1]&&!disE[t.x][t.y-1]){
            disE[t.x][t.y-1] = disE[t.x][t.y]+1;
            qu.push(makepos(t.x,t.y-1));
        }
        if(t.y+1<n&&mp[t.x][t.y+1]&&!disE[t.x][t.y+1]){
            disE[t.x][t.y+1] = disE[t.x][t.y]+1;
            qu.push(makepos(t.x,t.y+1));
        }
    }

    for(i = 0,minD = 100000,minC = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(!mp[i][j]){
                d1 = d2 = 0;
                if(i&&disS[i-1][j]&&(!d1||disS[i-1][j]<d1)) d1 = disS[i-1][j];
                if(i+1<m&&disS[i+1][j]&&(!d1||disS[i+1][j]<d1)) d1 = disS[i+1][j];
                if(j&&disS[i][j-1]&&(!d1||disS[i][j-1]<d1)) d1 = disS[i][j-1];
                if(j+1<n&&disS[i][j+1]&&(!d1||disS[i][j+1]<d1)) d1 = disS[i][j+1];

                if(i&&disE[i-1][j]&&(!d2||disE[i-1][j]<d2)) d2 = disE[i-1][j];
                if(i+1<m&&disE[i+1][j]&&(!d2||disE[i+1][j]<d2)) d2 = disE[i+1][j];
                if(j&&disE[i][j-1]&&(!d2||disE[i][j-1]<d2)) d2 = disE[i][j-1];
                if(j+1<n&&disE[i][j+1]&&(!d2||disE[i][j+1]<d2)) d2 = disE[i][j+1];

                if(d1&&d2){
                    minC++;
                    if(d1+d2<minD){
                        minD = d1+d2;
                    }
                }
            }
            //printf("%d ",disE[i][j]);
        }
        //printf("\n");
    }
    printf("%d\n%d\n",minC,minD+1);
}
