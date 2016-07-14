#include "stdio.h"

int r,c,i,j,co;
char wall[101][101];

void flood(int x, int y){
    wall[x][y] = '.';
    if(x>0&&wall[x-1][y]=='B') flood(x-1,y);
    if(x+1<r&&wall[x+1][y]=='B') flood(x+1,y);
    if(y>0&&wall[x][y-1]=='B') flood(x,y-1);
    if(y+1<c&&wall[x][y+1]=='B') flood(x,y+1);
}

int main(){
    scanf("%d%d",&r,&c);
    for(i = 0; i < r; i++){
        scanf("%s",&wall[i]);
    }
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            if(wall[i][j]=='B'){
                co++;
                flood(i,j);
            }
        }
    }
    printf("%d\n",co);
}
