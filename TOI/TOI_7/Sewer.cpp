#include "stdio.h"
#include "queue"

typedef struct{
    int x,y;
}pos;

int a,b;
char sewer[101][101];

void findMixWaterFlow(){
    int i,j;
    char c;
    pos p,t;
    int step[100][100] = {};
    std::queue<pos> water;

    step[0][0] = 1;
    t.x = 0, t.y = 0;
    water.push(t);

    while(!water.empty()){
        p = water.front();
        water.pop();

        c = sewer[p.x][p.y];

        if(p.y+1 < b && (c == 'R' || c == 'B')){
            t.x = p.x;
            t.y = p.y+1;
            if(step[p.x][p.y+1]){
                printf("%d\n%d %d\n", step[p.x][p.y+1], p.x+1, p.y+2);
                break;
            }
            step[p.x][p.y+1] = step[p.x][p.y]+1;
            water.push(t);
        }
        if(p.x+1 < a && (c == 'D' || c == 'B')){
            t.x = p.x+1;
            t.y = p.y;
            if(step[p.x+1][p.y]){
                printf("%d\n%d %d\n", step[p.x+1][p.y], p.x+2, p.y+1);
                break;
            }
            step[p.x+1][p.y] = step[p.x][p.y]+1;
            water.push(t);
        }
    }
}

int main(){
    int i,j;
    scanf("%d%d", &a, &b);
    for(i = 0; i < a; i++){
        for(j = 0; j < b; j++){
            scanf(" %c", &sewer[i][j]);
        }
    }
    findMixWaterFlow();
}
