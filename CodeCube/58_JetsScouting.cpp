#include "stdio.h"
#include "queue"
typedef struct{
    int x,y,d;
}pos;
pos getN(int x, int y, int d){
    pos t;
    t.x = x;
    t.y = y;
    t.d = d;
    return t;
}
pos getD(int d){
    switch(d){
        case 0: return getN(-1,0,0);
        case 1: return getN(-1,1,0);
        case 2: return getN(0,1,0);
        case 3: return getN(1,1,0);
        case 4: return getN(1,0,0);
        case 5: return getN(1,-1,0);
        case 6: return getN(0,-1,0);
        case 7: return getN(-1,-1,0);
    }
}

int r,c,x,y,n,i,j,mi;
pos s,p,t;
char mp[301][301];
int minMir[300][300][8];
std::queue<pos> qu[2],tmp;

char canM(int x, int y, int d){
    return x>=0&&y>=0&&x<r&&y<c&&mp[x][y]!='#'&&!minMir[x][y][d];
}
int main(){
    scanf("%d%d%d",&r,&c,&n);
    for(i =0,s.x=-1; i < r; i++){
        scanf(" %s",mp[i]);
        if(s.x==-1) for(j = 0; j < c; j++){
            if(mp[i][j]=='J'){
                s.x = i;
                s.y = j;
                break;
            }
        }
    }
    for(i = 0; i < 8; i++){
        qu[0].push(getN(s.x,s.y,i));
        minMir[s.x][s.y][i] = 2;
    }
    for(i = 2;!qu[i%2].empty(); i++){
        while(!qu[i%2].empty()){
            p = qu[i%2].front();
            qu[i%2].pop();
            tmp.push(p);
            t = getD(p.d);
            if(canM(p.x+t.x,p.y+t.y,p.d)){
                minMir[p.x+t.x][p.y+t.y][p.d] = i;
                qu[i%2].push(getN(p.x+t.x,p.y+t.y,p.d));
            }
        }
        while(!tmp.empty()){
            p = tmp.front();
            tmp.pop();
            j = (p.d+2)%8;
                if(canM(p.x,p.y,j)){
                    minMir[p.x][p.y][j] = i+1;
                    qu[(i+1)%2].push(getN(p.x,p.y,j));
                }
            j = (p.d+6)%8;
                if(canM(p.x,p.y,j)){
                    minMir[p.x][p.y][j] = i+1;
                    qu[(i+1)%2].push(getN(p.x,p.y,j));
                }
        }
    }
    /*printf("MINMIR:\n");
    for(i = 0; i < 8; i++){
        printf("\t%d:\n",i);
        for(x = 0; x < r; x++){
            for(y = 0; y < c; y++){
                printf("%d ",minMir[x][y][i]);
            }
            printf("\n");
        }
    }*/
    for(i = 0; i < n; i++){
        scanf("%d%d",&x,&y);
        for(j = 0,mi=1; j < 8; j++){
            if(minMir[x-1][y-1][j]&&(mi==1||minMir[x-1][y-1][j]<mi)) mi = minMir[x-1][y-1][j];
        }
        printf("%d\n",mi-2);
    }
}
