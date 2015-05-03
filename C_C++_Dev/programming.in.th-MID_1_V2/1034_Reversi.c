#include "stdio.h"
int t[8][8];
int k,i,r,c;
char ch;
int ck(int x,int y,int cx,int cy,char c){
    if(x<0||y<0||x>=8||y>=8||t[x][y]==0){
        return 0;
    }else if(t[x][y]==c){
        return 1;
    }else{
        if(ck(x+cx,y+cy,cx,cy,c)){
            t[x][y] = c;
            return 1;
        }
    }
    return 0;
}
void printM(){
    int r,c;
    for(r = 0; r < 8; r++){
        for(c = 0; c < 8; c++){
            if(t[r][c]) putchar(t[r][c]);
            else putchar('.');
        }
        putchar('\n');
    }
}
int main(){
    scanf("%d",&k);
    t[3][3] = 'O';
    t[4][4] = 'O';
    t[3][4] = 'X';
    t[4][3] = 'X';
    for(i = 0; i < k; i++){
        if(i%2) ch = 'O';
        else ch = 'X';
        scanf(" %c%d", &c, &r);
        t[r-1][c-'a'] = ch;
        ck(r-2,c-'a'-1,-1,-1,ch);
        ck(r-2,c-'a',-1,0,ch);
        ck(r-2,c-'a'+1,-1,1,ch);
        ck(r-1,c-'a'-1,0,-1,ch);
        ck(r-1,c-'a'+1,0,1,ch);
        ck(r,c-'a'-1,1,-1,ch);
        ck(r,c-'a',1,0,ch);
        ck(r,c-'a'+1,1,1,ch);
    }
    printM();
}
