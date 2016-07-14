#include "stdio.h"

int w,h,i,j;
char mp[100][100];

void fillLaser(int x, int y, int dx, int dy, char c){
    if(x<0||y<0||x>=h||y>=w) return;
    if(mp[x][y]=='.') mp[x][y] = c;
    else if(mp[x][y]!=c&&(mp[x][y]=='|'||mp[x][y]=='-'))mp[x][y] = '+';
    else return;
    fillLaser(x+dx,y+dy,dx,dy,c);
}

int main(){
    scanf("%d%d",&w,&h);
    for(i = 0; i < h; i++){
        scanf(" %s",mp[i]);
    }
    for(i = 0; i < h; i++){
        for(j = 0; j < w; j++){
            switch(mp[i][j]){
            case 'B': mp[i][j] = '*'; break;
            case '^': fillLaser(i-1,j,-1,0,'|'); break;
            case 'V': fillLaser(i+1,j,1,0,'|'); break;
            case '>': fillLaser(i,j+1,0,1,'-'); break;
            case '<': fillLaser(i,j-1,0,-1,'-'); break;
            }
        }
    }
    for(i = 0; i < h; i++){
        printf("%s\n",mp[i]);
    }
}
