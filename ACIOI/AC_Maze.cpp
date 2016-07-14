#include "stdio.h"
#include "queue"

typedef struct{
    int x,y;
}pos;

char maze[71][71];
int m,n;

int getShortestPart(char c){
    int i,j;
    bool isFind = false;
    int numMap[71][71];
    pos loc,t;
    std::queue<pos> q;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            numMap[i][j] = -1;
        }
    }
    for(i = 0; i < m && !isFind; i++){
        for(j = 0; j < n && !isFind; j++){
            if(maze[i][j] == c){
                isFind = true;
                numMap[i][j] = 0;
                t.x = i;
                t.y = j;
                q.push(t);
            }
        }
    }
    while(!q.empty()){
        loc = q.front();
        q.pop();
        if(maze[loc.x][loc.y] == 'Y'){
            return numMap[loc.x][loc.y];
        }
        if(loc.x > 0 && maze[loc.x-1][loc.y] != '#' && numMap[loc.x-1][loc.y] == -1){
            t.x = loc.x-1;
            t.y = loc.y;
            numMap[loc.x-1][loc.y] = numMap[loc.x][loc.y]+1;
            q.push(t);
        }
        if(loc.x+1 < m && maze[loc.x+1][loc.y] != '#' && numMap[loc.x+1][loc.y] == -1){
            t.x = loc.x+1;
            t.y = loc.y;
            numMap[loc.x+1][loc.y] = numMap[loc.x][loc.y]+1;
            q.push(t);
        }
        if(loc.y > 0 && maze[loc.x][loc.y-1] != '#' && numMap[loc.x][loc.y-1] == -1){
            t.x = loc.x;
            t.y = loc.y-1;
            numMap[loc.x][loc.y-1] = numMap[loc.x][loc.y]+1;
            q.push(t);
        }
        if(loc.y+1 < n && maze[loc.x][loc.y+1] != '#' && numMap[loc.x][loc.y+1] == -1){
            t.x = loc.x;
            t.y = loc.y+1;
            numMap[loc.x][loc.y+1] = numMap[loc.x][loc.y]+1;
            q.push(t);
        }
    }
    return 999999;
}

int main(){
    char li[4] = {'F','H','S','V'};
    int part[4];
    int i,j;
    int minP;
    scanf("%d%d", &m, &n);
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf(" %c", &maze[i][j]);
        }
    }
    for(i = 0; i < 4; i++){
        part[i] = getShortestPart(li[i]);
    }
    for(i = 0; i < 4; i++){
        minP = 0;
        for(j = 1; j < 4; j++){
            if(part[j] < part[minP] || (part[j] == part[minP] && li[j] < li[minP])){
                minP = j;
            }
        }
        printf("%c ", li[minP]);
        part[minP] = 9999999;
    }

}
