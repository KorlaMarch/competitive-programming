#include "stdio.h"
#include "queue"

typedef struct{
    int r,c;
}pos;

int maze[200][200];
int distance[200][200];
int m,n;

void setDis(int r, int c, int fr, int fc, int sign){
    maze[r][c] = sign;
    distance[r][c] = distance[fr][fc]+1;
}

void flood(pos s, int sign){
    std::queue<pos> q;
    pos t,t2;
    q.push(s);
    maze[s.r][s.c] = sign;
    distance[s.r][s.c] = 1;
    while(!q.empty()){
        t = q.front();
        q.pop();
        //printf("sign = %d pop %d %d\n", sign, t.r, t.c);
        if(t.r > 0 && maze[t.r-1][t.c] == 1){
            setDis(t.r-1,t.c,t.r,t.c,sign);
            t2.r = t.r-1;
            t2.c = t.c;
            q.push(t2);
        }
        if(t.c > 0 && maze[t.r][t.c-1] == 1){
            setDis(t.r,t.c-1,t.r,t.c,sign);
            t2.r = t.r;
            t2.c = t.c-1;
            q.push(t2);
        }
        if(t.r+1 < m && maze[t.r+1][t.c] == 1){
            setDis(t.r+1,t.c,t.r,t.c,sign);
            t2.r = t.r+1;
            t2.c = t.c;
            q.push(t2);
        }
        if(t.c+1 < n && maze[t.r][t.c+1] == 1){
            setDis(t.r,t.c+1,t.r,t.c,sign);
            t2.r = t.r;
            t2.c = t.c+1;
            q.push(t2);
        }
    }
}

int findMinD(int x, int y, int sign){
    int min = 9999999;
    if(x > 0 && maze[x-1][y] == sign){
        if(distance[x-1][y] < min){
            min = distance[x-1][y];
        }
    }
    if(y > 0 && maze[x][y-1] == sign){
        if(distance[x][y-1] < min){
            min = distance[x][y-1];
        }
    }
    if(x+1 < m && maze[x+1][y] == sign){
        if(distance[x+1][y] < min){
            min = distance[x+1][y];
        }
    }
    if(y+1 < n && maze[x][y+1] == sign){
        if(distance[x][y+1] < min){
            min = distance[x][y+1];
        }
    }
    return min == 9999999 ? -1 : min;
}

int main(){
    int i,j,x,y;
    int c = 0,minD = 999999;
    pos s,e;
    scanf("%d%d",&m,&n);
    scanf("%d%d", &s.r, &s.c);
    scanf("%d%d", &e.r, &e.c);
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &maze[i][j]);
        }
    }
    s.r--;
    s.c--;
    e.r--;
    e.c--;
    flood(s, 2);
    flood(e, 3);
    //printf("\n");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            //printf("%d ", distance[i][j]);
            if(maze[i][j] == 0){
                x = findMinD(i,j,2);
                y = findMinD(i,j,3);
                if(x != -1 && y != -1){
                    if(x+y+1 < minD){
                        minD = x+y+1;
                    }
                    c++;
                }
            }
        }
        //printf("\n");
    }
    printf("%d\n%d\n",c,minD);
}
